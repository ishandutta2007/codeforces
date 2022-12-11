#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)3e5 + 99;
const int LOG = 20;
ll x[N];

ll ab(ll y){
  return max(y,-y);
}

int n;
int solve(int lb, int rb, int pos, ll f, int dir){ 
  if(f == 0 || lb == rb)
    return pos;
  int go = pos;
  if(ab(x[pos] - x[pos + dir]) > f){
    if(dir == +1)return solve(lb, pos, pos, f, -dir);
    else return solve(pos, rb, pos, f, -dir);
  }
  int nx;
  for(int i = LOG; i >= 0 ; i -- ){
    nx = go + (1 << i) * dir;
    if(nx < lb || nx > rb) continue;
    if(ab(x[nx] - x[pos]) <= f){
      go = nx;
    }
  }
  nx=go;
  if(nx == pos){
    if(dir==+1) return solve(lb,pos,pos,f,-dir);
    else return solve(pos,rb,pos,f,-dir);
  }
  int t, r;
  if(dir == +1){
    if(lb == pos){
      t = f / ab(x[nx] - x[pos]);
      t %= 2;
      r = f % ab(x[nx] - x[pos]);
      if(t==0)return solve(lb, rb, pos, r, dir);
      else{
        return solve(lb, nx, nx, r, -dir);
      }
    }
    else{
      return solve(lb, nx, nx, f - ab(x[nx] - x[pos]), -dir);
    }
  }
  else{
    if(rb == pos){
      t = f / ab(x[nx] - x[pos]);
      t %= 2;
      r = f % ab(x[nx] - x[pos]);
      if(t==0)return solve(lb, rb, pos, r, dir);
      else{
        return solve(nx, rb, nx, r, -dir);
      }
    }
    else{
      return solve(nx, rb, nx, f - ab(x[nx] - x[pos]), -dir);
    }
  }
}

int ids[N];

int main(){
  fastIO;
  int m;
  cin >> n >> m;
  vector<pii> it(n);
  for(int i = 0; i < n; i ++ ){
    cin >> it[i].fi;
    it[i].se = i;
  }
  sort(it.begin(), it.end());
  for(int i = 0 ; i < n; i ++ ){
    x[i] = it[i].fi;
    ids[it[i].se] = i;
  }
  int a;
  ll ff;
  for(int i = 0 ; i < m ; i ++ ){
    cin >> a >> ff;
    --a;
    a = ids[a];
    cout << it[solve(0, n-1, a, ff, +1)].se + 1 << "\n";
  }
  
  return 0;
}