#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = (int)2e5 + 9;
ll euclid(ll a, ll b, ll &p, ll &q){
  if(b == 0){
    p = 1;
    q = 0;
    return a;
  }
  ll g = euclid(b, a % b, q, p);
  ll n = a/b;
  q -= p * n;
  return g;
}

vector<int> w[N];
int dp[N];
int las[N];
bool ban[N];
vector<int> pp;

int main(){
  fastIO;
  int n, m;
  cin >> n >> m;
  int x;
  for(int i = 0 ; i < n;  i ++ ){
    cin >> x;
    ban[x]=true;
  }
  ll p, q;
  for(int i = 0 ; i < m ; i ++ ){
    if(!ban[i])w[euclid(i, m, p, q)].push_back(i);
  }
  for(int i = 1; i <= m ; i ++ ){
    if(m % i == 0) pp.push_back(i);
    dp[i] = -1;
    las[i] = -1;
  }
  dp[1] = w[1].size();
  for(int i = 2; i <= m ; i ++ ){
    if(m % i != 0) continue;
    for(auto x : pp){
      if((i % x == 0 && x < i)){
        if(dp[i] < dp[x] + (int)w[i].size()){
          dp[i] = dp[x] + (int)w[i].size();
          las[i] = x;
        }
      }
    }
  }
  vector<int> pref;
  int mx = 1;
  for(int i = 2; i <= m ; i ++ ){
    if(dp[i] > dp[mx]){
      mx = i;
    }
  }
  while(1){
    for(auto x : w[mx]){
      pref.push_back(x);
    }
    if(mx == 1) break;
    mx = las[mx];
  }
  ll g;
  reverse(pref.begin(), pref.end());
  vector<int> ans = {pref[0]};
  for(int i = 0 ; i + 1 < pref.size(); i ++ ){
    g = euclid(pref[i], m, p, q);
    p %= m;
    if(p < 0) p += m;
    p *= (pref[i+1]/g);
    p %= m;
    ans.push_back(p);
  }
  cout << ans.size() << "\n";
  for(auto x : ans) cout << x << " ";
  return 0;
}