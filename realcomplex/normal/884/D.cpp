#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll

typedef long double ld;
typedef pair<int,int> pii;
typedef double db;

#define fi first
#define se second
#define mp make_pair
#define fastIO std::ios::sync_with_stdio(false);cin.tie(NULL);
#define TEST freopen("in.txt","r",stdin);
#define ones(a) __builtin_popcount(a);
#define pq priority_queue

signed main(){
  fastIO;
  int n;
  cin >> n;
  pq<int, vector<int>, greater<int>> a;
  int x;
  for(int i = 0;i < n; i++ ){
    cin >> x;
    a.push(x);
  }
  int ans = 0ll;
  int tot;
  while(a.size() > 1){
    tot = 0ll;
    for(int i = 0;i < 2;i ++ ){
      if(!a.empty()){
        tot += a.top();
        a.pop();
      }
    }
    if(a.size() % 2 == 1){
      tot += a.top();
      a.pop();
    }
    ans += tot;
    a.push(tot);
  }
  cout << ans << "\n";
  return 0;
}