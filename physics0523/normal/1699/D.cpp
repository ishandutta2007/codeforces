#include<bits/stdc++.h>

using namespace std;

bool jud(int p,int q){
  if(q==0){return true;}
  if(q%2){return false;}
  if(p*2>q){return false;}
  return true;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &nx : a){
      cin >> nx;
      nx--;
    }
    vector<vector<int>> freq(n,vector<int>(n,0));
    for(int i=0;i<n;i++){
      int cf=0;
      vector<int> bk(n,0);
      for(int j=i;j<n;j++){
        bk[a[j]]++;
        cf=max(cf,bk[a[j]]);
        freq[i][j]=cf;
      }
    }
    vector<int> dp(n,-1e9);
    dp[0]=1;
    for(int i=1;i<n;i++){
      if(jud(freq[0][i-1],i)){dp[i]=1;}
    }
    for(int i=1;i<n;i++){
      for(int j=0;j<i;j++){
        // j -> i
        if(dp[j] < -5e8){continue;}
        if(a[j]!=a[i]){continue;}
        if(jud(freq[j+1][i-1],i-j-1)){
          dp[i]=max(dp[i],dp[j]+1);
        }
      }
    }
    int res=max(0,dp[n-1]);
    for(int i=n-2;i>=0;i--){
      if(jud(freq[i+1][n-1],n-i-1)){res=max(res,dp[i]);}
    }
    cout << res << '\n';
  }
  return 0;
}