#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    long long n,k;
    cin >> n >> k;
    vector<long long> cnt(31,n);
    for(int i=0;i<n;i++){
      long long v;
      cin >> v;
      for(int j=0;j<=30;j++){
        if(v&(1ll<<j)){cnt[j]--;}
      }
    }
    long long res=0;
    for(int i=30;i>=0;i--){
      if(k>=cnt[i]){
        k-=cnt[i];
        res|=(1ll<<i);
      }
    }
    cout << res << '\n';
  }
  return 0;
}