#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll s[100001];
ll a[100001];
vector<int>g[100001];
int p[100001];
void dfs(int v,int h){
    if (h%2==0){
        if (g[v].empty()) a[v]=0;
        else {
            ll minx=100000000001ll;
            for (auto to:g[v]) minx=min(minx*1ll,s[to]*1ll);
            a[v]=minx-s[p[v]];
            for (auto to:g[v]) dfs(to,h+1);
        }
    }  else {
        a[v]=s[v]-s[p[p[v]]]-a[p[v]];
        for (auto to:g[v]) dfs(to,h+1);
    }
}
int main()
{
   int n;cin>>n;
   for (int i=2;i<=n;i++){
       int pr;cin>>pr;
       g[pr].push_back(i);
       p[i]=pr;
   }
   for (int i=1;i<=n;i++) cin>>s[i];
   for (int i=1;i<=n;i++) a[i]=-1;
   a[1]=s[1];
   for (auto to:g[1]) dfs(to,2);
   ll res=0ll;
   for (int i=1;i<=n;i++) {
        res+=a[i]*1ll;
        if (a[i]<0){
            cout<<-1;
            return 0;
        }
   }
   cout<<res;
   return 0;
}