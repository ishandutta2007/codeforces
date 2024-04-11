#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)1e6 + 9;
int cnt[N];

int main(){
  fastIO;
  int n;
  cin >> n;
  vector<int> t[n];
  int a, k;
  int mx, lw;
  bool ok[n];
  int tt = 0;
  for(int i = 0 ; i < n ; i ++ ){
    cin >> k;
    ok[i] = false;
    mx = 0, lw = N + 5;
    for(int j = 0 ; j < k ; j ++ ){
      cin >> a;
      t[i].push_back(a);
      if(a > lw){
        ok[i] = true;
      }
      mx = max(mx, a);
      lw = min(lw, a);
    }
    tt += ok[i];
    if(!ok[i]){
      cnt[mx] ++ ;
    }
  }
  ll res = 0;
  res += tt * 1ll * tt;
  res += tt * 2ll * (n - tt);
  for(int i = N - 1; i >= 0 ; i -- )
    cnt[i] += cnt[i + 1];
  for(int i = 0 ; i < n ; i ++ ){
    if(!ok[i]){
      lw = N + 5;
      for(auto x : t[i]){
        lw = min(lw, x);
      }
      res += cnt[lw + 1];
    }
  }
  cout << res;
  return 0;
}