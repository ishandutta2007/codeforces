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
    vector<vector<int>> pos(n+1);
    for(int i=0;i<n;i++){
      int v;
      cin >> v;
      pos[v].push_back(i);
    }

    vector<int> res(n);
    vector<int> st;
    for(int i=1;i<=n;i++){
      if(pos[i].size()>0){
        st.push_back(i);
      }
    }
    while(!st.empty()){
      vector<int> nst;
      vector<int> pts;
      for(auto &nx : st){
        pts.push_back(pos[nx].back());
        pos[nx].pop_back();
        if(pos[nx].size()>0){nst.push_back(nx);}
      }
      int sz=st.size();
      for(int i=0;i<sz;i++){
        res[pts[(i+1)%sz]]=st[i];
      }
      st.swap(nst);
    }
    for(int i=0;i<n;i++){
      if(i){cout << ' ';}
      cout << res[i];
    }cout << '\n';
  }
  return 0;
}