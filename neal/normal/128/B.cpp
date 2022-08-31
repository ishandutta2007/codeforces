// Solution to https://codeforces.com/contest/128/problem/B
// Also works in O(N log N) on arbitrarily large K and arbitrarily large alphabets.
#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

template<typename T, bool maximum_mode = false>
struct RMQ {
    int n = 0, levels = 0;
    vector<vector<T>> range_min;

    RMQ(const vector<T> &values = {}) {
        if (!values.empty())
            build(values);
    }

    static int largest_bit(int x) {
        return 31 - __builtin_clz(x);
    }

    static T better(T a, T b) {
        return maximum_mode ? max(a, b) : min(a, b);
    }

    void build(const vector<T> &values) {
        n = values.size();
        levels = largest_bit(n) + 1;
        range_min.resize(levels);

        for (int k = 0; k < levels; k++)
            range_min[k].resize(n - (1 << k) + 1);

        if (n > 0)
            range_min[0] = values;

        for (int k = 1; k < levels; k++)
            for (int i = 0; i <= n - (1 << k); i++)
                range_min[k][i] = better(range_min[k - 1][i], range_min[k - 1][i + (1 << (k - 1))]);
    }

    T query_value(int a, int b) const {
        assert(0 <= a && a < b && b <= n);
        int level = largest_bit(b - a);
        return better(range_min[level][a], range_min[level][b - (1 << level)]);
    }
};

template<typename T_string>
struct suffix_array {
    int n = 0;
    T_string str;
    vector<int> suffix;
    vector<int> rank;
    vector<int> lcp;
    RMQ<int> rmq;

    suffix_array() {}

    suffix_array(const T_string &_str, bool build_rmq = true) {
        build(_str, build_rmq);
    }

    void build(const T_string &_str, bool build_rmq = true) {
        str = _str;
        n = str.size();
        suffix.resize(n);

        for (int i = 0; i < n; i++)
            suffix[i] = i;

        bool large_alphabet = false;

        for (int i = 0; i < n; i++)
            if (str[i] < 0 || str[i] >= 128)
                large_alphabet = true;

        // Sort each suffix by the first character.
        if (large_alphabet) {
            sort(suffix.begin(), suffix.end(), [&](int a, int b) {
                return str[a] < str[b];
            });
        } else {
            vector<int> freq(128, 0);

            for (int i = 0; i < n; i++)
                freq[str[i]]++;

            for (int c = 1; c < 128; c++)
                freq[c] += freq[c - 1];

            for (int i = 0; i < n; i++)
                suffix[--freq[str[i]]] = i;
        }

        // Compute the rank of each suffix. Tied suffixes share the same rank.
        rank.resize(n);
        rank[suffix[0]] = 0;

        for (int i = 1; i < n; i++)
            rank[suffix[i]] = str[suffix[i]] == str[suffix[i - 1]] ? rank[suffix[i - 1]] : i;

        vector<int> next_index(n);
        vector<int> values(n);
        bool done = false;

        for (int len = 1; len < n && !done; len *= 2) {
            // next_index[i] = the next index to use for a suffix of rank i. We insert them in order of the rank of the
            // suffix that comes len characters after the current suffix.
            for (int i = 0; i < n; i++)
                next_index[i] = i;

            // Compute the suffix array for 2 * len. Suffixes of length <= len are prioritized first.
            for (int i = n - len; i < n; i++)
                values[next_index[rank[i]]++] = i;

            for (int i = 0; i < n; i++) {
                int prev = suffix[i] - len;

                if (prev >= 0)
                    values[next_index[rank[prev]]++] = prev;
            }

            swap(suffix, values);

            // Compute the rank array for 2 * len.
            values[suffix[0]] = 0;
            done = true;

            for (int i = 1; i < n; i++) {
                int s = suffix[i], prev = suffix[i - 1];

                if (s + len < n && prev + len < n && rank[s] == rank[prev] && rank[s + len] == rank[prev + len]) {
                    values[s] = values[prev];
                    done = false;
                } else {
                    values[s] = i;
                }
            }

            swap(rank, values);
        }

        compute_lcp();

        if (build_rmq)
            rmq.build(lcp);
    }

