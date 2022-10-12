#include<bits/stdc++.h>
#define mod 998244353

using namespace std;

int f(char p,char q){
  if(p=='?' && q=='?'){return 1;}
  if(p=='?'){return 0;}
  if(q=='?'){return 0;}
  if(p==q){return 0;}
  return -1;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<vector<long long>> dp(20,vector<long long>(1<<17,0));
  int l;
  string s;
  cin >> l >> s;
  int wq=0;
  for(auto &nx : s){
    if(nx=='?'){wq++;}
  }

  for(long long knd=1;knd<=17;knd++){
    vector<long long> ce(l+1,1);
    for(int i=1;i<=l;i++){ce[i]=(ce[i-1]*knd)%mod;}

    for(int i=0;i<=2*(l-1);i++){
      int p=(i/2);
      int q=i-p;
      int fl=0;
      int rk=wq;
      while(p>=0 && q<l){
        int fv=f(s[p],s[q]);
        if(fv==-1){break;}
        else if(fv==0){
          if(s[p]=='?'){fl|=(1<<(s[q]-'a'));rk--;}
          if(s[q]=='?'){fl|=(1<<(s[p]-'a'));rk--;}
        }
        else if(p!=q){rk--;}
        dp[knd][fl]+=ce[rk];
        dp[knd][fl]%=mod;
        p--;q++;
      }
    }
    for(int i=0;i<17;i++){
      for(int j=0;j<(1<<17);j++){
        if(j&(1<<i)){
          dp[knd][j]+=dp[knd][j^(1<<i)];
          dp[knd][j]%=mod;
        }
      }
    }
  }
  int t;
  cin >> t;
  while(t>0){
    t--;
    string qs;
    cin >> qs;
    int fl=0;
    for(auto &nx : qs){fl|=(1<<(nx-'a'));}
    cout << dp[qs.size()][fl] << '\n';
  }
  return 0;
}