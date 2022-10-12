#include<bits/stdc++.h>
#define mod 1000000007

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<int> pal;
  for(int i=1;i<44444;i++){
    string s=to_string(i);
    reverse(s.begin(),s.end());
    if(stoi(s)==i){pal.push_back(i);}
  }

  vector<long long> dp(44444,0);
  dp[0]=1;
  for(int i=0;i<pal.size();i++){
    for(int j=0;pal[i]+j<44444;j++){
      dp[pal[i]+j]+=dp[j];
      dp[pal[i]+j]%=mod;
    }
  }

  int t;
  cin >> t;
  while(t>0){
    t--;
    int v;
    cin >> v;
    cout << dp[v] << '\n';
  }
  return 0;
}