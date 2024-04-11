#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef double db;

#define fi first
#define se second
#define mp make_pair
#define fastIO std::ios::sync_with_stdio(false);cin.tie(NULL);
#define TEST freopen("in.txt","r",stdin);
#define ones(a) __builtin_popcount(a)

const int N = (int)2e5 + 9;

map<int, ll> cnt;

int main(){
  fastIO;
  int n,m;
  cin >> n >> m;
  int p[n];
  int x = 0;
  for(int i = 0;i < n;i ++ ){
    cin >> p[i];
    if(p[i] == m)
      x = i;
  }
  int larg = 0, sm = 0;
  ll ans = 1LL;
  for(int i = x - 1;i >= 0;i -- ){
    if(p[i] < m)
      sm ++ ;
    else
      larg ++ ;
    cnt[larg - sm] ++ ;
    if(larg - sm == 0 or larg - sm == 1)
      ans ++ ;
  }
  larg = 0, sm = 0;
  for(int i = x + 1;i < n;i ++ ){
    if(p[i] < m)
      sm ++ ;
    else
      larg ++ ;
    if(larg - sm == 0 or larg - sm == 1)
      ans ++ ;
    ans += cnt[sm - larg]; // odd case
    ans += cnt[sm - larg + 1]; // even case
  }
  cout << ans << "\n";
  return 0;
}