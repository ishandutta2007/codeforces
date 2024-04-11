#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#ifdef NEAL_DEBUG
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif


int N, R, C;
vector<int> goes;
vector<bool> black;
vector<vector<int>> adj;

int encode(int row, int col) {
    return row * C + col;
}

vector<bool> done;
vector<bool> seen_depth;

void set_true(int d) {
    if (d + 1 > (int) seen_depth.size())
        seen_depth.resize(d + 1, false);

    seen_depth[d] = true;
}

void dfs(int node, int parent, int depth) {
    if (black[node]) {
        dbg(node, depth);
        set_true(depth);
    }

    done[node] = true;

    for (int neighbor : adj[node])
        if (neighbor != parent)
            dfs(neighbor, node, depth + 1);
}

void run_case() {
    cin >> R >> C;
    N = R * C;
    goes.assign(N, -1);
    black.assign(N, false);

    for (int r = 0; r < R; r++) {
        string str;
        cin >> str;

        for (int c = 0; c < C; c++)
            black[encode(r, c)] = str[c] == '0';
    }

    for (int r = 0; r < R; r++) {
        string str;
        cin >> str;

        for (int c = 0; c < C; c++) {
            int me = encode(r, c);

            if (str[c] == 'U')
                goes[me] = encode(r - 1, c);
            else if (str[c] == 'D')
                goes[me] = encode(r + 1, c);
            else if (str[c] == 'L')
                goes[me] = encode(r, c - 1);
            else if (str[c] == 'R')
                goes[me] = encode(r, c + 1);
            else
                assert(false);
        }
    }

    dbg(goes);

    adj.assign(N, {});

    for (int i = 0; i < N; i++)
        adj[goes[i]].push_back(i);

    done.assign(N, false);
    int ans = 0, ans_black = 0;

    for (int start = 0; start < N; start++)
        if (!done[start]) {
            int x = start;

            do {
                done[x] = true;
                x = goes[x];
            } while (!done[x]);

            vector<int> cycle;
            int y = x;

            do {
                cycle.push_back(y);
                y = goes[y];
            } while (y != x);

            dbg(cycle);

            C = cycle.size();
            vector<bool> found(C, false);

            for (int i = 0; i < C; i++) {
                seen_depth.clear();
                dfs(cycle[i], cycle[(i + C - 1) % C], 0);

                for (int d = 0; d < (int) seen_depth.size(); d++)
                    if (seen_depth[d]) {
                        dbg(d);
                        found[(i + C - d % C) % C] = true;
                    }

                dbg(cycle[i]);
                dbg(found);
            }

            ans += C;

            for (int i = 0; i < C; i++)
                ans_black += found[i];
        }

    cout << ans << ' ' << ans_black << '\n';
}

int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    int tests;
    cin >> tests;

    while (tests-- > 0)
        run_case();
}