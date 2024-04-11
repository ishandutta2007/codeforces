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
  scanf("%i", &n);
  ll a[n];
  for(int i = 0;i < n;i ++ )
    scanf("%lli", &a[i]);
  int m;
  scanf("%i", &m);
  ll b[m];
  for(int i = 0;i < m;i ++ ){
    scanf("%lli", &b[i]);
  }
  int r = 0;
  ll s1 = 0, s2 = 0;
  int ans = 0;
  for(int i = 0;i < n;i ++ ){
    s1 += a[i];
    while(s2 < s1 and r < m){
      s2 += b[r++];
    }
    if(s1 == s2){
      ans ++ ;
      s1 = 0;
      s2 = 0;
    }
  }
  if(s1 + s2 > 0 or r != m)
    cout << -1;
  else
    cout << ans;
  return 0;
}