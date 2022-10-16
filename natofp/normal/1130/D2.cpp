#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const int N=5005;
long long int ile[N];
int odl[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    memset(ile,0,sizeof ile);
    for(int i=0;i<=5000;i++) odl[i]=1e9;
   int n,m; cin>>n>>m;
   for(int i=0;i<m;i++)
   {
       int a,b; cin>>a>>b;
       ile[a]++;
       int t;
       if(b>a) t=b-a;
       else t=n-(a-b);
       odl[a]=min(odl[a],t);
   }
   for(int i=1;i<=n;i++)
   {
       long long int ans=0;
       for(int j=1;j<=n;j++)
       {
           if(ile[j]==0) continue;
           long long int t;
           if(i<=j) t=j-i;
           else t=n-(i-j);
           ans=max(ans,(ile[j]-1)*n+odl[j]+t);
       }
       cout<<ans<<" ";
   }
    return 0;
}