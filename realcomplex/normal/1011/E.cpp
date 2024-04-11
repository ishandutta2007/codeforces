#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef long double db;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO std::ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define TEST freopen("in.txt","r",stdin);
#define ones(a) __builtin_popcount(a);
#define pq priority_queue

int main(){
  fastIO;
  int n;
  ll k;
  scanf("%i %lli", &n, &k);
  int g;
  scanf("%i", &g);
  int nx;
  for(int i = 1; i < n;i ++ ){
    scanf("%i", &nx);
    g = __gcd(nx, g);
  }
  set<int> ans;
  for(ll i = 0;i < k; i ++ ){
    ans.insert((1ll * i * g) % k);
  }
  cout << ans.size() << "\n";
  for(auto x : ans)
    cout << x << " ";
  return 0;
}