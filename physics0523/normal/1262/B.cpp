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
    vector<int> a(n+1);
    set<int> st;
    for(int i=1;i<=n;i++){
      cin >> a[i];
      st.insert(i);
    }
    bool err=false;
    for(int i=1;i<=n;i++){
      if(i>a[i]){err=true;}
    }
    if(err){cout << "-1\n";continue;}
    for(int i=1;i<=n;i++){
      if(i-1){cout << ' ';}
      if(st.find(a[i])!=st.end()){
        cout << a[i];
        st.erase(a[i]);
      }
      else{
        auto it=st.begin();
        cout << (*it);
        st.erase(it);
      }
    }cout << '\n';
  }
  return 0;
}