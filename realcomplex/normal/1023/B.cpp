#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef long double ld;
typedef pair<int,int> pii;
typedef double db;

#define int ll

#define fi first
#define se second
#define mp make_pair
#define fastIO std::ios::sync_with_stdio(false);cin.tie(NULL);
#define TEST freopen("in.txt","r",stdin);
#define ones(a) __builtin_popcount(a);
#define pq priority_queue

signed main(){
  fastIO;
  int n, k;
  cin >> n >> k;
  if(k >= 2 * n or n == 1){
    cout << 0;
    return 0;
  }
  n = min(n, k - 1);
  int l = (k + 2)/2;
  cout << max(0ll, n - l + 1);
  return 0;
}