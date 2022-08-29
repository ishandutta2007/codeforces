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
    int N, M;
    cin >> N >> M;
    vector<int> A(N);

    for (int &a : A)
        cin >> a;

    vector<bool> connected(N, false);

    for (int i = 0; i < M; i++) {
        int p;
        cin >> p;
        p--;
        connected[p] = true;
    }

    for (int i = 0; i < N - 1; i++)
        if (!connected[i]) {
            int left = *max_element(A.begin(), A.begin() + i + 1);
            int right = *min_element(A.begin() + i + 1, A.end());

            if (left > right) {
                cout << "NO" << '\n';
                return;
            }
        }

    cout << "YES" << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tests;
    cin >> tests;

    while (tests-- > 0)
        run_case();
}