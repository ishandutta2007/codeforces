#include<bits/stdc++.h>

using namespace std;
using pi=pair<int,int>;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,k;
  cin >> n >> k;
  set<pi> st;
  for(int i=0;i<256;i++){
    st.insert({i,i});
  }
  for(int i=0;i<n;i++){
    if(i){cout << ' ';}
    int v;
    cin >> v;
    while(1){
      auto it=st.lower_bound({v+1,-1});it--;
      if(it==st.begin()){
        cout << (*it).first;
        break;
      }

      auto fit=it;fit--;
      if( (*it).second-(*fit).first+1 > k){
        cout << (*it).first;
        break;
      }

      pi ins={(*fit).first,(*it).second};
      st.erase(it);st.erase(fit);
      st.insert(ins);
    }
  }cout << '\n';
  return 0;
}