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

map<int,int>common;

int main(){
  fastIO;
  int n;
  cin >> n;
  int a,x;
  for(int i = 0;i < n;i ++ ){
    cin >> a >> x;
    common[a] = x;
  }
  int m;
  cin >> m;
  for(int i = 0;i < m;i ++ ){
    cin >> a >> x;
    common[a] = max(common[a], x);
  }
  ll ans = 0;
  for(auto x : common){
    ans += x.se;
  }
  cout << ans << "\n";
  return 0;
}