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

const int N = 150091;
int p[N];
ll siz[N];
ll edg[N];

void init(){
  for(int i = 0;i < N ;i ++ ){
    p[i] = i;
    siz[i] = 1ll;
    edg[i] = 0;
  }
}

int fin(int a ){
  if(p[a] == a)
    return a;
  return p[a] = fin(p[a]);
}

void merge(int a, int b){
  a = fin(a);
  b = fin(b);
  if(siz[b] < siz[a])
    swap(a, b);
  edg[b] ++ ;
  if(a == b)
    return;
  siz[b] += siz[a];
  edg[b] += edg[a];
  p[a] = b;
}

int main(){
  fastIO;
  init();
  int n,m;
  cin >> n >> m;
  int a, b;
  for(int i = 0;i < m;i ++ ){
    cin >> a >> b;
    merge(a, b);
  }
  int x;
  ll tot;
  for(int i = 1;i <= n;i ++ ){
    x = fin(i);
    tot = (siz[x] * (siz[x] - 1)) / 2;
    if(tot != edg[x]){
      cout << "NO\n";
      return 0;
    }
  }
  cout << "YES\n";
  return 0;
}