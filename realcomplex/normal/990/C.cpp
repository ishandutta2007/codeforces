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
#define ones(a) __builtin_popcount(a)

int main(){
  fastIO;
  int n;
  cin >> n;
  string s;
  pii cnt[n];
  ll tt = 0;
  ll ans = 0;
  map<pii, int> cc;
  for(int i = 0;i < n;i ++ ){
    cin >> s;
    cnt[i].fi = 0;
    cnt[i].se = 0;
    for(char x : s){
      if(x == '('){
        cnt[i].fi ++ ;
      }
      else{
        if(cnt[i].fi > 0){
          cnt[i].fi -- ;
        }
        else{
          cnt[i].se ++ ;
        }
      }
    }
    cc[cnt[i]] ++ ;
    if(cnt[i].fi == 0 and cnt[i].se == 0)
      tt ++ ;
  }
  ans += tt * tt;
  for(int i = 0;i < n;i ++ ){
    if(cnt[i].fi + cnt[i].se != 0){
      if(cnt[i].se == 0){
        ans += cc[mp(0, cnt[i].fi)];
      }
    }
  }
  cout << ans << "\n";
  return 0;
}