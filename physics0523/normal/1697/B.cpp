#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t=1;
  // cin >> t;
  while(t>0){
    t--;
    long long n,m;
    cin >> n >> m;
    vector<long long> a(n);
    for(auto &nx : a){cin >> nx;}
    sort(a.begin(),a.end());
    vector<long long> rw(n+1,0);
    for(int i=0;i<n;i++){
      rw[i+1]=rw[i]+a[i];
    }
    while(m>0){
      m--;
      long long x,y;
      cin >> x >> y;
      cout << rw[n-x+y]-rw[n-x] << '\n';
    }
  }
  return 0;
}