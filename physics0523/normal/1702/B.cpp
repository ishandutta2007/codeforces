#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    string s;
    cin >> s;
    int res=1;
    set<char> st;
    for(auto &nx : s){
      st.insert(nx);
      if(st.size()>=4){
        res++;
        st.clear();
        st.insert(nx);
      }
    }
    cout << res << '\n';
  }
  return 0;
}