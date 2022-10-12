#include<bits/stdc++.h>

using namespace std;
using pi=pair<int,int>;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,m;
  cin >> n >> m;
  vector<int> a(n);
  for(auto &nx : a){cin >> nx;}
  vector<pi> pv;
  for(int i=0;i<m;i++){
    int t,r;
    cin >> t >> r;
    while(!pv.empty()){
      if(pv.back().second<=r){pv.pop_back();}
      else{break;}
    }
    pv.push_back({t,r});
  }
  pv.push_back({0,0});
  // for(auto &nx : pv){
  //   cout << nx.first << ' ' << nx.second << '\n';
  // }

  vector<int> res;
  for(int i=n-1;i>=pv[0].second;i--){res.push_back(a[i]);}
  multiset<int> st;
  for(int i=0;i<pv[0].second;i++){st.insert(a[i]);}
  for(int i=0;i<pv.size()-1;i++){
    int rem=pv[i+1].second;
    while(st.size()>rem){
      //cerr << st.size() << '\n';
      if(pv[i].first==1){
        auto it=st.end();it--;
        res.push_back(*it);
        //cout << *it << ',';
        st.erase(it);
      }
      else{
        auto it=st.begin();
        res.push_back(*it);
        //cout << *it << ',';
        st.erase(it);
      }
    }//cout << '\n';
  }
  reverse(res.begin(),res.end());
  for(int i=0;i<n;i++){
    if(i){cout << ' ';}
    cout << res[i];
  }cout << '\n';
  return 0;
}