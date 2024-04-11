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
    vector<long long> a(n);
    for(auto &nx : a){cin >> nx;}
    vector<long long> t(n);
    for(auto &nx : t){cin >> nx;}
    long long mi=8e18,ma=-8e18;
    for(int i=0;i<n;i++){
      mi=min(mi,a[i]-t[i]);
      ma=max(ma,a[i]+t[i]);
    }

    long long res=(mi+ma);
    if(res<0){
      cout << "-";
      res*=-1;
    }
    long long rem=res%2;
    cout << res/2;
    if(rem){cout << ".5";}
    cout << "\n";
  }
  return 0;
}