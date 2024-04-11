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
    int r=st.size();
    if(n%2!=r%2){r--;}
    cout << r << '\n';
  }
  return 0;
}