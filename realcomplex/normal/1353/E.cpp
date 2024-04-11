#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

void solve(){
  int n, k;
  cin >> n >> k;
  int ans = n;
  vector<char> s(n);
  int tot = 0;
  for(int i = 0 ; i < n ; i ++ ){
    cin >> s[i];
    tot += (s[i] == '1');
  }
  for(int mod = 0 ;mod < k; mod ++ ){
    int cur = n;
    int ovl = 0;
    for(int j = mod; j < n; j += k){
      ovl += (s[j] == '1');
    }
    int pf = 0;
    int ret = n;
    for(int j = mod; j < n; j += k){
      cur = min(cur + (s[j] != '1'), pf + (s[j] != '1'));
      pf += (s[j] == '1');
      ret = min(ret, cur+ovl-pf);
    }
    ret = min(ret, ovl);
    ans = min(ans, ret + tot - ovl);
  }
  cout << ans << "\n";
}

int main(){
  fastIO;
  int tc;
  cin >> tc;
  for(int t = 0 ;t < tc;t ++ )
    solve();
  return 0;
}