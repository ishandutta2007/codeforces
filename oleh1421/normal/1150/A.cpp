#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
vector<int>v;
int maxx=0;
int dp[2001][2001];
int F(int pos,int s){
    if (pos==v.size()) return s;
    if (dp[pos][s]!=-1) return dp[pos][s];
    int res=0;
    for (int i=0;v[pos]*i<=s;i++) {
        res=max(res,F(pos+1,s-v[pos]*i)+i*maxx);
    }
    dp[pos][s]=res;
    return res;
}
int main()
{
   int n,m,r;cin>>n>>m>>r;
   v.resize(n);
   for (int i=0;i<n;i++) cin>>v[i];
   for (int i=0;i<m;i++){
       int x;cin>>x;
       maxx=max(maxx,x);
   }
   for (int i=0;i<=n;i++){
      for (int j=0;j<=r;j++){
          dp[i][j]=-1;
      }
   }
   cout<<F(0,r);

   return 0;
}