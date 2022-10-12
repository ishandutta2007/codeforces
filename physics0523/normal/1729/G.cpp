// Why strlen <= 500?
#include<bits/stdc++.h>
#define mod 1000000007

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    string a,b;
    cin >> a >> b;
    int al=a.size();
    int bl=b.size();
    int olim=(al/bl);
    vector<int> fl(al+1,0);
    for(int i=0;i<al;i++){
      bool ok=true;
      for(int j=0;j<bl;j++){
        if(i+j>=al){ok=false;break;}
        if(b[j]!=a[i+j]){ok=false;break;}
      }
      if(ok){fl[i]=1;}
    }

    vector<vector<vector<int>>> dp(al+1,vector<vector<int>>(bl+1,vector<int>(olim+1,-1)));
    dp[0][bl][0]=1;
    
    for(int i=0;i<al;i++){
      for(int j=1;j<=bl;j++){
        for(int k=0;k<=olim;k++){
          if(dp[i][j][k]==-1){continue;}
          if(fl[i]==0){
            int lim=j;
            if(lim!=bl){lim--;}
            if(dp[i+1][lim][k]==-1){dp[i+1][lim][k]=0;}
            dp[i+1][lim][k]+=dp[i][j][k];
            dp[i+1][lim][k]%=mod;
          }
          else{
            if(dp[i+bl][bl][k+1]==-1){dp[i+bl][bl][k+1]=0;}
            dp[i+bl][bl][k+1]+=dp[i][j][k];
            dp[i+bl][bl][k+1]%=mod;

             int lim=min(j-1,bl-1);
if(dp[i+1][lim][k]==-1){dp[i+1][lim][k]=0;}
            dp[i+1][lim][k]+=dp[i][j][k];
            dp[i+1][lim][k]%=mod;
          }
        }
      }
    }
    for(int i=0;i<=olim;i++){
      if(dp[al][bl][i]!=-1){
        cout << i << " "  << dp[al][bl][i] << "\n";
        break;
      }
    }
  }
  return 0;
}