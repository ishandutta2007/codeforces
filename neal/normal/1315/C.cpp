#include <algorithm>
#include <cassert>
#include <iostream>
#include <set>
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


int N;
vector<int> B;

void run_case() {
    cin >> N;
    B.resize(N);
    vector<bool> seen(2 * N + 1, false);

    for (int &b : B) {
        cin >> b;
        seen[b] = true;
    }

    set<int> other;

    for (int x = 1; x <= 2 * N; x++)
        if (!seen[x])
            other.insert(x);

    vector<int> A;

    for (int i = 0; i < N; i++) {
        int current = B[i];
        auto it = other.upper_bound(current);

        if (it == other.end()) {
            cout << -1 << '\n';
            return;
        }

        A.push_back(current);
        A.push_back(*it);
        other.erase(it);
    }

    for (int i = 0; i < 2 * N; i++)
        cout << A[i] << (i < 2 * N - 1 ? ' ' : '\n');

    cout << flush;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tests;
    cin >> tests;

    while (tests-- > 0)
        run_case();
}