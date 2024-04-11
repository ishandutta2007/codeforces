#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef double db;

#define fi first
#define se second
#define mp make_pair
#define fastIO std::ios::sync_with_stdio(false);cin.tie(NULL);
#define TEST freopen("in.txt","r",stdin);
#define ones(a) __builtin_popcount(a)

int main(){
  fastIO;
  int n;
  cin >> n;
  int a[n];
  for(int i = 0;i < n;i ++ ){
    cin >> a[i];
  }
  ll sum = 0;
  set<ll> st;
  for(int i = n-1;i >= 0;i -- ){
    sum += a[i];
    st.insert(sum);
  }
  ll xi = 0ll;
  ll ans = 0ll;
  for(int j = 0;j < n;j ++ ){
    st.erase(sum);
    xi += a[j];
    if(st.count(xi)){
      ans = max(ans, xi);
    }
    sum -= a[j];
  }
  cout << ans;
  return 0;
}