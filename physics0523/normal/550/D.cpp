#include<bits/stdc++.h>

using namespace std;
using pi=pair<int,int>;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int k;
  cin >> k;
  if(k%2==0){cout << "NO\n";return 0;}
  if(k==1){
    cout << "YES\n";
    cout << "2 1\n";
    cout << "1 2\n";
    return 0;
  }
  set<pi> st;
  for(int i=0;i<(k+1);i++){
    for(int j=i+1;j<(k+1);j++){
      st.insert({i,j});
    }
  }
  for(int i=0;i<(k-1)/2;i++){
    st.erase({2*i,2*i+1});
    st.insert({2*i,(k+1)});
    st.insert({2*i+1,(k+1)});
  }
  cout << "YES\n";
  cout << 2*(k+2) << ' ' << 2*st.size()+1 << '\n';
  for(auto &nx : st){
    cout << nx.first+1 << ' ' << nx.second+1 << '\n';
    cout << (k+2)+nx.first+1 << ' ' << (k+2)+nx.second+1 << '\n';
  }
  cout << k+2 << ' ' << 2*(k+2) << '\n';
  return 0;
}