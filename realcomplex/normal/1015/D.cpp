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
#define ones(a) __builtin_popcount(a)

int main(){
  fastIO;
  ll n, s;
  ll k;
  cin >> n >> k >> s;
  if(s < k or (k * (n - 1)) < s){
    cout << "NO";
    return 0;
  }
  cout << "YES\n";
  ll xc = 1;
  ll rem;
  ll go;
  int to = 0;
  for(int j = k-1;j >= 0;j -- ){
    rem = s - (n - 1);
    if(rem >= 0 and rem >= j){
      go = n-1;
    }
    else{
      go = s/(j+1);
    }
    if(xc + go <= n)
      xc += go;
    else
      xc -= go;
    cout << xc << " ";
    s -= go;
    to = 1-to;
  }
  return 0;
}