#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)3e4 + 9;
vector<int> fac[N];

void precalc(){
  for(int i = 1; i < N; i ++ ){
    for(int j = 1; j * j <= i ; j ++ ){
      if(i % j == 0){
        fac[i].push_back(j);
        if(j * j != i)
          fac[i].push_back(i/j);
      }
    }
    sort(fac[i].begin(), fac[i].end());
  }
}

void solve(){
  int a, b, c;
  cin >> a >> b >> c;
  int ans = (int)1e9;
  int cur = 0;
  int ad;
  int ib,ia,ic;
  int la,lb,lc;
  for(int x = 1; x <= (int)2e4 + 1; x ++ ){
    cur = 0;
    cur += abs(b - x);
    cur += min(c%x,(x-(c%x))%x);
    if(c%x <= x - (c % x)){
      ic = c - c%x;
    }
    else{
      ic = c+((x-(c%x))%x);
    }
    ad = (int)1e9;
    ib=x;
    for(auto y : fac[x]){
      if(abs(y-a) < ad ){
        ad = abs(y-a);
        ia = y;
      }
    }
    cur += ad;
    if(ans > cur){
      ans = cur;
      la = ia;
      lb = ib;
      lc = ic;
    }
  }
  cout << ans << "\n" << la << " " << lb << " " << lc << "\n"; 
}

int main(){
  fastIO;
  precalc();
  int tc;
  cin >> tc;
  for(int t = 0; t < tc ; t ++ ){
    solve();
  }
  return 0;
}