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
    stack<int> st;
    vector<int> p(n);
    for(auto &nx : p){cin >> nx;}
    for(int i=n-1;i>=0;i--){
      while(!st.empty() && st.top()>p[i]){st.pop();}
      st.push(p[i]);
    }
    deque<int> dq;
    for(int i=0;i<n;i++){
      if(!st.empty() && st.top()==p[i]){dq.push_front(p[i]);st.pop();}
      else{dq.push_back(p[i]);}
    }
    for(int i=0;i<n;i++){
      if(i){cout << ' ';}
      cout << dq.front();
      dq.pop_front();
    }cout << '\n';
  }
  return 0;
}