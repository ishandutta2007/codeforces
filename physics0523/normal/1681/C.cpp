#include<bits/stdc++.h>

using namespace std;
using pi=pair<int,int>;
using ppi=pair<pi,int>;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n;
    cin >> n;
    vector<ppi> c(n);
    for(int i=0;i<n;i++){
      cin >> c[i].first.first;
    }
    for(int i=0;i<n;i++){
      cin >> c[i].first.second;
      c[i].second=i;
    }
    sort(c.begin(),c.end());
    bool fl=true;
    for(int i=1;i<n;i++){
      if(c[i-1].first.first>c[i].first.first){fl=false;}
      if(c[i-1].first.second>c[i].first.second){fl=false;}
    }
    if(!fl){cout << "-1\n";continue;}
    vector<int> p(n);
    for(int i=0;i<n;i++){
      p[c[i].second]=i;
    }
    vector<pi> res;
    for(int i=0;i<n;i++){
      while(p[i]!=i){
        int p1=i,p2=p[i];
        swap(p[p1],p[p2]);
        res.push_back({p1,p2});
      }
    }
    cout << res.size() << '\n';
    for(auto &nx : res){
      cout << nx.first+1 << ' ' << nx.second+1 << '\n';
    }
  }
  return 0;
}