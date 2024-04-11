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
  int t;
  cin >> t;
  while(t>0){
    t--;
    int l;
    string s;
    cin >> l >> s;
    tree<pi,null_type,less<pi>,rb_tree_tag,tree_order_statistics_node_update> tr[3];
    int h=500001;
    tr[0].insert({h,0});
    long long res=0;
    for(int i=0;i<l;i++){
      if(s[i]=='-'){h++;}
      else{h--;}
      res+=tr[h%3].order_of_key({h,1e9});
      tr[h%3].insert({h,i+1});
    }
    cout << res << '\n';
  }
  return 0;
}