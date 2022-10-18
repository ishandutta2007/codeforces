#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <math.h>
#include <cstdlib>
#include <memory.h>
#include <queue>
#include <assert.h>

#define pb push_back
#define LL long long
#define uLL unsigned long long
#define mp make_pair
#define pii pair <int,int>
#define vi vector <int>
#define vii vector <pii>
#define f first
#define s second
#define foran(i,a,b) for (int i=a;i<(int)b;i++)
#define forn(i,n) for (int i=0;i<(int)n;i++)
#define ford(i,n) for (int i=(int)n-1;i>=0;i--)
#define sqr(x) ((x) * (x))
#define sz(A) ((int)(A).size())
#define y1 asxfdsfsdsjhfgidf
#define y0 dsfgdfggdfjdhriwurehiw

const double EPS = 1e-9;
const double PI = acos(-1.0);

using namespace std;

vi g[100500];
int n, m;
int h, t;
int deg[100500];
vii e;
bool used[100500];

bool is(int v, int u) {
    int id = lower_bound(g[v].begin(), g[v].end(), u) - g[v].begin();
    return id != sz(g[v]) && g[v][id] == u;
}

int main() {
 // freopen("in.txt", "r", stdin);
  cin >> n >> m >> h >> t;
  memset(deg, 0, sizeof deg);
  forn(i, m) {
    int a, b;
    scanf("%d%d", &a, &b);
    a--; b--;
    e.pb(mp(a, b));
    e.pb(mp(b, a));
    deg[a]++;
    deg[b]++;
    g[a].pb(b);
    g[b].pb(a);
  }

  forn(i, n)
    sort(g[i].begin(), g[i].end());

  forn(i, sz(e)) {
        int a = e[i].f;
        int b = e[i].s;
        int dega = deg[a] - 1;
        int degb = deg[b] - 1;
        if  (dega < h || degb < t) continue;
        int deg = 0;

        forn(k, sz(g[b])) {
            int v = g[b][k];
            if  (is(v, a)) deg++;
        }

        if  (h + t <= dega + degb - deg) {
            memset(used, 0, sizeof used);
            puts("YES");
            printf("%d %d\n", a + 1, b + 1);

            forn(k, sz(g[a])) {
                if  (h == 0) break;
                int v = g[a][k];
                if  (v == b) continue;
                if  (is(v, b)) continue;
                printf("%d ", v + 1); h--;
                used[v] = 1;
            }

            forn(k, sz(g[a])) {
                if  (h == 0) break;
                int v = g[a][k];
                if  (v == b) continue;
                if  (used[v]) continue;
                printf("%d ", v + 1); h--;
                used[v] = 1;
            }
            puts("");

            forn(k, sz(g[b])) {
                int v = g[b][k];
                if  (v == a) continue;
                if  (used[v]) continue;
                printf("%d ", v + 1); t--;
                if  (t == 0) break;
            }
            return 0;
        }
    }

  puts("NO");
  return 0;
}