#include<bits/stdc++.h>

using namespace std;
using pi=pair<int,int>;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,m,d;
  cin >> n >> m >> d;
  vector<int> res(n);
  int cur=0;
  set<pi> st;
  for(int i=0;i<n;i++){
    int v;
    cin >> v;
    st.insert({v,i});
  }

  while(!st.empty()){
    cur++;
    auto it=st.begin();
    while(it!=st.end()){
      pi cp=(*it);
      st.erase(it);
      res[cp.second]=cur;
      cp.first+=(d+1);
      cp.second=-1e9;
      it=st.lower_bound(cp);
    }
  }
  cout << cur << '\n';
  for(int i=0;i<n;i++){
    if(i){cout << ' ';}
    cout << res[i];
  }cout << '\n';
  return 0;
}