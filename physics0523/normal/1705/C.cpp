#include<bits/stdc++.h>

using namespace std;
using pl=pair<long long,long long>;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    long long n,c,q;
    cin >> n >> c >> q;
    string s;
    cin >> s;

    set<pl> st;
    st.insert({0,0});
    long long len=n;
    for(int i=0;i<c;i++){
      long long l,r;
      cin >> l >> r;
      l--;r--;
      st.insert({len,len-l});
      len+=(r-l+1);
    }
    st.insert({8e18,8e18});
    for(int i=0;i<q;i++){
      long long x;
      cin >> x;
      x--;
      while(x>=n){
        auto it=st.lower_bound({x+1,-1});
        it--;
        x-=(*it).second;
      }
      cout << s[x] << "\n";
    }
  }
  return 0;
}