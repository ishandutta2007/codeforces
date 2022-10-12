#include<bits/stdc++.h>
#define mod 998244353

using namespace std;
int cnt[1<<23][26];

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  for(int i=0;i<(1<<23);i++){
    for(int j=0;j<26;j++){cnt[i][j]=30000;}
  }
  //vector<vector<__int16>> cnt(1<<n,vector<__int16>(26,30000));
  for(int i=0;i<n;i++){
    string s;
    cin >> s;
    vector<int> cv(26,0);
    for(auto &nx : s){cv[nx-'a']++;}
    for(int j=0;j<26;j++){
      cnt[1<<i][j]=cv[j];
    }
  }
  for(int i=0;i<(1<<n);i++){
    for(int j=0;j<n;j++){
      for(int k=0;k<26;k++){
        cnt[i|(1<<j)][k]=min(cnt[i|(1<<j)][k],cnt[i][k]);
      }
    }
  }
  vector<int> f(1<<n,0);
  for(int i=1;i<(1<<n);i++){
    long long cur=1;
    for(int j=0;j<26;j++){cur*=(cnt[i][j]+1);cur%=mod;}
    f[i]=cur;
  }
  //for(int i=0;i<(1<<n);i++){cerr << i << ' ' << f[i] << '\n';}
  for(int i=0;i<n;i++){
    for(int j=0;j<(1<<n);j++){
       if(!(j&(1<<i))){f[j]+=(mod-f[j|(1<<i)]);f[j]%=mod;}
    }
  }
  f[0]=0;
  //for(int i=0;i<(1<<n);i++){cerr << i << ' ' << f[i] << '\n';}
  long long sig=0;
  for(int i=0;i<(1<<n);i++){
    sig+=f[i];sig%=mod;
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<(1<<n);j++){
      if(j&(1<<i)){f[j]+=f[j^(1<<i)];f[j]%=mod;}
    }
  }
  f[0]=0;
  //for(int i=0;i<(1<<n);i++){cerr << i << ' ' << f[i] << '\n';}

  long long res=0;
  int all=(1<<n)-1;
  for(int i=1;i<(1<<n);i++){
    long long lf=(mod+sig-f[all^i])%mod;
    //cerr << i << ' ' << lf << '\n';
    long long ce=0,cf=0;
    for(int j=0;j<n;j++){
      if(i&(1<<j)){
        ce+=(j+1);
        cf++;
      }
    }
    ce*=cf;ce%=mod;
    res^=(lf*ce);
  }
  cout << res << '\n';
  return 0;
}