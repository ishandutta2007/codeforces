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
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):"; dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif


void run_case() {
    int A, B, P;
    string S;
    cin >> A >> B >> P >> S;
    int N = S.size();
    vector<long long> cost(N, 0);

    for (int i = N - 2; i >= 0; i--)
        if (i == N - 2 || S[i] != S[i + 1])
            cost[i] = (S[i] == 'A' ? A : B) + cost[i + 1];
        else
            cost[i] = cost[i + 1];

    dbg(cost);
    int answer = 0;

    while (cost[answer] > P)
        answer++;

    cout << answer + 1 << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tests;
    cin >> tests;

    while (tests-- > 0)
        run_case();
}