#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  set<int> st;
  for(int i=0;i<n;i++){st.insert(i);}
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      int v;
      cin >> v;
      if(v==3){st.erase(i);st.erase(j);}
      if(v==1){st.erase(i);}
      if(v==2){st.erase(j);}
    }
  }
  cout << st.size() << '\n';
  bool fl=false;
  for(auto &nx : st){
    if(fl){cout << ' ';}
    fl=true;
    cout << nx+1;
  }cout << '\n';
  return 0;
}