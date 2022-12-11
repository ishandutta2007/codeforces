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

int n;

int cross(int p){
  p ++ ;
  int x, y;
  cout << "? " <<  p << endl;
  cin >> x;
  cout << "? " << p + (n / 2) << endl;
  cin >> y;
  if(x == y)  {
    cout << "! " << p << endl;
    exit(0);
  }
  return x < y;
}

int main(){
  cin >> n;
  int dir = cross(0);
  int l = 0, r = n/2, md; // md (= [l, r)
  for(int i = 0;i < 25;i ++ ){
    md = (l + r)/2;
    if(cross(md) == dir){
      l = md;
    }
    else{
      r = md;
    }
  }
  cout << "! -1" << endl;
  return 0;
}