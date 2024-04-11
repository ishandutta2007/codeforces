#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,x;
  cin >> n >> x;
  vector<int> a(n),b(n);
  multiset<int> st;
  for(auto &nx : a){
    cin >> nx;
    st.insert(nx);
  }
  for(auto &nx : b){cin >> nx;}
  sort(b.begin(),b.end());
  int res=0;
  for(auto &nx : b){
    auto it=st.lower_bound(x-nx);
    if(it!=st.end()){
      res++;
      st.erase(it);
    }
  }
  cout << 1 << ' ' << res << '\n';
  return 0;
}