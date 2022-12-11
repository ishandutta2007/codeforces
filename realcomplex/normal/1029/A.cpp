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

int main(){
  fastIO;
  int n, k;
  cin >> n >> k;
  string t;
  cin >> t;
  int mx = 0;
  for(int i = 1; i < n;i ++ ){
    if(t.substr(0, i) == t.substr(n-i, i))
      mx = max(mx, i);
  }
  int rem = 0;
  for(int i = 0;i < k;i ++ ){
    for(int j = rem;j < n;j ++ )
      cout << t[j];
    rem = mx;
  }
  return 0;
}