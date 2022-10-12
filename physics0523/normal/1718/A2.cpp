#include<bits/stdc++.h>

using namespace std;

int f(vector<int> &a){
  int res=0;
  set<int> st;
  int rx=0,elem=0;
  st.insert(rx);
  for(auto &nx : a){
    rx^=nx;
    elem++;
    if(st.find(rx)==st.end()){
      st.insert(rx);
    }
    else{
      // cout << elem << ":" << elem-1 << '\n';
      res+=(elem-1);
      elem=0;
      st.clear();
      rx=0;
      st.insert(rx);
    }
  }
  return res+elem;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &nx : a){cin >> nx;}
    int res=0;
    vector<int> cur;
    for(auto &nx : a){
      if(nx==0){
        res+=f(cur);
        cur.clear();
      }
      else{
        cur.push_back(nx);
      }
    }
    res+=f(cur);
    cout << res << "\n";
  }
  return 0;
}