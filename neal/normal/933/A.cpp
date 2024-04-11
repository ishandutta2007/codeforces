#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#ifdef NEAL_DEBUG
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

// Finds the length of the longest subsequence of values such that compare is true for all consecutive pairs.
template<typename T, typename T_compare>
int longest_increasing_subsequence(vector<T> values, T_compare &&compare) {
    vector<T> best_ending;

    for (T value : values) {
        auto it = lower_bound(best_ending.begin(), best_ending.end(), value, compare);

        if (it == best_ending.end())
            best_ending.push_back(value);
        else
            *it = value;
    }

    return best_ending.size();
}


int main() {
    int N;
    cin >> N;
    vector<int> A(N);

    for (int &a : A)
        cin >> a;

    int answer = longest_increasing_subsequence(A, less_equal<int>());

    vector<int> one_prefix(N + 1, 0);
    vector<int> two_suffix(N + 1, 0);

    for (int i = 0; i < N; i++)
        one_prefix[i + 1] = one_prefix[i] + (A[i] == 1);

    for (int i = N - 1; i >= 0; i--)
        two_suffix[i] = two_suffix[i + 1] + (A[i] == 2);

    for (int end = 0; end <= N; end++) {
        vector<int> best_ending;

        for (int start = end - 1; start >= 0; start--) {
            auto it = upper_bound(best_ending.begin(), best_ending.end(), A[start]);

            if (it == best_ending.end())
                best_ending.push_back(A[start]);
            else
                *it = A[start];

            answer = max(answer, one_prefix[start] + (int) best_ending.size() + two_suffix[end]);
            dbg(start, end, one_prefix[start] + (int) best_ending.size() + two_suffix[end]);
            dbg(best_ending);
        }
    }

    cout << answer << '\n';
}