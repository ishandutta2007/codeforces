#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = (int)1e5 + 9;
int cnt[N];
vector<vector<int>> pp;

void init(){
  vector<int> p = {0,1,2};
  do{
    pp.push_back(p);
  }while(next_permutation(p.begin(),p.end()));
  for(int i = 1; i < N ; i ++ ){
    for(int j = i ; j < N ; j += i){
      cnt[j] ++ ;
    }
  }
}

int gcd(int x, int y){
  if(x == 0) return y;
  return gcd(y % x, x);
}

void solve(){
  int a[3];
  cin >> a[0] >> a[1] >> a[2];
  int eq = cnt[gcd(gcd(a[0],a[1]),a[2])];
  int two = 0;
  int ovl = 0;
  int par;
  for(int i = 1; i < (1 << 6) ; i ++ ){
    int g[3];
    g[0] = g[1] = g[2] = 0;
    for(int j = 0 ; j < 6 ; j ++ ){
      if((i&(1<<j))){
        for(int t = 0 ;t < 3; t ++ ){
          g[t] = gcd(g[t],a[pp[j][t]]);
        }
      }
    }
    if(__builtin_popcount(i) % 2 == 1) par = +1;
    else par = -1;
    ovl += par * cnt[g[0]] * cnt[g[1]] * cnt[g[2]];
    g[0] = gcd(g[0], g[1]);
    two += par * (cnt[g[0]] * cnt[g[2]] - cnt[gcd(g[0],g[2])]);
  }
  cout << eq + two + (ovl - eq - two * 3)/6 << "\n";
}

int main(){
  fastIO;
  init();
  int tc;
  cin >> tc;
  for(int t = 0 ; t < tc; t ++ ) solve();
  return 0;
}