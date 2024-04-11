#include<bits/stdc++.h>
#define inf 1000000007

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    string s;
    cin >> s;
    s=":)"+s;
    int n=s.size();
    vector<int> dp(4,inf);
    dp[0]=0;
    for(int i=2;i<n;i++){
      vector<int> ndp(4,inf);
      for(int j=0;j<4;j++){
        for(int k=0;k<2;k++){
          if((j&1)==0 && k==0 && s[i-1]==s[i]){continue;}
          if((j&2)==0 && k==0 && s[i-2]==s[i]){continue;}
          //printf("%d %d %d\n",i,j,k);
          ndp[(2*j+k)&3]=min(dp[j]+k,ndp[(2*j+k)&3]);
        }
      }
      dp.swap(ndp);
      //printf("%d %d %d %d\n",dp[0],dp[1],dp[2],dp[3]);
    }
    cout << min( min(dp[0],dp[1]) , min(dp[2],dp[3]) ) << '\n';
  }
}