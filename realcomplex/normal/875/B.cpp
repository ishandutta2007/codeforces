#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)3e5 + 9;
int par[N];
int sz[N];

int fin(int a){
  if(par[a] == a) return a;
  return par[a]=fin(par[a]);
}

void unite(int a, int b){
  a = fin(a);
  b = fin(b);
  if(a==b) return;
  sz[b] += sz[a];
  par[a]=b;
}


int main(){
  fastIO;
  int n;
  cin >> n;
  for(int i = 0 ; i <= n + 1; i ++ ) par[i] = -1;
  cout << 1 << " ";
  int x;
  int res =0 ;
  for(int i = 1; i <= n; i ++ ){
    cin >> x;
    par[x]=x;
    sz[x]=1;
    if(par[x-1] != -1){
      unite(x,x-1);
    }
    if(par[x+1] != -1){
      unite(x,x+1);
    }
    res = i+1;
    if(par[n] != -1) res -= sz[fin(n)];
    cout << res << " ";
  }
  return 0;
}