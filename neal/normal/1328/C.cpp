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


void run_case() {
    int N;
    string X;
    cin >> N >> X;
    string A(N, '0'), B(N, '0');
    bool different = false;

    for (int i = 0; i < N; i++)
        if (X[i] == '0') {
            A[i] = B[i] = '0';
        } else if (X[i] == '1') {
            if (!different) {
                A[i] = '1';
                B[i] = '0';
                different = true;
            } else {
                A[i] = '0';
                B[i] = '1';
            }
        } else if (X[i] == '2') {
            if (!different) {
                A[i] = B[i] = '1';
            } else {
                A[i] = '0';
                B[i] = '2';
            }
        }

    cout << A << '\n';
    cout << B << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tests;
    cin >> tests;

    while (tests-- > 0)
        run_case();
}