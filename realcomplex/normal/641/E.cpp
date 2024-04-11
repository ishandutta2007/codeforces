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

const int MOD = (int)1e9 + 9;

unordered_map<int, unordered_map<int,int>> segtree;

int main(){
  fastIO;
  int q;
  cin >> q;
  int a, t, x;
  int lf,rf,ans;
  for(int i = 0;i < q;i ++ ){
    cin >> a >> t >> x;
    if(a != 3){
      t += MOD;
      if(a == 1)segtree[x][t] ++ ;
      if(a == 2)segtree[x][t] -- ;
      t/=2;
      while(t >= 1){
        segtree[x][t] = segtree[x][t * 2] + segtree[x][t * 2 + 1];
        t /= 2;
      }
    }
    else{
      lf = 1, rf = t;
      lf += MOD;
      rf += MOD;
      ans = 0;
      while(lf <= rf){
        if(lf % 2 == 1){
          ans += segtree[x][lf];
          lf ++ ;
        }
        if(rf % 2 == 0){
          ans += segtree[x][rf];
          rf -- ;
        }
        lf /= 2;
        rf /= 2;
      }
      cout << ans << "\n";
    }
  }
  return 0;
}