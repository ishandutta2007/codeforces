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


const int LOG = 60;

int N, K;
vector<long long> A;
vector<int> freq;

void run_case() {
    cin >> N >> K;
    A.resize(N);

    for (auto &a : A)
        cin >> a;

    freq.assign(LOG, 0);

    for (auto &a : A) {
        int position = 0;

        while (a > 0) {
            freq[position] += a % K;
            a /= K;
            position++;
        }
    }

    for (int p = 0; p < LOG; p++)
        if (freq[p] > 1) {
            cout << "NO" << '\n';
            return;
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