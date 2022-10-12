#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n;
    cin >> n;
    vector<int> a(n);
    set<int> st;
    for(int i=0;i<n;i++){cin >> a[i];}
    for(int i=0;i<n;i++){
      for(int j=(i+1);j<n;j++){
        st.insert(abs(a[i]-a[j]));
      }
    }
    cout << st.size() << '\n';
  }
  return 0;
}