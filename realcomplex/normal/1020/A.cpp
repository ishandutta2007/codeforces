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

int abs(int x){
  if(x < 0)
    return -x;
  else
    return x;
}

int main(){
  fastIO;
  int n, h, a, b, q;
  cin >> n >> h >> a >> b >> q;
  int ta, fa, tb, fb;
  int ans;
  for(int j = 0;j < q;j ++ ){
    cin >> ta >> fa >> tb >> fb;
    ans = abs(ta - tb);
    if(ta == tb){
      ans += abs(fa - fb);
    }
    else if(fa > b and fb > b){
      ans += abs(fa - b) + abs(fb - b);
    }
    else if(fa < a and fb < a){
      ans += abs(fa - a) + abs(fb - a);
    }
    else{
      ans += abs(fa - fb);
    }
    cout << ans << "\n";
  }
  return 0;
}