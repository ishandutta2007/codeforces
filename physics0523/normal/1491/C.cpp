#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    long long n;
    cin >> n;
    vector<long long> a(n);
    for(long long i=0;i<n;i++){cin >> a[i];}
    long long res=0;
    vector<long long> mem(n+1,0);
    for(long long i=0;i<n;i++){
      //cout << mem[i] << ',';
      res+=max(a[i]-1-mem[i],0ll);
      long long kj=max(0ll,mem[i]+1-a[i]);
      mem[i+1]+=kj;
      for(long long j=i+2;j<=i+a[i];j++){
        if(j>=n){break;}
        mem[j]++;
      }
    }
    cout << res << '\n';
  }
  return 0;
}