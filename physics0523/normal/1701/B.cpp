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
    for(int i=1;i<=n;i++){st.insert(i);}
    cout << "2\n";
    int prev=-1;
    for(int i=0;i<n;i++){
      if(i){cout << " ";}
      if(st.find(2*prev)==st.end()){
        prev=(*st.begin());
      }
      else{
         prev=2*prev;
      }
      cout << prev << '\n';
      st.erase(prev);
    }
    cout << "\n";
  }
  return 0;
}