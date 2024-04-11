#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/tag_and_trait.hpp>
using namespace __gnu_pbds;

using namespace std;
using pl=pair<long long,long long>;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  long long n,m;
  cin >> n >> m;
  map<long long,vector<long long>> mp;
  set<long long> st;
  vector<long long> t(n),s(n),f(n);
  for(long long i=0;i<n;i++){
    cin >> t[i] >> s[i] >> f[i];
    mp[t[i]].push_back(i);
    st.insert(t[i]);
  }
  st.insert(8e18);
  vector<long long> res(n);
  long long ct=(*st.begin());
  long long rem=n,cf=1;
  tree<pl,null_type,less<pl>,rb_tree_tag,tree_order_statistics_node_update> tr;
  while(rem>0){
    for(auto &nx : mp[ct]){
      tr.insert({s[nx],nx});
    }
    while(1){
      auto it=tr.lower_bound({cf,-1});
      if(it==tr.end()){break;}
      if((*it).first!=cf){break;}
      if((*it).second<n){
        tr.insert({f[(*it).second],(*it).second+n});
      }
      else{
        res[(*it).second-n]=ct;
        rem--;
      }
      tr.erase(it);
    }
    if(rem==0){break;}
    int down=tr.order_of_key({cf,-1});
    int up=tr.size()-tr.order_of_key({cf+1,-1});
    if(down==0 && up==0){
      ct=(*st.lower_bound(ct+1));
    }
    else{
      long long merg=(*st.lower_bound(ct+1))-ct;
      if(down<=up){
        auto it=tr.lower_bound({cf+1,-1});
        merg=min(merg,(*it).first-cf);
        cf+=merg;
      }
      else{
        auto it=tr.lower_bound({cf,-1});it--;
        merg=min(merg,cf-(*it).first);
        cf-=merg;
      }
      ct+=merg;
    }
  }
  for(auto &nx : res){cout << nx << '\n';}
  return 0;
}