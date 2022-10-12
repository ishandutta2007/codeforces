#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n,m;
    cin >> n >> m;
    vector<int> p(n);
    for(auto &nx : p){cin >> nx;}
    vector<pair<int,double>> pv(m);
    for(auto &nx : pv){cin >> nx.first >> nx.second;}
    int bd=0;
    for(int i=n-1;i>=0;i--){
      if(p[i]!=(i+1)){
        bd=i+1;
        break;
      }
    }
    if(bd==0){cout << "1\n";continue;}
    
    sort(pv.begin(),pv.end());
    reverse(pv.begin(),pv.end());
    double res=0.0,rem=1.0;
    for(auto &nx : pv){
      double suc=rem*nx.second;
      rem*=(1.0-nx.second);
      if(nx.first>=bd){res+=suc;}
    }
    cout << std::setprecision(15) << res << '\n';
  }
  return 0;
}