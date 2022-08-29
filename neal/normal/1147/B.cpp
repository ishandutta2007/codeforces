#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi=v.begin(); vi!=v.end(); ++vi) { if (vi != v.begin()) os << ", "; os << *vi; } os << "}"; return os; }

struct segment {
    int start, end, length;
};

int N, M;
vector<segment> segments;
vector<vector<int>> starts_by_length;

// Also known as "extended KMP"
template<typename T>
vector<int> z_algorithm(const T &pattern) {
    // Z[i] = for the suffix [i, n) of pattern, the longest prefix that is also a prefix of pattern.
    int n = pattern.size();
    vector<int> Z(n, 0);
    Z[0] = n;
    int loc = 1;

    for (int i = 1; i < n; i++) {
        if (i < loc + Z[loc])
            Z[i] = min(Z[i - loc], loc + Z[loc] - i);

        while (i + Z[i] < n && pattern[Z[i]] == pattern[i + Z[i]])
            Z[i]++;

        if (i + Z[i] > loc + Z[loc])
            loc = i;
    }

    return Z;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    segments.resize(M);
    starts_by_length.assign(N + 1, {});

    for (segment &seg : segments) {
        cin >> seg.start >> seg.end;

        if (seg.start > seg.end)
            swap(seg.start, seg.end);

        seg.length = seg.end - seg.start;

        if (seg.start + N - seg.end < seg.end - seg.start) {
            seg.length = seg.start + N - seg.end;
            swap(seg.start, seg.end);
        }

        starts_by_length[seg.length].push_back(seg.start);
    }

    vector<int> valid_count(N + 1, 0);
    int needed = 0;

    for (int length = 1; length < N; length++) {
        vector<int> &starts = starts_by_length[length];
        sort(starts.begin(), starts.end());
        int n = starts.size();

        if (n == 0)
            continue;

        // cerr << starts << endl;

        needed++;

        for (int i = 0; i < n; i++)
            starts.push_back(starts[i] + N);

        vector<int> diffs(2 * n - 1);

        for (int i = 0; i < 2 * n - 1; i++)
            diffs[i] = starts[i + 1] - starts[i];

        // cerr << diffs << endl;

        vector<int> Z = z_algorithm(diffs);

        // cerr << Z << endl;
        bool includes_half = false;

        for (int i = 0; i < n; i++)
            if (Z[i] >= n - 1) {
                valid_count[starts[i] - starts[0]]++;

                if (2 * (starts[i] - starts[0]) == N)
                    includes_half = true;
            }

        if (2 * length == N && !includes_half)
            valid_count[N / 2]++;
    }

    bool any = false;

    for (int i = 1; i < N; i++)
        if (valid_count[i] >= needed) {
            // cerr << i << endl;
            any = true;
        }

    cout << (any ? "Yes" : "No") << '\n';
}