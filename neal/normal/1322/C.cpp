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


int N, M;
vector<long long> C;
vector<pair<vector<int>, int>> signature;

void run_case() {
    cin >> N >> M;
    C.resize(N);

    for (auto &c : C)
        cin >> c;

    signature.assign(N, {{}, 0});

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        signature[v].first.push_back(u);
    }

    for (int i = 0; i < N; i++) {
        sort(signature[i].first.begin(), signature[i].first.end());

        if (signature[i].first.empty())
            C[i] = 0;

        signature[i].second = i;
    }

    sort(signature.begin(), signature.end());

    for (int i = 0, j = 0; i < N; i = j) {
        while (j < N && signature[i].first == signature[j].first) {
            if (j > i) {
                C[signature[i].second] += C[signature[j].second];
                C[signature[j].second] = 0;
            }

            j++;
        }
    }

    dbg(C);
    long long G = 0;

    for (int i = 0; i < N; i++)
        G = __gcd(G, C[i]);

    cout << G << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tests;
    cin >> tests;

    while (tests-- > 0)
        run_case();
}