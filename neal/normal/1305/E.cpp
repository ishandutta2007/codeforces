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


const int A_MAX = 1e9;
const int JUMP = 20000;

int get_max(int n) {
    return ((n - 1) / 2) * (n / 2);
}

int N, M;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;

    if (M > get_max(N)) {
        cout << -1 << '\n';
        return 0;
    }

    int n = 1;

    while (get_max(n) < M)
        n++;

    int extra = get_max(n) - M;
    vector<int> answer;

    for (int i = 1; i <= n; i++)
        answer.push_back(i);

    answer.back() += 2 * extra;
    int remaining = N - n;

    for (int i = remaining - 1; i >= 0; i--)
        answer.push_back(A_MAX - i * JUMP);

    for (int i = 0; i < N; i++)
        cout << answer[i] << (i < N - 1 ? ' ' : '\n');
}