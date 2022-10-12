#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n,m;
    cin >> n >> m;
    set<int> st;
    for(int i=1;i<=n;i++){
      st.insert(i);
    }
    for(int i=0;i<m;i++){
      int a,b,c;
      cin >> a >> b >> c;
      st.erase(b);
    }
    int ct=(*st.begin());
    for(int i=1;i<=n;i++){
      if(i==ct){continue;}
      cout << i << ' ' << ct << '\n';
    }
  }
  return 0;
}