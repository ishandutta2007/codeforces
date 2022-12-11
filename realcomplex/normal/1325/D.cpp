#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int LOG = 62;
ll c[LOG];

int main(){ 
  fastIO;
  ll u, v;
  cin >> u >> v;
  if(u > v){
    cout << "-1\n";
    return 0;
  }
  ll d = v - u;
  if(d % 2 == 1){
    cout << -1 << "\n";
    return 0;
  }
  for(int i = 1 ; i < LOG ; i ++ ){
    if((d & (1ll << i))){
      c[i-1] += 2;
    }
  }
  for(int i = 0 ; i < LOG; i ++ ){
    if((u & (1ll << i))){
      c[i] ++ ;
    }
  }
  vector<ll> r(3);
  for(int i = 0 ; i < LOG; i ++ ){
    for(int j = 0 ; j < c[i] ; j ++ ){
      r[j] |= (1ll << i);
    }
  }
  while(!r.empty() && r.back() == 0){
    r.pop_back();
  }
  cout << r.size() << "\n";
  for(auto x : r)
    cout << x << " ";
  return 0;
}