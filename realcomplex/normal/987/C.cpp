#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int,int> pii;
typedef double db;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define TEST freopen("in.txt","r",stdin);
#define ab(a) ((a < 0) ? (-(a)) : (a))
#define all(a) a.begin(), a.end()

int main(){
  fastIO;
  int n;
  cin >> n;
  int sz[n];
  int cost[n];
  for(int i = 0;i < n;i ++ )
    cin >> sz[i];
  for(int i = 0;i < n;i ++ )
    cin >> cost[i];
  int best[n];
  for(int j = 0;j < n;j ++ )
    best[j] = (int)1e9 + 9;
  for(int i = 0;i < n;i ++ ){
    for(int j = i+1;j < n;j ++ ){
      if(sz[i] < sz[j])
        best[j] = min(best[j], cost[i] + cost[j]);
    }
  }
  int ans = (int)1e9 + 9;
  for(int i = 1;i < n;i ++ ){
    for(int j = i + 1;j < n;j ++ ){
      if(sz[i] < sz[j])
        ans = min(ans, best[i] + cost[j]);
    }
  }
  cout << (ans == (int)1e9 + 9 ? -1 : ans);
  return 0;
}