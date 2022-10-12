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
    vector<int> a(n);
    for(auto &nx : a){cin >> nx;}
    bool jud=false;
    set<int> st;
    st.insert(a[0]);
    for(int i=2;i<n;i++){
      if(st.find(a[i])!=st.end()){jud=true;break;}
      st.insert(a[i-1]);
    }
    if(jud){cout << "YES\n";}
    else{cout << "NO\n";}
  }
  return 0;
}