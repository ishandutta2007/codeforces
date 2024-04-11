#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    long long n,h;
    cin >> n >> h;
    vector<long long> a(n);
    for(auto &nx : a){cin >> nx;}
    vector<long long> mem;
    for(int i=1;i<n;i++){mem.push_back(a[i]-a[i-1]);}
    mem.push_back(2e18);
    long long st=0,fi=1.5e18,te;
    while(st<=fi){
      te=(st+fi)/2;
      long long sig=0;
      for(auto &nx : mem){sig+=min(te,nx);}
      if(sig>=h){fi=te-1;}else{st=te+1;}
    }
    cout << st << '\n';
  }
  return 0;
}