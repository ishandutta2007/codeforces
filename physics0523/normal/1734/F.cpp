#include<bits/stdc++.h>

using namespace std;

//   0001 ... param (1)
//   0101 ... n (2)
// ^ 0100 ... XOR (3)
// + 0110 ... SUM (4)
// count parity of (1) != (4)

long long solve(long long n,long long m){
  vector<long long> dp(8,0); // dp[chain][leq][val]
  dp[2]=1;
  for(long long tg=60;tg>=0;tg--){
    vector<long long> ndp(8,0);
    long long cn=(n&(1ll<<tg));
    long long cm=(m&(1ll<<tg));

    for(long long i=0;i<8;i++){
      for(long long dg=0;dg<2;dg++){
        long long ni=i;
        if(ni&2ll){
          if(cm==0 && dg!=0){continue;}
          if(cm!=0 && dg==0){ni^=2ll;}
        }

        if(dg){ni^=1ll;}
        if(cn!=0 && dg!=0){
          if((ni&4ll)==0){
            ni^=1ll;
          }
          ni&=3ll;
        }
        else if(cn==0 && dg==0){
          ni&=3ll;
        }
        else{
          ni^=5ll;
        }
        ndp[ni]+=dp[i];
      }
    }
    dp=ndp;
  }

  // for(int i=0;i<8;i++){
  //   cerr << dp[i] << " ";
  // }cerr << "\n";
  return dp[1]+dp[5];
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    long long n,m;
    cin >> n >> m;
    cout << solve(n,m) << "\n";
  }
  return 0;
}