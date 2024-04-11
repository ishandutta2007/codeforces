#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int m,n;
    bool obv=false;
    cin >> m >> n;
    vector<pair<int,pair<int,int>>> vd;
    for(int i=0;i<m;i++){
      for(int j=0;j<n;j++){
        int v;
        cin >> v;
        vd.push_back({v,{i,j}});
      }
    }
    sort(vd.begin(),vd.end());
    reverse(vd.begin(),vd.end());
    set<int> st,ht;
    int cnt=0;
    for(auto &nx : vd){
      st.insert(nx.second.first);
      ht.insert(nx.second.second);
      //cerr << nx.second.first << ' ' << nx.second.second << '\n';
      cnt++;
      if( (st.size()!=cnt) && ht.size()==n){
        cout << nx.first << '\n';break;
      }
    }
  }
  return 0;
}