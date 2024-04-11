#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
 
const int mxN=1e6, mxM=5e6;
int n, m, cnt[mxM+2], dp[mxM+1], mx;
bool has[mxM+1];
 
void upd(int x, int val) {
           if (has[x])
                      --cnt[dp[x]];
           dp[x]=val;
           if (has[x]) {
                      ++cnt[dp[x]];
                      while(!cnt[mx])
                                 --mx;
           }
}
 
void solve() {
           cin >> n >> m;
           memset(has, 0, m+1);
           memset(cnt, 0, 4*(m+2));
           mx=m+1;
           fill(dp+1, dp+m+1, m+1);
           for (int i=0; i<n; ++i) {
                      int x;
                      cin >> x;
                      if (!has[x]) {
                                 has[x]=1;
                                 ++cnt[m+1];
                      }
           }
           int ans=69696969;
           for (int i=m; i; --i) { // loop over min(a_i)
                      upd(i, i);
                      for (int j=i; (ll)i*j<=m; ++j)
                                 if (dp[j]<dp[i*j])
                                            upd(i*j, dp[j]);
                      if (mx<m+1)
                                 ans=min(ans, mx-i);
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