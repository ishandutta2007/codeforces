#include<bits/stdc++.h>
#define llinf 4154118101919364364

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<long long> a(n);
  set<long long> st;
  st.insert(-1ll);
  st.insert(llinf);

  long long sig=0;
  for(auto &nx : a){
    cin >> nx;
    st.insert(nx);
    sig+=nx;
  }
  int q;
  cin >> q;
  while(q>0){
    q--;
    long long x,y;
    cin >> x >> y;
    auto it=st.lower_bound(x);
    long long ma=(*it);
    it--;
    long long mi=(*it);

    long long res=llinf;
    if(ma!=llinf){
      //cout << ma << '\n';
      res=min(res,max(0ll,y-(sig-ma)));
    }
    if(mi!=-1){
      //cout << mi << '\n';
      res=min(res,max(0ll,x-mi)+max(0ll,y-(sig-mi)));
    }
    cout << res << '\n';
  }
  return 0;
}