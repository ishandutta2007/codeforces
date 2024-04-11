#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/tag_and_trait.hpp>

using namespace __gnu_pbds;
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    long long n,res=0;
    cin >> n;
    vector<long long> a(n),b(n);
    for(auto &nx : a){cin >> nx;}
    for(auto &nx : b){cin >> nx;}
    multiset<long long> st;
    for(int i=0;i<n;i++){st.insert(b[i]-a[i]);}
    while(st.size()>=2){
      auto ia=st.begin();
      long long va=(*ia);
      st.erase(ia);

      auto ib=st.lower_bound(-va);
      if(ib==st.end()){continue;}
      res++;
      st.erase(ib);
    }
    cout << res << "\n";
  }
  return 0;
}