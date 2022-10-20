#ifdef LOCAL
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
#include <map>
#else
#include <bits/stdc++.h>
#endif
#define pii pair<int,int>
using namespace std;
typedef unsigned long long uint64;
const int maxn = 3e5 + 5;
int a[2][maxn],c[maxn][3];
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,Q;
  cin >> n >> Q;
  int invalid = 0;
  while(Q--)
  {
    int u,v;
    cin >> u >> v;
    u--;
    v--;
    if(a[u][v])
    {
      a[u][v] = 0;
      c[v][0]--;
      if(c[v][0] == 1) invalid--;
      if(u == 0)
      {
        c[v][1]--;
        if(c[v][1] == 1) invalid--;
        if(v)
        {
          c[v-1][2]--;
          if(c[v-1][2] == 1) invalid--;
        }
      }
      else
      {
        c[v][2]--;
        if(c[v][2] == 1) invalid--;
        if(v)
        {
          c[v-1][1]--;
          if(c[v-1][1] == 1) invalid--;
        }
      }
    }
    else
    {
      a[u][v] = 1;
      c[v][0]++;
      if(c[v][0] == 2) invalid++;
      if(u == 0)
      {
        c[v][1]++;
        if(c[v][1] == 2) invalid++;
        if(v)
        {
          c[v-1][2]++;
          if(c[v-1][2] == 2) invalid++;
        }
      }
      else
      {
        c[v][2]++;
        if(c[v][2] == 2) invalid++;
        if(v)
        {
          c[v-1][1]++;
          if(c[v-1][1] == 2) invalid++;
        }
      }
    }
    if(invalid) cout << "No" << '\n';
    else cout << "Yes" << '\n';
  }
  return 0;
}