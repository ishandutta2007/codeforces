#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;
typedef long double ld;
typedef pair<ld, ld> pdd;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = (int)2e5 + 9;

int cnt[N * 2];

void add(int l, int r){
  cnt[l] ++ ;
  cnt[r + 1] -- ;
}

void solve(){
  int n, k;
  cin >> n >> k;
  for(int i = 0 ; i <= 2 * k ; i ++ )
    cnt[i] = 0;
  vector<int> t(n);
  for(int i = 0 ; i < n; i ++ )
    cin >> t[i];
  int j;
  int y;
  for(int i = 0 ; i < n/2; i ++ ){
    j = n - i - 1;
    y = t[i] + t[j];
    add(0,y-max(t[i],t[j]));
    add(0, y-1);
    add(y+1,2 * k);
    add(y+max(k-t[i],k-t[j])+1,2*k);
  }
  int ans = n;
  for(int i = 1; i <= 2 * k ; i ++ ){
    cnt[i] += cnt[i - 1];
    if(i>1) ans = min(ans, cnt[i]);
  }
  cout << ans << "\n";
}

int main(){
  fastIO;
  int tc;
  cin >> tc;
  for(int i = 1; i <= tc; i ++ ){
    solve();
  }
  return 0;
}