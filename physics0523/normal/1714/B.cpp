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
    int res=n;
    set<int> st;
    for(int i=n-1;i>=0;i--){
      if(st.find(a[i])!=st.end()){res=n-i-1;break;}
      st.insert(a[i]);
    }
    cout << n-res << "\n";
  }
  return 0;
}