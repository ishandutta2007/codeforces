#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 5010;
const int MOD = (int)1e9 + 7;
int a[N];
int pos[N];
vector<int> pp[N];
vector<int> T[N];

int main(){
  fastIO;
  int n, m;
  cin >> n >> m;
  int x;
  for(int i = 1; i <= n ; i ++ ){
    cin >> a[i];
    pos[i]=pp[a[i]].size();
    pp[a[i]].push_back(i);
  }
  int f, h;
  for(int i = 1; i <= m ; i ++ ){
    cin >> f >> h;
    T[f].push_back(h);
  }
  int fl, fe, fr;
  int ac = 0, wy = 1;
  int cur, ww;
  int ii, jj;
  int sum;
  for(int cut = 1; cut <= n; cut ++ ){
    cur = 0, ww = 1;
    fl = 0, fe = 0, fr = 0;
    for(auto x : T[a[cut]]){
      if(x > pp[a[cut]].size()) continue;
      if(x - 1 == pos[cut] && pp[a[cut]][pp[a[cut]].size() - x] > cut){
        fe ++ ;
      }
      else if(x - 1 == pos[cut]){
        fl ++ ;
      }
      else if(pp[a[cut]][pp[a[cut]].size() - x] > cut){
        fr ++ ;
      }
    }
    sum = fl * fe;
    sum += fe * fr;
    sum += fl * fr;
    sum += (fe * (fe - 1));
    if(sum > 0){
      cur += 2;
      ww = (ww * 1ll * sum) % MOD;
    }
    else{
      sum = fl + fe;
      if(sum > 0){
        cur ++ ;
        ww = (ww * 1ll * sum) % MOD;
      }
      else{
        ww = 0;
      }
    }
    for(int j = 1; j <= n; j ++ ){
      if(j == a[cut]) continue;
      fl = 0, fe = 0, fr = 0;
      sum = 0;
      for(auto x : T[j]){
        if(x > pp[j].size()) continue;
        ii = pp[j][x - 1];
        jj = pp[j][(int)pp[j].size() - x];
        if(ii <= cut && jj > cut)
          fe ++ ;
        else if(ii <= cut)
          fl ++ ;
        else if(jj > cut)
          fr ++ ;
      }
      sum = fl * fe;
      sum += fe * fr;
      sum += fl * fr;
      sum += (fe * (fe - 1));
      if(sum > 0){
        cur += 2;
        ww = (ww * 1ll * sum) % MOD;
      }
      else{
        sum = fl + 2ll * fe + fr;
        if(sum > 0){
          cur ++ ;
          ww = (ww * 1ll * sum) % MOD;
        }
      }
    }
    if(ww == 0) continue;
    if(cur > ac){
      ac = cur;
      wy = ww;
    }
    else if(cur == ac){
      wy = (wy + ww) % MOD;
    }
  }
  cur = 0;
  ww = 1;
  for(int i = 1; i <= n; i ++ ){
    fr = 0;
    for(auto x : T[i]){
      if(x <= pp[i].size()){
        fr ++ ;
      }
    }
    if(fr > 0){
      cur ++ ;
      ww = (ww * 1ll * fr) % MOD;
    }
  }
  if(cur > ac){
    ac = cur;
    wy = ww;
  }
  else if(cur == ac){
    wy = (wy + ww) % MOD;
  }
  if(ac==0)wy=1;
  cout << ac << " " << wy << "\n";
  return 0;
}