#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 5;
long long c[maxn],hs[maxn][3];
const long long P = 1e9 + 7;
const long long Q = 1e9 + 9;
const long long R = 0x94878787;
vector<int> e[maxn];
bool del[maxn];
map<long long,int>mp;
int main()
{
  int T;
  scanf("%d",&T);
  while(T--)
  {
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i = 1; i <= n; i++)
    {
      e[i].clear();
      hs[i][0] = hs[i][1] = hs[i][2] = 0;
      del[i] = 0;
    }
    mp.clear();
    for(int i = 1; i <= n; i++) scanf("%lld",&c[i]);
    for(int i = 0; i < m; i++)
    {
      int u,v;
      scanf("%d%d",&u,&v);
      e[v].push_back(u);
    }
    for(int i = 1; i <= n; i++) sort(e[i].begin(),e[i].end());
    for(int i = 1; i <= n; i++)
    {
      for(int j = 0; j < e[i].size(); j++)
      {
        long long k = e[i][j];
        hs[i][0] = hs[i][0] * 97 + k;
        hs[i][1] = hs[i][1] * 101 + k;
        hs[i][2] = hs[i][2] * 890501 + k;
        hs[i][0] %= P;
        hs[i][1] %= Q;
        hs[i][2] %= R;
      }
    }
    long long ans = 0;
    for(int i = 1; i <= n; i++)
    {
      if(e[i].size() == 0)
      {
        del[i] = 1;
        continue;
      }
      bool ok = 1;
      int k;
      if(mp.count(hs[i][0]*R+hs[i][1]))
      {
        k = mp[hs[i][0]*R+hs[i][1]];
        if(hs[i][2] == hs[k][2]) ok = 0;
      }
      if(!ok)
      {
        c[k] += c[i];
        del[i] = 1;
      }
      else mp[hs[i][0]*R+hs[i][1]] = i;
    }
    for(int i = 1; i <= n; i++)
    {
      if(!del[i]) ans = __gcd(ans,c[i]);
    }
    printf("%lld\n",ans);
  }
  return 0;
}