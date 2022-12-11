#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<ll,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ab(x) ((x) < 0 ? -(x) : (x))
#define all(x) ((x).begin(),(x).end())
#define len(x) ((ll)(x).size())

int main(){
  fastIO;
  int n;
  cin >> n;
  ll p[n];
  char t[n];
  vector<int>pp;
  for(int i = 0;i < n; i ++ ){
    cin >> p[i] >> t[i];
    if(t[i] == 'P')
      pp.push_back(i);
  }
  if(pp.empty()){
    ll ans = 0;
    ll las = (ll)-1e18;
    for(int i = 0;i < n;i ++ ){
      if(t[i] == 'R'){
        if(las != (ll)-1e18)
          ans += p[i] - las;
        las = p[i];
      }
    }
    las = (ll)-1e18;
    for(int i = 0;i < n;i ++ ){
      if(t[i] == 'B'){
        if(las != (ll)-1e18)  
          ans += p[i] - las;
        las = p[i];
      }
    }
    cout << ans << "\n";
    return 0;
  }
  ll ans = 0;
  ll v1, v2;
  vector<ll> s1, s2;
  int lp,rp;
  ll len;
  ll tt;
  for(int i = 1;i < (int)pp.size(); i ++ ){
    lp = pp[i - 1];
    rp = pp[i];
    for(int j = lp + 1;j < rp;j ++ ){
      if(t[j] == 'R')
        s1.push_back(p[j]);
      else
        s2.push_back(p[j]);
    }
    len = 2*(p[rp] - p[lp]);
    tt = p[rp] - p[lp];
    v1 = 0;
    v2 = 0;
    if(!s1.empty()){
      v1 = max(s1[0] - p[lp],p[rp] - s1.back());
      for(int i = 1;i < len(s1); i ++ ) 
        v1 = max(v1, s1[i] - s1[i - 1]);
      tt += (p[rp] - p[lp]) - v1;
    }
    if(!s2.empty()){
      v2 = max(s2[0] - p[lp],p[rp] - s2.back());
      for(int i = 1;i < len(s2); i ++ )
        v2 = max(v2, s2[i] - s2[i - 1]);
      tt += (p[rp] - p[lp]) - v2;
    }
    len = min(len , tt);
    ans += len;
    s1.clear();
    s2.clear();
  }
  ll l1 = p[pp[0]], l2 = l1;
  for(int i = pp[0] - 1;i >= 0;i -- ){
    if(t[i] == 'R'){
      ans += l1 - p[i];
      l1 = p[i];
    }
    else{
      ans += l2 - p[i];
      l2 = p[i];
    }
  }
  l1 = p[pp[len(pp) - 1]],l2 = l1;
  for(int i = pp[len(pp) - 1]; i < n;i ++ ){
    if(t[i] == 'R'){
      ans += p[i] - l1;
      l1 = p[i];
    }
    else{
      ans += p[i] - l2;
      l2 = p[i];
    }
  }
  cout << ans;
  return 0;
}