#include<bits/stdc++.h>

using namespace std;
using Graph=vector<vector<int>>;

int main(){
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n;
    cin >> n;
    vector<long long> a(n+1);
    vector<int> cnt(n+1);
    vector<long long> res;
    Graph g(n+1);
    long long sig=0;
    for(int i=1;i<=n;i++){cin >> a[i];}
    for(int i=0;i<(n-1);i++){
      int p,q;
      cin >> p >> q;
      g[p].push_back(q);
      g[q].push_back(p);
      cnt[p]++;cnt[q]++;
      sig+=a[p];
      sig+=a[q];
    }
    vector<long long> pv;
    for(int i=1;i<=n;i++){
      for(int j=2;j<=cnt[i];j++){pv.push_back(a[i]);}
    }
    sort(pv.begin(),pv.end());
    res.push_back(sig);
    int rc=1,pp=0;
    while(rc<(n-1)){
      sig-=pv[pp];
      res.push_back(sig);
      rc++;pp++;
    }
    reverse(res.begin(),res.end());
    for(int i=0;i<n-1;i++){
      if(i){cout << ' ';}
      cout << res[i];
    }cout << '\n';
  }
}