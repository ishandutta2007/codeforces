#include<bits/stdc++.h>
#define inf 1000000007

using namespace std;

int main(){
  std::random_device seed_gen;
  std::mt19937 engine(seed_gen());
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  int dp[128][128];
  while(t>0){
    t--;
    int n,m;
    cin >> n >> m;
    vector<string> s(n);
    for(int i=0;i<n;i++){
      cin >> s[i];
    }
    int res=0;
    for(int i=0;i<n;i++){
      if(s[i][m-1]=='R'){res++;}
    }
    for(int i=0;i<m;i++){
      if(s[n-1][i]=='D'){res++;}
    }
    cout << res << '\n';
  }
  return 0;
}