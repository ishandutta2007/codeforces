#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    long long sum=0,mi=8e18;
    long long n;
    cin >> n;
    for(long long i=0;i<n;i++){
      long long v;
      cin >> v;
      sum+=v;
      mi=min(v,mi);
    }
    cout << sum-mi*n << '\n';
  }
  return 0;
}