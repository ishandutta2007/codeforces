#include <bits/stdc++.h>
#define MAXN 1000
#define MAXK 2000

using namespace std;

int a[MAXN + 1], b[MAXK + 1];
vector <int> g[2 * MAXK + 1];
int per[2 * MAXK + 1];
bool f[2 * MAXK + 1];
int n,k,p;

inline bool func(int nod) {
    for(auto it : g[nod])
      if(per[it] == 0) {
          per[nod] = it;
          per[it] = nod;
          return 1;
      }
    f[nod] = 1;
    for(auto it : g[nod])
      if(f[per[it]] == 0 && func(per[it])) {
        per[it] = nod;
        per[nod] = it;
        return 1;
      }
      return 0;
}

inline bool check(int len) {
    int i,j;
    for(i = 1; i <= n + k; i++)
        g[i].clear();
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= k; j++)
          if(abs(a[i] - b[j]) + abs(p - b[j]) <= len) {
            g[i].push_back(j + n);
            g[j + n].push_back(i);
          }
    }
    memset(per, 0, sizeof(per));
    bool flag = 1;
    while(flag) {
        memset(f, 0, sizeof(f));
        flag = 0;
        for(i = 1; i <= n; i++)
            if(per[i] == 0)
               flag |= func(i);
    }
    int cnt = 0;
    for(i = 1; i <= n; i++)
        if(per[i])
           cnt++;
    return cnt == n;
}


int main() {
  //  fstream cin("B.in");
  //  ofstream cout("B.out");
    int i,rez,pas;
    ios::sync_with_stdio(false);
    cin >> n >> k >> p;
    for(i = 1; i <= n; i++)
        cin >> a[i];
    for(i = 1; i <= k; i++)
        cin >> b[i];
    rez = -1;
    for(pas = 1 << 30; pas; pas >>= 1)
        if(check(rez + pas) == 0)
           rez += pas;
    cout << rez + 1;
  //  cin.close();
  //  cout.close();
    return 0;
}