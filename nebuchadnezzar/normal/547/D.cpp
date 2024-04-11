#include "bits/stdc++.h"
#define puba push_back
#define mapa make_pair
#define ff first
#define ss second
#define bend(_x) (_x).begin(), (_x).end()
#define szof(_x) ((int) (_x).size())
#define forn(i, n) for (int i = 0; i < n; ++i)

using namespace std;
typedef long long ll;
typedef double dbl;
typedef pair <int, int> pii;
const int MAXN = 2e5 + 5;
const int MAXC = 2e5 + 5;

int n;
set <pii > graph[MAXC * 2];
set <int> odd;
set <int> rest;
int ans[MAXN];
int now[MAXC * 2];

int main() {    
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);

    cin >> n;

    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        graph[x].insert(mapa(y + MAXC, i));
        graph[y + MAXC].insert(mapa(x, i));
    }

    for (int i = 0; i < MAXC * 2; ++i) {
        if (szof(graph[i]) & 1) {
            odd.insert(i);
        }
        if (szof(graph[i])) {
            rest.insert(i);
        }
    }

    while (szof(rest)) {
        int pos = -1;
        bool flag = false;
        if (szof(odd)) {
            pos = *odd.begin();
            odd.erase(pos);
            flag = true;
        } else {
            pos = *rest.begin();           
        }
        int col = 0;
        while (szof(graph[pos])) {
            pii p = *graph[pos].begin();
            graph[pos].erase(p);
            if (!szof(graph[pos])) {
                rest.erase(pos);
            }
            graph[p.ff].erase(mapa(pos, p.ss));
            if (!szof(graph[p.ff])) {
                rest.erase(p.ff);
            }
            ans[p.ss] = col;
            col = 1 - col;
            pos = p.ff;
        }
        if (flag) {
            odd.erase(pos);
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << "br"[ans[i]];
    }
    cout << endl;

    return 0;
}