#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n;
    cin >> n;
    vector<int> p(n);
    for(auto &nx : p){cin >> nx;}
    stack<int> st;
    st.push(-1e9);
    st.push(p[0]);
    for(int i=1;i<n;i++){
      if(st.top()<p[i]){st.push(p[i]);}
      else{
        int back=st.top();st.pop();
        while(st.top()>p[i]){st.pop();}
        st.push(back);
      }
    }
    cout << st.size()-1 << '\n';
  }
  return 0;
}