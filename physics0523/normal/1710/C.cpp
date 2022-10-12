#include<bits/stdc++.h>
#define mod 998244353

using namespace std;

int main(){
  // vector<int> val={0,3,5,6};
  vector<int> bp={1,2,4};

  string s;
  cin >> s;
  int l=s.size();
  vector<long long> dp(64,0);
  dp[63]=1;
  for(int pos=0;pos<l;pos++){
    vector<long long> ndp(64,0);
    for(int i=0;i<64;i++){
      if(dp[i]==0){continue;}
      for(int nx=0;nx<8;nx++){
        int ksf=0;
        int b1=0,b2=0,b3=0;
        if(nx&1){b1=1;}
        if(nx&2){b2=1;}
        if(nx&4){b3=1;}
        if(b1^b2){ksf|=1;}
        if(b2^b3){ksf|=2;}
        if(b3^b1){ksf|=4;}
        if(ksf==0){ksf=7;}
        // cout << b1 << ' ' << b2 << ' ' << b3 << " : " << ksf << '\n';

        int ikf=0;
        bool fail=false;
        for(auto &ny : bp){
          if((i&ny)>0){
            if((nx&ny)==0 && s[pos]=='0'){ikf|=ny;}
            if((nx&ny)!=0 && s[pos]=='1'){ikf|=ny;}
            if((nx&ny)!=0 && s[pos]=='0'){fail=true;}
          }
        }
        if(fail){continue;}
        int ff=(ksf<<3)+ikf;
        ndp[i&ff]+=dp[i];
        ndp[i&ff]%=mod;
      }
    }
    dp=ndp;
    // for(int i=0;i<64;i++){
    //   if(dp[i]>0){
    //     cout << i << ':' << dp[i] << '\n';
    //   }
    // }cout << '\n';
  }

  long long res=0;
  for(int i=0;i<8;i++){
    res+=dp[i];
    res%=mod;
  }
  cout << res << "\n";
  return 0;
}