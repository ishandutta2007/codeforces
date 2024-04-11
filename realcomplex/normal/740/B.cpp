#pragma optimize ("O3")
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
#define len(x) ((int)(x).size())

int main(){
  fastIO;
  int n,m;
  cin >> n >> m;
  int a[n];
  for(int i = 0;i < n;i ++ )
    cin >> a[i];
  int l,r;
  int cur;
  int ans = 0;
  for(int i = 0;i <m ;i ++ ){
    cin >> l >> r;
    l -- ;
    r -- ;
    cur = 0;
    for(int j = l ;j <= r;j ++ ){
      cur += a[j];
    }
    ans = max(ans, ans + cur);
  }
  cout << ans;
  return 0;
}