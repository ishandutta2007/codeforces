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


long long U, V;

void answer(vector<long long> v) {
    int n = v.size();
    cout << n << '\n';

    for (int i = 0; i < n; i++)
        cout << v[i] << (i < n - 1 ? ' ' : '\n');

    exit(0);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> U >> V;

    if (V < U || (U % 2 != V % 2)) {
        cout << -1 << '\n';
        return 0;
    }

    if (U == 0 && V == 0)
        answer({});

    if (U == V)
        answer({U});

    long long D = (V - U) / 2;

    if ((U & D) == 0)
        answer({U ^ D, D});

    answer({U, D, D});
}