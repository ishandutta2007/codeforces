#include<bits/stdc++.h>

using namespace std;
using pi=pair<int,int>;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int cases;
  cin >> cases;
  while(cases>0){
    cases--;
    int n,q;
    cin >> n >> q;
    vector<int> a(n);
    for(auto &nx : a){cin >> nx;}
    set<pi> st;
    int cmi=2e9;
    for(int i=0;i<n;i++){
      if(cmi>a[i]){
        cmi=a[i];
        st.insert({i,cmi});
      }
    }

    for(int qu=0;qu<q;qu++){
      if(qu){cout << ' ';}
      int k,d;
      cin >> k >> d;
      k--;
      a[k]-=d;
      auto it=st.lower_bound({k+1,-1e9});
      it--;
      if((*it).second>a[k]){
        pi cur={k,a[k]};
        while(1){
          auto cit=st.lower_bound(cur);
          if(cit==st.end()){break;}
          if(a[k]>(*cit).second){break;}
          st.erase(cit);
        }
        st.insert(cur);
      }
      cout << st.size();
    }cout << '\n';
  }
  return 0;
}