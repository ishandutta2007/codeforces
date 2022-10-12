#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  set<int> st;
  set<int> drs;
  vector<int> res;
  int cnt=0;
  for(int i=0;i<n;i++){
    int v;
    cin >> v;
    if(v>0){
      if(st.find(v)!=st.end()){cout << "-1\n";return 0;}
      if(drs.find(v)!=drs.end()){cout << "-1\n";return 0;}
      st.insert(v);
    }
    else{
      if(st.find(-v)==st.end()){cout << "-1\n";return 0;}
      st.erase(-v);
      drs.insert(-v);
    }
    cnt++;
    if(st.empty()){
      drs.clear();
      res.push_back(cnt);
      cnt=0;
    }
  }
  if(cnt){cout << "-1\n";return 0;}
  cout << res.size() << '\n';
  bool sfl=false;
  for(auto &nx : res){
    if(sfl){cout << ' ';}
    sfl=true;
    cout << nx;
  }cout << '\n';
  return 0;
}