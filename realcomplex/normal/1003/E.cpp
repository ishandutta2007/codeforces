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

const int N = (int)4e5 + 1923;
int deg[N];
vector<pii> ed;

int p,n,d,k;

void constr(int node, int dep, int ok_dep){
  if(ok_dep == dep)
    return;
  while(deg[node] + 1 <= k){
    if(p > n)
      return;
    deg[node] ++ ;
    deg[p] ++ ;
    ed.push_back(mp(node, p));
    constr(p ++ , dep + 1, ok_dep);
  }
}

int main(){
  fastIO;
  cin >> n >> d >> k;
  if(d + 1 > n){
    cout << "NO\n";
    return 0;
  }
  if(n == 1){
    cout << "NO\n";
    return 0;
  }
  if(k == 1){
    cout << (n != 2 or d != 1 ? "NO\n" : "YES\n1 2\n");
    return 0;
  }
  p = d + 2;
  for(int i = 1;i <= d;i ++ ){
    deg[i] ++ ;
    deg[i + 1] ++ ;
    ed.push_back(mp(i, i + 1));
  }
  for(int i = 2; i <= d;i ++ )
    constr(i, 0, min(i - 1, d - i + 1));
  if(p <= n){
    cout << "NO\n";
    return 0;
  }
  cout << "YES\n";
  for(auto x : ed)
    cout << x.fi << " " << x.se << "\n";
  return 0;
}