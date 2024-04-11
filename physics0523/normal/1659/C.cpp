#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n;
    long long a,b;
    cin >> n >> a >> b;
    vector<long long> x(n);
    for(auto &nx : x){cin >> nx;}
    x.push_back(0);
    sort(x.begin(),x.end());

    long long res=8e18,suf=0;
    for(long long i=n;i>=0;i--){
      // cout << (a+b)*x[i] << ' ' << suf << '\n';
      res=min(res,(a+b)*x[i]+suf);
      if(i!=0){suf+=b*(n-i+1)*(x[i]-x[i-1]);}
    }
    cout << res << '\n';
  }
  return 0;
}