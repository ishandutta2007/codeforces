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
    vector<int> a(n);
    set<int> st;
    for(int i=0;i<n;i++){
      cin >> a[i];
      st.insert(a[i]);
    }
    bool isok=false;
    for(auto &nx : a){
      if(st.find(nx+k)!=st.end()){isok=true;break;}
    }
    if(isok){cout << "YES\n";}
    else{cout << "NO\n";}
  }
  return 0;
}