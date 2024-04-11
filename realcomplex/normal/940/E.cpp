#pragma optimize ("O3")
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO std::ios::sync_with_stdio(false);cin.tie(NULL);
#define TEST freopen("in.txt","r",stdin);
#define _ones(a) __builtin_popcount(a)

const int N = (int)1e5 + 9;
ll dp[N];
ll a[N];
ll pref[N];

ll ask(int l, int r){
  return pref[r] - pref[l-1];
}

int main(){
  fastIO;
  int n, c;
  cin >> n >> c;
  for(int i = 1;i <= n;i ++ ){
    cin >> a[i];
    pref[i] = a[i] + pref[i - 1];
    dp[i] = a[i] + dp[i - 1];
  }
  multiset<ll> vv;
  for(int i = 1;i <= n;i ++ ){
    vv.insert(a[i]);
    if(vv.size() > c){
      vv.erase(vv.find(a[i - c]));
    }
    if(i >= c){
      dp[i] = min(dp[i], dp[i-c] + ask(i-c+1, i) - (*vv.begin()));
      dp[i] = min(dp[i], dp[i-1] + a[i]);
    }
  }
  cout << dp[n];
  return 0;
}