#include<bits/stdc++.h>

using namespace std;
using pi=pair<int,int>;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &nx : a){cin >> nx;}
    set<pi> st;
    int sig=0;
    for(int i=0;i<n;i++){
      int v;
      cin >> v;
      st.insert({v-a[i],i+1});
      sig+=(v-a[i]);
    }
    if(sig!=0){cout << "-1\n";continue;}
    vector<pi> res;
    while(1){
      auto bit=st.begin();
      auto eit=st.end();
      eit--;
      if((*bit).first==0){break;}
      pi bp=(*bit),ep=(*eit);
      st.erase(bit);st.erase(eit);
      bp.first++;ep.first--;
      res.push_back({bp.second,ep.second});
      st.insert(bp);st.insert(ep);
    }
    cout << res.size() << '\n';
    for(auto &nx : res){
      cout << nx.first << ' ' << nx.second << '\n';
    }
  }
  return 0;
}