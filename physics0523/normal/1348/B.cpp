#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n,k;
    cin >> n >> k;
    vector<int> a;
    set<int> st;
    for(int i=0;i<n;i++){
      int v;
      cin >> v;
      if(st.find(v)==st.end()){
        st.insert(v);
        a.push_back(v);
      }
    }
    while(a.size()<k){a.push_back(a.back());}
    if(a.size()>k){cout << "-1\n";continue;}
    int circ=(10000/a.size());
    int sz=circ*a.size();
    cout << sz << '\n';
    for(int i=0;i<sz;i++){
      if(i){cout << ' ';}
      cout << a[i%a.size()];
    }cout << '\n';
  }
  return 0;
}