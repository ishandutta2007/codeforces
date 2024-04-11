#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n,x;
    set<int> st;
    cin >> n >> x;
    for(int i=0;i<n;i++){
      int a;
      cin >> a;
      st.insert(a);
    }
    int lim=st.size()+x;
    for(int i=1;;i++){
      st.insert(i);
      if(st.size()==lim+1){
        cout << i-1 << '\n';
        break;
      }
    }
  }
}