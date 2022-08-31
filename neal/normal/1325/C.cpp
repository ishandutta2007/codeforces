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


int N;
vector<pair<int, int>> edges;
vector<int> degree;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    edges.resize(N - 1);
    degree.assign(N, 0);

    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        edges[i] = {u, v};
        degree[u]++; degree[v]++;
    }

    vector<int> answer(N - 1, -1);
    int label = 0;

    for (int i = 0; i < N - 1; i++) {
        pair<int, int> &edge = edges[i];

        if (degree[edge.first] == 1 || degree[edge.second] == 1)
            answer[i] = label++;
    }

    for (int i = 0; i < N - 1; i++)
        if (answer[i] < 0)
            answer[i] = label++;

    for (int i = 0; i < N - 1; i++)
        cout << answer[i] << '\n';
}