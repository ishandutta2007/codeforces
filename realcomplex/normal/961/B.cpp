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
  int n,k;
  cin >> n >> k;
  int a[n];
  int t[n];
  for(int i = 0;i < n;i  ++ ){
    cin >> a[i];
  }
  for(int i = 0; i < n;i ++ ){
    cin >> t[i];
  }
  int ans = 0;
  int lose = 0;
  int tot = 0;
  for(int i = 0;i < k; i ++ ){
    lose += (1 - t[i]) * a[i];
  }
  int p = 0;
  for(int i = 0;i < n;i ++ ){
    tot += t[i] * a[i];
  }
  ans = max(ans, tot + lose);
  for(int i = k;i < n;i ++ ){
    if(t[p] == 0)
      lose -= a[p];
    if(t[i] == 0)
      lose += a[i];
    p ++ ;
    ans = max(ans, tot + lose);
  }
  cout << ans << "\n";
  return 0;
}