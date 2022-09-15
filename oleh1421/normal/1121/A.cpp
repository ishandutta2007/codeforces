#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int p[2000001];
int h[2000001];
int used[2000001];
int main()
{
   int n,m,k;cin>>n>>m>>k;
   for (int i=1;i<=n;i++) cin>>p[i];
   for (int i=1;i<=n;i++){
       int s;cin>>s;
       h[i]=s;
       used[s]=max(used[s],p[i]);
   }
   int cnt=0;
   for (int i=1;i<=k;i++){
       int c;cin>>c;
       if (p[c]<used[h[c]]) cnt++;
   }
   cout<<cnt;
   return 0;
}