#include<bits/stdc++.h>
using namespace std;
using pi=pair<int,int>;
using lin=pair<int,pi>;
using pl=pair<long long,long long>;

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/tag_and_trait.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

pl solve(vector<lin> &a,vector<lin> &b){
  ordered_set tr;
  pl res={0,0};
  vector<lin> q;
  for(auto &nx : a){
    q.push_back({3*nx.first+1,nx.second});
  }
  for(auto &nx : b){
    q.push_back({3*nx.second.first,{nx.first,0}});
    q.push_back({3*nx.second.second+2,{nx.first,0}});
  }
  sort(q.begin(),q.end());
  for(auto &nx : q){
    if(nx.first%3==0){tr.insert(nx.second.first);}
    if(nx.first%3==1){
      long long dlt=tr.order_of_key(nx.second.second+1);
      dlt-=tr.order_of_key(nx.second.first);
      res.first+=max(0ll,dlt);
      res.second+=max(0ll,dlt-1);
    }
    if(nx.first%3==2){tr.erase(nx.second.first);}
  }
  return res;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,m;
  cin >> n >> m;
  vector<lin> a(n),b(m);
  for(auto &nx : a){
    cin >> nx.first;
    cin >> nx.second.first;
    cin >> nx.second.second;
  }
  a.push_back({0,{0,1000000}});
  a.push_back({1000000,{0,1000000}});
  for(auto &nx : b){
    cin >> nx.first;
    cin >> nx.second.first;
    cin >> nx.second.second;
  }
  b.push_back({0,{0,1000000}});
  b.push_back({1000000,{0,1000000}});

  pl s1=solve(a,b);
  pl s2=solve(b,a);
  long long v=s1.first; // ==s2.first;
  long long e=s1.second+s2.second;
  // v-e+f = 2 (Euler's polyhedron theorem)
  //cout << v << ' ' << e << '\n';
  long long f=e-v+2;
  cout << f-1 << '\n';
  return 0;
}