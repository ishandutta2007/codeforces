#include <bits/stdc++.h>
#define MAXN 200
#define MAXC 100000

using namespace std;

bool ciur[2 * MAXC + 1];

struct Node {
    int p, c, l;
}v[MAXN + 1];

std::vector <int> g[MAXN + 1];
int cap[MAXN + 1][MAXN + 1];
int flux[MAXN + 1][MAXN + 1];

int n;
int sum;

inline void build(int lvl) {
    int i, j;
    memset(flux, 0, sizeof(flux));
    memset(cap, 0, sizeof(cap));
    for(i = 0; i <= n + 1; i++)
        g[i].clear();
    int mx = -1;
    sum = 0;
    for(i = 1; i <= n; i++)
       if(v[i].c % 2 == 1 && v[i].l <= lvl) {
           if(v[i].c == 1)
                mx = max(mx, v[i].p);
           else {
                g[0].push_back(i);
                g[i].push_back(0);
                cap[0][i] = v[i].p;
                sum += v[i].p;
           }
       }
    for(i = 1; i <= n; i++)
       if(v[i].c == 1 && v[i].p == mx && v[i].l <= lvl) {
          mx = -1;
          g[0].push_back(i);
          g[i].push_back(0);
          cap[0][i] = v[i].p;
          sum += v[i].p;
       }
    for(i = 1; i <= n; i++)
       if(v[i].c % 2 == 1 && v[i].l <= lvl)
         for(j = 1; j <= n; j++)
          if(v[j].c % 2 == 0 && ciur[v[i].c + v[j].c] == 0 && v[j].l <= lvl) {
              g[i].push_back(j);
              g[j].push_back(i);
              cap[i][j] = (1 << 30);
          }
    for(i = 1; i <= n; i++)
       if(v[i].c % 2 == 0 && v[i].l <= lvl) {
          g[i].push_back(n + 1);
          g[n + 1].push_back(i);
          cap[i][n + 1] = v[i].p;
          sum += v[i].p;
       }
}

bool viz[MAXN + 1];
int q[MAXN + 1];
int from[MAXN + 1];

inline bool bfs() {
    int b = 0, e = 1;
    memset(viz, 0, sizeof(viz));
    q[0] = 0;
    viz[0] = 1;
    do {
        for(auto it : g[q[b]])
          if(viz[it] == 0 && flux[q[b]][it] < cap[q[b]][it]) {
              q[e++] = it;
              from[it] = q[b];
              viz[it] = 1;
          }
        b++;
    }while(b < e);
    return viz[n + 1];
}

inline int check(int lvl) {
    int flx = 0;
    build(lvl);
    while(bfs()) {
        int nod = n + 1;
        int mn = (1 << 30);
        while(nod > 0) {
            mn = min(mn, cap[from[nod]][nod] - flux[from[nod]][nod]);
            nod = from[nod];
        }
        nod = n + 1;
        while(nod > 0) {
            flux[from[nod]][nod] += mn;
            flux[nod][from[nod]] -= mn;
            nod = from[nod];
        }
        flx += mn;
    }
    return sum - flx;
}

int main() {
    //fstream cin("A.in");
    //ofstream cout("A.out");
    int i, j, rez, pas, k;
    ios::sync_with_stdio(false);
    for(i = 2; i * i <= 2 * MAXC; i++)
        if(ciur[i] == 0)
          for(j = i * i; j <= 2 * MAXC; j += i)
             ciur[j] = 1;
    cin >> n >> k;
    for(i = 1; i <= n; i++)
        cin >> v[i].p >> v[i].c >> v[i].l;
    rez = 0;
    for(pas = 1 << 7; pas; pas >>= 1)
        if(rez + pas <= n && check(rez + pas) < k)
           rez += pas;
    rez++;
    if(rez == n + 1)
        cout << -1;
    else
        cout << rez;
    //cin.close();
    //cout.close();
    return 0;
}