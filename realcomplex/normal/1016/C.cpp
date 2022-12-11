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

const int N = (int)3e5 + 9;
ll up[N]; // >V<
ll down[N]; // >^<

ll a[N];
ll b[N];

ll p1[N];
ll p2[N];

int main(){
  fastIO;
  int n;
  cin >> n;
  for(int i = 0;i < n;i ++ )
    cin >> a[i];
  for(int i = 0;i < n;i ++ )
    cin >> b[i];
  up[n - 1] = b[n - 1];
  down[n - 1] = a[n - 1];
  p1[n - 1] = a[n - 1];
  p2[n - 1] = b[n - 1];
  ll ct = 3;
  for(int i = n-2;i >= 0;i -- ){
    up[i] = up[i + 1] + p1[i + 1] + p2[i + 1] + ct * b[i];
    down[i] = down[i + 1] + p1[i + 1] + p2[i + 1] + ct * a[i];
    p1[i] = p1[i + 1] + a[i];
    p2[i] = p2[i + 1] + b[i];
    ct += 2 ;
  }
  ll ans = up[0];
  ll cur = 0;
  ll cnt = 0;
  ll sum;
  for(int i = 0;i < n;i ++ ){
    if(i % 2 == 0){
      cur += a[i] * cnt;
      cur += b[i] * (cnt + 1);
    }
    else{
      cur += a[i] * (cnt + 1);
      cur += b[i] * cnt;
    }
    sum = 0;
    if(i % 2 == 0)
      sum += down[i + 1];
    else
      sum += up[i + 1];
    sum += (p1[i + 1] + p2[i + 1]) * (cnt + 2);
    ans = max(ans, sum + cur);
    cnt += 2;
  }
  cout << ans;
  return 0;
}