#include<bits/stdc++.h>

using namespace std;

int cvrt(int h,int m){
  return h*60+m;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n,h,m;
    cin >> n >> h >> m;
    m=cvrt(h,m);
    set<int> st;
    for(int i=0;i<n;i++){
      int u,v;
      cin >> u >> v;
      st.insert(cvrt(u,v));
      st.insert(cvrt(u,v)+24*60);
    }
    auto it=st.lower_bound(m);
    int res=(*it)-m;
    cout << res/60 << ' ' << res%60 << "\n";
  }
  return 0;
}