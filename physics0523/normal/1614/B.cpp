#include<bits/stdc++.h>

using namespace std;
using pl=pair<long long,long long>;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    long long n;
    cin >> n;
    vector<pl> pv(n);
    for(int i=1;i<=n;i++){
      cin >> pv[i-1].first;
      pv[i-1].second=i;
    }
    sort(pv.begin(),pv.end());
    reverse(pv.begin(),pv.end());

    long long res=0;
    vector<long long> x(n+1,0);
    for(int i=0;i<n;i++){
      long long cx;
      if(i%2){cx=(i/2)+1;}
      else{cx=-((i/2)+1);}
      x[pv[i].second]=cx;
      res+=2*max(cx,-cx)*pv[i].first;
    }
    cout << res << "\n";
    for(int i=0;i<=n;i++){
      if(i){cout << " ";}
      cout << x[i];
    }cout << "\n";
  }
  return 0;
}