    void compute_lcp() {
        lcp.assign(n, 0);
        int match = 0;

        for (int i = 0; i < n; i++) {
            if (rank[i] == 0)
                continue;

            int a = suffix[rank[i]] + match;
            int b = suffix[rank[i] - 1] + match;

            while (a < n && b < n && str[a++] == str[b++])
                match++;

            // lcp[r] = the longest common prefix length of the suffixes starting at suffix[r] and at suffix[r - 1].
            lcp[rank[i]] = match;
            match = max(match - 1, 0);
        }
    }

    int get_lcp_from_ranks(int a, int b) const {
        if (a == b)
            return n - suffix[a];

        if (a > b)
            swap(a, b);

        return rmq.query_value(a + 1, b + 1);
    }

    int get_lcp(int a, int b) const {
        if (a >= n || b >= n)
            return 0;

        if (a == b)
            return n - a;

        return get_lcp_from_ranks(rank[a], rank[b]);
    }

    // Compares the substrings starting at `a` and `b` up to `length`.
    int compare(int a, int b, int length = -1) const {
        if (length < 0)
            length = n;

        if (a == b)
            return 0;

        int common = get_lcp(a, b);

        if (common >= length)
            return 0;

        if (a + common >= n || b + common >= n)
            return a + common >= n ? -1 : 1;

        return str[a + common] < str[b + common] ? -1 : (str[a + common] == str[b + common] ? 0 : 1);
    }
};


string str;
suffix_array<string> SA;
vector<long long> prefix_sum;

// Given the range start to end, finds the first index such that str[suffix[index] + i] >= character, capped at end.
int search_index(int start, int end, int i, int character) {
    int low = start, high = end;

    while (low < high) {
        int mid = (low + high) / 2;

        if (str[SA.suffix[mid] + i] >= character)
            high = mid;
        else
            low = mid + 1;
    }

    return low;
}

// Given the current character index i and the suffix array range start to end, computes in constant time the number of
// substrings that start at suffix[s] for any s such that start <= s < end, with length strictly greater than i.
long long compute_substring_count(int i, int start, int end) {
    return prefix_sum[end] - prefix_sum[start] - (long long) i * (end - start);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long K;
    cin >> str >> K;
    int N = str.size();

    if (K > (long long) N * (N + 1) / 2) {
        cout << "No such line." << '\n';
        return 0;
    }

    assert(1 <= K && K <= (long long) N * (N + 1) / 2);
    SA.build(str);
    prefix_sum.assign(N + 1, 0);

    for (int i = 0; i < N; i++)
        prefix_sum[i + 1] = prefix_sum[i] + N - SA.suffix[i];

    // start and end is the range of suffix array indices we are still considering.
    int start = 0, end = N;
    string substring = "";

    for (int i = 0; i < N; i++) {
        // Only the first suffix of the section can be too short, since being too short makes it less than the others.
        if (SA.suffix[start] + i == N)
            start++;

        // Find the next character of our substring, which is the smallest character c we can add such that the number
        // of substrings whose first i + 1 characters are <= (substring + c) is at least K.
        int low = start, high = end;

        while (low < high) {
            int mid = (low + high) / 2;
            long long additional = compute_substring_count(i, start, mid);

            if (additional >= K)
                high = mid;
            else
                low = mid + 1;
        }

        assert(low > start);
        int c = str[SA.suffix[low - 1] + i];
        substring += c;

        // Update K to exclude all substrings <= substring. Also update our start and end range to become c's range.
        int c_start = search_index(start, low, i, c);
        K -= compute_substring_count(i, start, c_start);
        start = c_start;
        end = search_index(low, end, i, c + 1);
        K -= end - start;

        if (K <= 0)
            break;
    }

    cout << substring << '\n';
}