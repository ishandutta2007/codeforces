#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi = v.begin(); vi != v.end(); ++vi) { if (vi != v.begin()) os << ", "; os << *vi; } os << "}"; return os; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#ifdef NEAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif


const long long LL_INF = (long long) 2e18 + 5;

int N, K;
vector<int> A;
vector<long long> prefix_sum, suffix_sum;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> K;
    A.resize(N);

    for (int &a : A)
        cin >> a;

    sort(A.begin(), A.end());
    prefix_sum.assign(N + 1, 0);
    suffix_sum.assign(N + 1, 0);

    for (int i = 0; i < N; i++)
        prefix_sum[i + 1] = prefix_sum[i] + A[i];

    for (int i = N - 1; i >= 0; i--)
        suffix_sum[i] = suffix_sum[i + 1] + A[i];

    long long answer = LL_INF;

    for (int i = 0, j = 0; i < N; i = j) {
        long long value = A[i];

        while (j < N && A[j] == value)
            j++;

        if (j - i >= K) {
            answer = 0;
            break;
        }

        int need = K - (j - i);
        int before = i;
        int after = N - j;
        long long before_cost = before * value - prefix_sum[i];
        long long after_cost = suffix_sum[j] - after * value;

        if (before >= need)
            answer = min(answer, before_cost - (before - need));

        if (after >= need)
            answer = min(answer, after_cost - (after - need));

        answer = min(answer, before_cost + after_cost - (before + after - need));
    }

    cout << answer << '\n';
}