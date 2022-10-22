#include <bits/stdc++.h>
using namespace std;
 
const int mxN=5000;
int n, a[mxN], cnt[mxN], dp[mxN+2];
bool can[mxN][mxN];
vector<int> oc[mxN];
 
void solve() {
 cin >> n;
 for (int i=0; i<n; ++i)
  oc[i]={-1};
 for (int i=0; i<n; ++i) {
  cin >> a[i], --a[i];
  oc[a[i]].push_back(i);
 }
 for (int i=0; i<n; ++i) {
  memset(cnt, 0, 4*n);
  int mx=0;
  for (int j=i; j<n; ++j) {
   mx=max(mx, (++cnt[a[j]]));
   can[i][j]=(j-i+1)%2==0&&mx<=(j-i+1)/2;
  }
 }
 int ans=0;
 for (int i=0; i<n; ++i) {
  if (oc[i].size()==1)
   continue;
  oc[i].push_back(n);
  for (int j : oc[i])
   dp[j+1]=-69696969;
  dp[0]=-1;
  for (int j=1; j<oc[i].size(); ++j)
   for (int k=0; k<j; ++k)
    if (oc[i][k]+1==oc[i][j]||can[oc[i][k]+1][oc[i][j]-1])
     dp[oc[i][j]+1]=max(dp[oc[i][j]+1], dp[oc[i][k]+1]+1);
  ans=max(ans, dp[n+1]);
 }
 cout << ans << "\n";
}
 
int main() {
 ios::sync_with_stdio(0);
 cin.tie(0);
 int t;
 cin >> t;
 while(t--)
  solve();
 return 0;
}