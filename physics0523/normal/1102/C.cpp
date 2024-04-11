#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,x,y;
  cin >> n >> x >> y;
  vector<int> a(n);
  for(auto &nx : a){cin >> nx;}
  if(x>y){cout << n << '\n';return 0;}
  multiset<int> st;
  for(auto &nx : a){
    if(nx<=x){st.insert(nx);}
  }

  int res=0;
  for(int i=0;i<n+5;i++){
    auto it=st.lower_bound(x+1);
    if(it!=st.begin()){
      it--;
      res++;
      st.erase(it);
    }
    if(st.empty()){break;}

    it=st.lower_bound(x+1-y);
    if(it==st.end()){it--;}
    int v=(*it);
    st.erase(it);
    if((v+y)<=x){st.insert(v+y);}
    if(st.empty()){break;}
  }
  cout << res << '\n';
  return 0;
}