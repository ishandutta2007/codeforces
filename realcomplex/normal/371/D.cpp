#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef long double ld;
typedef pair<int,ll> pii;
typedef double db;

#define int ll

#define fi first
#define se second
#define mp make_pair
#define fastIO std::ios::sync_with_stdio(false);cin.tie(NULL);
#define TEST freopen("in.txt","r",stdin);
#define ones(a) __builtin_popcount(a);
#define pq priority_queue

const int N = (int)2e5 + 91;
int rem[N];
int lit[N];

int p[N];
int rnk[N];
int nx[N];

void init(){
  for(int i = 0;i < N; i ++ ){
    p[i] = i;
    rnk[i] = 1;
    nx[i] = i + 1;
  }
}

int fin(int u){
  if(u == p[u])
    return u;
  return p[u] = fin(p[u]);
}

void merge(int a, int b){
  a = fin(a);
  b = fin(b);
  if(a == b)
    return;
  if(rnk[a] > rnk[b]) 
    swap(a, b);
  rnk[b] += rnk[a];
  p[a] = b;
  nx[b] = max(nx[b], nx[a]);
}

int n;

bool is_full(int ix){
  return (lit[ix] == rem[ix] and ix <= n);
}

signed main(){
  fastIO;
  init();
  cin >> n;
  for(int i = 1;i <= n;i ++ ){
    cin >> rem[i];
    lit[i] = 0;
  }
  int q;
  cin >> q;
  int ti, ves, litr;
  int can;
  for(int i = 0;i < q;i ++ ){
    cin >> ti;
    if(ti == 1){
      cin >> ves >> litr;
      while(ves <= n and litr > 0){
        can = min(litr, rem[ves] - lit[ves]);
        lit[ves] += can;
        litr -= can;
        if(is_full(ves)){
          if(is_full(ves - 1))merge(ves, ves - 1);
          if(is_full(ves + 1))merge(ves, ves + 1);
        }
        ves = nx[fin(ves)];
      }
    }
    else{
      cin >> ves;
      cout << lit[ves] << "\n";
    }
  }
  return 0;
}