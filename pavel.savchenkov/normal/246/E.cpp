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
#define all(A) (A).begin(), (A).end()
#define sz(A) ((int)(A).size())
#define y1 fucking_y1

const double EPS = 1e-9;
const double PI = acos(-1.0);
const int MAXN = (int)1e5 + 10;
const LL P = 29;
const LL MOD = (LL)1e9 + 7;;

using namespace std;

struct query {
  int l, r, id;
  query(int l = 0, int r = 0, int id = 0): l(l), r(r), id(id) {}
  friend bool operator <(const query & a, const query & b) {
    return a.l < b.l;
  }
};

int n, m;
int de[MAXN];
int tin[MAXN];
int tout[MAXN];
vi names[MAXN];
vi times[MAXN];

vector <query> queries[MAXN];
int next[MAXN];
int last[MAXN];
int name[MAXN];

vi g[MAXN];
vi roots;
int ans[MAXN];
int timer = 0;
map <string, int> all_names;
int cnt_names = 0;
vi fen[MAXN];

void inc(int id, int j) {
    for (int i = j; i < sz(fen[id]); i = (i | (i + 1)))
        fen[id][i]++;
}

int sum(int id, int r) {
    int res = 0;
    for (int i = r; i >= 0; i = (i & (i + 1)) - 1)
        res += fen[id][i];
    return res;
}

int sum(int id, int l, int r) {
    return sum(id, r) - sum(id, l - 1);
}

void dfs(int v, int p = -1) {
    if  (p != -1) de[v] = de[p] + 1;

    tin[v] = timer++;
    times[de[v]].pb(tin[v]);

    for (int i = 0; i < sz(g[v]); i++) {
        int to = g[v][i];
        dfs(to, v);
    }
    
    tout[v] = timer++;
    names[de[v]].pb(name[v]);
}

void calc(int de) {
    int sz_names = sz(names[de]);
    memset(next, -1, sizeof(int) * sz_names);
    memset(last, -1, sizeof(int) * sz_names);
    sort(queries[de].begin(), queries[de].end());
    fen[de].assign(sz_names, 0);

    vi tranc;
    for (int i = 0; i < sz_names; i++)
        tranc.pb(names[de][i]);
    sort(all(tranc));
    tranc.resize(unique(all(tranc)) - tranc.begin());
    for (int i = 0; i < sz_names; i++)
        names[de][i] = lower_bound(all(tranc), names[de][i]) - tranc.begin();  

    for (int i = sz_names - 1; i >= 0; i--) {
        next[i] = last[names[de][i]];
        last[names[de][i]] = i;
    }
        
        for (int i = 0; i < sz_names; i++)
            if  (last[names[de][i]] == i)
                inc(de, i);

    for (int i = 0, j = 0; i < sz(queries[de]); i++) {
        int L = lower_bound(times[de].begin(), times[de].end(), queries[de][i].l) - times[de].begin();
        int R = lower_bound(times[de].begin(), times[de].end(), queries[de][i].r) - times[de].begin(); R--;
        if  (L > R || L >= sz_names) continue;

        while (j < L) {
            if  (next[j] != -1) inc(de, next[j]);
            j++;
        }

        ans[ queries[de][i].id ] = sum(de, L, R);

    }   
}

int main() {
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
  scanf("%d\n", &n);
  for (int i = 0; i < n; i++) {
    char c; string s = "";
    while (scanf("%c", &c) >= 1 && c != ' ') s += c;

    int par;
    scanf("%d\n", &par);
    if  (par > 0)
        g[par - 1].pb(i);
    else
        roots.pb(i);

    if  (all_names[s] == 0) {
        name[i] = cnt_names++;
        all_names[s] = cnt_names - 1;
    }
    else
        name[i] = all_names[s];
  }

  
  int depth = 0;
  for (int i = 0; i < sz(roots); i++)
     de[roots[i]] = depth++, dfs(roots[i]);

  
  scanf("%d", &m);
  for (int i = 0; i < m; i++) {
    int v, k;
    scanf("%d%d", &v, &k);
    k += de[v - 1];
    if  (k >= n) continue;
    queries[k].pb(query(tin[v - 1], tout[v - 1], i));
  }

  memset(ans, 0, sizeof ans);   
  for (int i = 0; i <= n; i++)
    calc(i);
  
  for (int i = 0; i < m; i++)
    printf("%d\n", ans[i]);
  return 0;
}