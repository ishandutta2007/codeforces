#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = (int)1e6 + 9;
int cnt[N];
int qq[N];
int t[N];
int mx;
int low=-1;
int n;

void check(int nn, int mm, int x, int y){
  for(int i = 0 ; i <= n; i ++ )
    qq[i] = 0;
  for(int i = 1; i <= nn; i ++ ){
    for(int j = 1; j <= mm ; j ++ ){
      qq[abs(i-x) + abs(j-y)] ++; 
    }
  }
  for(int i = 0 ; i <= n; i ++ ){
    if(qq[i] != cnt[i]) return;
  }
  cout << nn << " " << mm << "\n" << x << " " << y << "\n";
  exit(0);
}

void can(int nn, int mm){ 
  int x=low,y=-1;
  y = mx + 2 - x;
  if(x >= 1 && y >= 1 && x <= nn && y <= mm){
    check(nn,mm,x,y);
  }
  y = nn + mm - x - mx;
  if(x >= 1 && y >= 1 && x <= nn && y <= mm){
    check(nn, mm, x, y);
  }
  y = x - 1 + mm - mx;
  if(x >= 1 && y >= 1 && x <= nn && y <= mm){
    check(nn, mm, x, y);
  }
  y = mx + 1 - nn + x;
  if(x >= 1 && y >= 1 && x <= nn && y <= mm){
    check(nn, mm, x, y);
  }
}

int main(){
  fastIO;
  cin >> n;
  for(int i = 1; i <= n; i ++ ){
    cin >> t[i];
    mx = max(mx, t[i]);
    cnt[t[i]] ++ ;
  }
  if(cnt[0] != 1){
    cout << "-1\n";
    return 0;
  }
  for(int i = 1; i <= n; i ++ ){
    if(i * 4 != cnt[i]){
      low = i;
      break;
    }
  }
  for(int i = 1; i * i <= n; i ++ ){
    if(n % i == 0){
      can(i,n/i);
      if(i * i != n) can(n/i,i);
    }
  }
  cout << "-1\n";
  return 0;
}