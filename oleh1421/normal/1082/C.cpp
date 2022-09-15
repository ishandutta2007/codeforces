#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int a[100002];
vector<int>g[100001];
int s[100001];
int main()
{
   int n,m;cin>>n>>m;
   for (int i=1;i<=n;i++){
       int s,r;cin>>s>>r;
       g[s].push_back(r);
   }
   for (int i=1;i<=m;i++){
       sort(g[i].begin(),g[i].end());
       reverse(g[i].begin(),g[i].end());
       int sum=0;
       for (int j=0;j<g[i].size();j++){
           sum+=g[i][j];
           if (sum>0) s[j+1]+=sum;
       }
   }
   int maxx=0;
   for (int i=0;i<=n;i++) maxx=max(maxx,s[i]);
   cout<<maxx;
   return 0;
}