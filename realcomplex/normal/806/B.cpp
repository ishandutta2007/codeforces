#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef long double ld;
typedef pair<ld, ld> pdd;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int M = 10000;
const int N = 120;
int a[N][5];
int c[5];

bool check(int a, int b, int p, int q){ 
  return a*q > b*p;
}

int main(){
  fastIO;
  int n;
  cin >> n;
  for(int i = 1; i <= n; i ++ ){
    for(int j = 0 ; j < 5; j ++ ){
      cin >> a[i][j];
    }
  }
  int cur;
  int ca, cb;
  int p;
  for(int x = 0 ; x < M ; x ++ ){
    cur = x + n;
    ca = 0;
    cb = 0;
    for(int j = 0 ;j < 5; j ++ ){
      c[j] = 0;
      for(int i = 1; i <= n; i ++ ){
        if(a[i][j] != -1) c[j] ++ ;
      }
      if(a[1][j] == -1) continue;
      if(a[2][j] == -1) continue;
      if(a[1][j] > a[2][j]){
        c[j] += x;
      }
    }
    
    for(int j = 0 ; j < 5; j ++ ){
      if(check(c[j],cur,1,2)){
        p = 500;
      }
      else if(check(c[j],cur,1,4)){
        p = 1000;
      }
      else if(check(c[j],cur,1,8)){
        p = 1500;
      }
      else if(check(c[j],cur,1,16)){
        p = 2000;
      }
      else if(check(c[j],cur,1,32)){
        p = 2500;
      }
      else{
        p = 3000;
      }
      if(a[1][j] != -1) ca += p-(p/250)*a[1][j];
      if(a[2][j] != -1) cb += p-(p/250)*a[2][j];
    }
    if(ca > cb){
      cout << x << "\n";
      return 0;
    }
  }
  cout << -1 << "\n";
  return 0;
}