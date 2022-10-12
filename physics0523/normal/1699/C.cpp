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
    int n;
    cin >> n;
    vector<long long> p(n);
    vector<long long> inv(n);
    for(int i=0;i<n;i++){
      cin >> p[i];
      inv[p[i]]=i;
    }
    long long res=1;
    long long l=1e9,r=-1e9;
    for(int i=0;i<n;i++){
      if(l<=inv[i] && inv[i]<=r){
        res*=(r-l+1)-i;
        res%=mod;
      }
      else{
        l=min(l,inv[i]);
        r=max(r,inv[i]);
      }
    }
    cout << res << '\n';
  }
  return 0;
}