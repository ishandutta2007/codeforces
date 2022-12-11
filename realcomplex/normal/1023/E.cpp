#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef long double ld;
typedef pair<int,int> pii;
typedef double db;

#define fi first
#define se second
#define mp make_pair
#define fastIO std::ios::sync_with_stdio(false);cin.tie(NULL);
#define TEST freopen("in.txt","r",stdin);
#define ones(a) __builtin_popcount(a);
#define pq priority_queue

int n;
int ask(int x1, int y1, int x2, int y2){
  if(x1 <= 0 or y1 <= 0 or x2 > n or y2 > n)
    return false;
  cout << "? " << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
  string rez;
  cin >> rez;
  return rez == "YES";
}

int main(){
  fastIO;
  cin >> n;
  int moves = n * 2 - 2;
  int h = moves/2;
  int xi = n, yi = n;
  string v1;
  for(int i = 0;i < h;i ++ ){
    if(ask(1, 1, xi, yi - 1)){
      v1 += "R";
      yi -- ;
    }
    else{
      v1 += "D";
      xi -- ;
    }
  }
  string v2;
  xi = 1, yi = 1;
  for(int i = 0;i < h; i ++ ){
    if(ask(xi + 1, yi, n, n)){
      v2 += "D";
      xi ++ ;
    }
    else{
      v2 += "R";
      yi ++ ;
    }
  }
  reverse(v1.begin(), v1.end());
  cout << "! " << v2 << v1 << endl;
  return 0;
}