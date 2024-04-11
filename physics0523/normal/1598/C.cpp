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
    cin >> n;
    long long sig=0;
    vector<long long> a(n);
    for(auto &nx : a){
      cin >> nx;
      sig+=nx;
    }
    long long p=sig,q=n;
    long long g=gcd(p,q);
    p/=g;q/=g;
    if(q>2){cout << "0\n";continue;}
    if(q==1){p*=2;}
    long long res=0;
    map<long long,long long> mp;
    for(auto &nx : a){
      long long tg=p-nx;
      res+=mp[tg];
      mp[nx]++;
    }
    cout << res << '\n';
  }
  return 0;
}