#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> x(n+2),h(n+2);
  x[0]=-1000000007;h[0]=1;
  x[n+1]=2000000007;h[n+1]=1;
  for(int i=1;i<=n;i++){cin >> x[i] >> h[i];}
  int dp1=0,dp2=0;
  for(int i=1;i<=n;i++){
    int ndp1=max(dp1,dp2),ndp2=-1000000007;
    if((x[i]-x[i-1])>h[i]){ndp1=max(dp1+1,ndp1);}
    if((x[i]-x[i-1])>h[i-1]+h[i]){ndp1=max(dp2+1,ndp1);}
    if((x[i+1]-x[i])>h[i]){ndp2=max(max(dp1,dp2)+1,ndp2);}
    dp1=ndp1;
    dp2=ndp2;
  }
  cout << max(dp1,dp2) << '\n';
  return 0;
}