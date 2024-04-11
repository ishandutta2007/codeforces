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
    cin >> N;
    vector<vector<int>> daughter_lists(N);

    for (int i = 0; i < N; i++) {
        int k;
        cin >> k;

        while (k-- > 0) {
            int p;
            cin >> p;
            p--;
            daughter_lists[i].push_back(p);
        }
    }

    vector<int> prince(N, -1);
    vector<bool> taken(N, false);

    for (int i = 0; i < N; i++)
        for (int p : daughter_lists[i])
            if (!taken[p]) {
                prince[i] = p;
                taken[p] = true;
                break;
            }

    for (int i = N - 1; i >= 0; i--)
        if (prince[i] < 0) {
            for (int p = 0; p < N; p++)
                if (!taken[p]) {
                    cout << "IMPROVE" << '\n';
                    cout << i + 1 << ' ' << p + 1 << '\n';
                    return;
                }
        }

    cout << "OPTIMAL" << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tests;
    cin >> tests;

    while (tests-- > 0)
        run_case();
}