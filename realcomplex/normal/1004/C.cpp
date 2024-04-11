#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef double db;

#define fi first
#define se second
#define mp make_pair
#define fastIO std::ios::sync_with_stdio(false);cin.tie(NULL);
#define TEST freopen("in.txt","r",stdin);
#define ones(a) __builtin_popcount(a)

const int N = (int)1e5 + 9;
int cnt1[N];
int cnt2[N];

int main(){
  fastIO;
  int n;
  cin >> n;
  int a[n];
  int dist = 0;
  for(int i = 0; i < n;i ++ ){
    cin >> a[i];
    cnt2[a[i]] ++ ;
    if(cnt2[a[i]] == 1)
      dist ++ ;
  }
  ll ans = 0;
  for(int i = 0;i < n;i ++ ){
    cnt2[a[i]] -- ;
    if(cnt2[a[i]] == 0)
      dist -- ;
    if(cnt1[a[i]] != 0)
      continue;
    ans += dist;
    cnt1[a[i]] ++ ;
  }
  cout << ans;
  return 0;
}