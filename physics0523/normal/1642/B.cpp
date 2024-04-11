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
    set<int> st;
    for(int i=0;i<n;i++){
      int v;
      cin >> v;
      st.insert(v);
    }
    for(int i=1;i<=n;i++){
      if(i-1){cout << ' ';}
      cout << max((int)st.size(),i);
    }
    cout << '\n';
  }
  return 0;
}