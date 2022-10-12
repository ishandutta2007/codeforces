#include<bits/stdc++.h>
#define mod 1000000007

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  vector<long long> seq(100);
  for(long long i=1;i<100;i++){seq[i]=i;}
  for(long long i=1;i<100;i++){
    for(long long j=i+1;j<100;j++){
      if(seq[j]%seq[i]==0){seq[j]/=seq[i];}
    }
  }
  while(t>0){
    t--;
    long long n;
    cin >> n;
    long long f=1,res=0;
    for(long long i=1;i<100;i++){
      long long nn=(n/seq[i]);
      res+=(n-nn)*i;res%=mod;
      n=nn;
    }
    cout << res%mod << '\n';
  }
  return 0;
}