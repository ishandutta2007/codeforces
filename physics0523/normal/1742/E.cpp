#include<bits/stdc++.h>

using namespace std;
using pl=pair<long long,long long>;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    long long n,k;
    cin >> n >> k;
    set<pl> st;
    long long cmax=0,csum=0;
    for(long long i=0;i<n;i++){
      long long v;
      cin >> v;
      if(cmax<v){
        st.insert({cmax,csum});
        cmax=v;
      }
      csum+=v;
    }
    st.insert({cmax,csum});
    for(long long i=0;i<k;i++){
      if(i){cout << " ";}
      long long v;
      cin >> v;
      auto it=st.lower_bound({v,8e18});
      it--;
      cout << (*it).second;
    }cout << "\n";
  }
  return 0;
}