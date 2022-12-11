#pragma optimize ("O3")
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO std::ios::sync_with_stdio(false);cin.tie(NULL);
#define TEST freopen("in.txt","r",stdin);
#define _ones(a) __builtin_popcount(a)

int main(){
  fastIO;
  int n,k;
  cin >> n >> k;
  ll powr[n];
  ll coins[n];
  pii pwr[n];
  for(int i = 0;i < n;i ++) {
    cin >> powr[i];
    pwr[i].fi = powr[i];
    pwr[i].se = i;
  }
  sort(pwr, pwr + n);
  for(int j = 0;j < n;j ++ ){
    cin >> coins[j];
  }
  ll ans[n];
  multiset<ll>values;
  int ix;
  ll sum = 0;
  for(int i = 0;i < n;i ++ ){
    if(i == 0){
      ix = pwr[i].se;
      ans[ix] = coins[ix];
      values.insert(coins[ix]);
      sum += coins[ix];
    }
    else{
      ix = pwr[i].se;
      sum += coins[ix];
      if(values.size() > k){
        auto it = values.begin();
        sum -= (*it);
        values.erase(it);
      }
      values.insert(coins[ix]);
      ans[ix] = sum;
    }
  }
  for(int i = 0;i < n;i ++)
    cout << ans[i] << " ";
  return 0;
}