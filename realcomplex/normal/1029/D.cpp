#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef long double db;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO std::ios::sync_with_stdio(false);cin.tie(NULL);
#define TEST freopen("in.txt","r",stdin);
#define ones(a) __builtin_popcount(a);
#define pq priority_queue

unordered_map<int, int> cnt[20];

int len(ll a){
  int k = 0;
  do{
    ++k;
    a/=10;
  }while(a > 0);
  return k;
}

int main(){
  fastIO;
  for(int i = 0;i < 20;i ++)
    cnt[i].reserve((int)2e6);
  int n;
  ll k;
  cin >> n >> k;
  ll a[n];
  for(int i = 0; i < n;i ++ ){
    cin >> a[i];
    cnt[len(a[i])][a[i] % k] ++ ;
  }
  ll ans = 0;
  ll rz;
  ll rem;
  for(int i = 0;i < n;i ++ ){
    cnt[len(a[i])][a[i] % k] -- ;
    rz = 1ll;
    for(int j = 1;j <= 10;j ++ ){
      rz *= 10ll;
      rem = ((a[i]%k) * (rz%k))%k;
      rem = (k - rem)%k;
      ans += cnt[j][rem];
    }
    cnt[len(a[i])][a[i] % k] ++ ;
  }
  cout << ans;
  return 0;
}