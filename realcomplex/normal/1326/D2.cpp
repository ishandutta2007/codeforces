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

int n;

bool is_pr(int x){
  for(int y = 2; y * y <= x; y ++ )
    if(x%y==0)
      return false;
  return true;
}

int gen(){
  int x = (int)1e9 + ((int)rng() % (int)1e8 + (int)1e8) % (int)1e8;
  while(!is_pr(x))x++;
  return x;
}

const int AL = 69;
const int MOD = gen();
const int N = (int)1e6 + 10;
int pwr[N];
int f1[N];
int f2[N];
int ch[N];

int add(int x, int y){  
  x += y;
  if(x >= MOD) x-=MOD;
  else if(x < 0) return x + MOD;
  return x;
}

int mult(int x, int y){ 
  return (x * 1ll * y) % MOD;
}

bool palin(int l, int r){
  if(l==r)
    return 1;
  int m1 = (l + r) / 2;
  int m2;
  if((r-l+1)%2==0){
    m2=m1+1;
  }
  else{
    m2=m1+1;
    m1--;
  }
  int c1 = mult(add(f2[l],-f2[m1+1]),pwr[l-1]);
  int c2 = mult(add(f1[r],-f1[m2-1]),pwr[n-r]);
  return (c1==c2);
}

void solve(){
  string t;
  cin >> t;
  n = t.size();
  for(int i = 0 ; i < n; i ++ ){
    ch[i+1]=(t[i]-'a'+1);
  }
  for(int i = 1; i <= n; i ++ ){
    f1[i]=(f1[i-1]+(pwr[i-1]*1ll*ch[i])%MOD)%MOD;
  }
  f2[n+1]=0;
  for(int i = n; i >= 1; i -- ){
    f2[i]=(f2[i+1]+(pwr[n-i]*1ll*ch[i])%MOD)%MOD;
  }
  int x = 1, y = n;
  while(x < y){
    if(ch[x]==ch[y])
      x++,y--;
    else 
      break;
  }
  int lf = 0, len = 0;
  for(int t = x; t <= y; t ++ ){
    if(palin(x,t)){
      if(len<(t-x+1)){
        len=t-x+1;
        lf=x;
      }
    }
    if(palin(t,y)){
      if(len<(y-t+1)){
        len=y-t+1;
        lf=t;
      }
    }
  }
  for(int k = 1; k < x; k ++ )
    cout << char(ch[k]+'a'-1);
  for(int p = 0 ; p < len ; p ++ )
    cout << char(ch[lf+p]+'a'-1);
  for(int k = x-1; k >= 1; k -- )
    cout << char(ch[k]+'a'-1);
  cout << "\n";
}

int main(){
  fastIO;
  pwr[0]=1;
  for(int i = 1; i < N ; i ++ )
    pwr[i]=(pwr[i-1]*1ll*AL)%MOD;
  int tc;
  cin >> tc;
  for(int t = 0 ;t < tc; t ++ ) solve();
  return 0;
}