#include<bits/stdc++.h>
#define mod 998244353

using namespace std;

long long cnt[16]={0};
long long sum[16][16]={0};

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  long long n;
  cin >> n;
  for(int i=0;i<n;i++){
    long long x;
    cin >> x;
    string s=to_string(x);
    int dig=s.size();
    cnt[dig]++;
    reverse(s.begin(),s.end());
    for(int j=0;j<dig;j++){
      sum[dig][j]+=(s[j]-'0');
      sum[dig][j]%=mod;
    }
  }

  long long res=0;
  for(int i=1;i<16;i++){
    for(int j=1;j<16;j++){
      if(cnt[i]==0 || cnt[j]==0){continue;}
      long long pos=1;
      int p=0,q=0;
      for(int k=0;k<32;k++){
        if(k%2==0){
          if(i<=p){continue;}
          long long del=(pos*sum[i][p])%mod;
          del*=cnt[j];del%=mod;
          res+=del;res%=mod;
          p++;
          pos*=10;pos%=mod;
        }
        else{
          if(j<=q){continue;}
          long long del=(pos*sum[j][q])%mod;
          del*=cnt[i];del%=mod;
          res+=del;res%=mod;
          q++;
          pos*=10;pos%=mod;
        }
      }
    }
  }
  cout << res << "\n";
  return 0;
}