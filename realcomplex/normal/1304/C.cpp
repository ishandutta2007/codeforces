#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

void solve(){
  int n, m;
  cin >> n >> m;
  int l = m, r=m;
  int las=0,ti,low,high;
  int nl, nr;
  bool ans = true;
  for(int i = 0 ; i < n; i ++ ){
    cin >> ti >> low >> high;
    if(!ans)continue;
    nl = l - (ti - las);
    nr = r + (ti - las);
    l = max(nl, low);
    r = min(nr, high);
    if(l > r){
      ans=false;
    }
    las = ti;
  }
  if(ans)
    cout << "YES\n";
  else
    cout << "NO\n";
}

int main(){
  fastIO;
  int tc;
  cin >> tc;
  for(int i = 0 ; i < tc; i ++ )
    solve();
  return 0;
}