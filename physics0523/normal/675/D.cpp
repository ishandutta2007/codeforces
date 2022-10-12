#include<bits/stdc++.h>
#define inf 1072114514

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  map<int,int> mp;
  set<int> st;
  st.insert(-inf);
  st.insert(inf);
  for(int i=0;i<n;i++){
    if(i>=2){cout << ' ';}
    int v;
    cin >> v;
    if(i!=0){
      auto it=st.lower_bound(v);
      int lg=(*it);
      it--;
      int sm=(*it);
      if(lg!=inf && (mp[lg]&1)==0){
        cout << lg;
        mp[lg]|=1;
      }
      else{
        cout << sm;
        mp[sm]|=2;
      }
    }
    st.insert(v);
  }cout << '\n';
  return 0;
}