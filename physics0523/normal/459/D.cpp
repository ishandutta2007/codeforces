#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/tag_and_trait.hpp>
using namespace __gnu_pbds;
using namespace std;
using pi=pair<int,int>;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n);
  for(auto &nx : a){cin >> nx;}

  map<int,int> mp;
  vector<int> l(n),r(n);
  for(int i=0;i<n;i++){
    mp[a[i]]++;
    l[i]=mp[a[i]];
  }
  mp.clear();
  for(int i=n-1;i>=0;i--){
    mp[a[i]]++;
    r[i]=mp[a[i]];
  }

  // for(int i=0;i<n;i++){
  //   if(i){cout << ' ';}
  //   cout << l[i];
  // }cout << '\n';
  // for(int i=0;i<n;i++){
  //   if(i){cout << ' ';}
  //   cout << r[i];
  // }cout << '\n';

  tree<pi,null_type,less<pi>,rb_tree_tag,tree_order_statistics_node_update> tr;
  for(int i=0;i<n;i++){
    tr.insert({r[i],i});
  }
  tr.insert({2e9,2e9});
  long long res=0;
  for(int i=0;i<n;i++){
    tr.erase({r[i],i});
    res+=tr.order_of_key({l[i],-1});
  }

  cout << res << '\n';

  return 0;
}