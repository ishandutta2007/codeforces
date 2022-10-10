#ifndef BZ
#pragma GCC optimize "-O3"
#endif
#include <bits/stdc++.h>

#define FASTIO
#define ALL(v) (v).begin(), (v).end()
#define rep(i, l, r) for (int i = (l); i < (r); ++i)

#ifdef FASTIO
#define scanf abacaba
#define printf abacaba
#endif

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

using namespace std;

const int MX = 307;

bool can[MX][MX];
int n;
int a[MX];
int cl[MX];
vector<int> al[MX];
void dfs(int v, int c) {
    cl[v] = c;
    al[c].push_back(a[v]);
    for (int i = 1; i <= n; i++) {
        if (can[v][i] && cl[i] == 0) {
            dfs(i, c);
        }
    }
}

int ptr[MX];
int main() {
#ifdef FASTIO
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        for (int j = 1; j <= n; j++) {
            if (s[j - 1] == '1') {
                can[i][j] = true;
            }
        }
    }

    int nid = 1;
    for (int i = 1; i <= n; i++) {
        if (cl[i] == 0) {
            dfs(i, nid++);
        }
    }

    for (int i=  1; i < nid; i++) {
        sort(al[i].begin(), al[i].end());
    }
    for (int i = 1; i <= n; i++) {
        cout << al[cl[i]][ptr[cl[i]]++] << " ";
    }
    return 0;
}