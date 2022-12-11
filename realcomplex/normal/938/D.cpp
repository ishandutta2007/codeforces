#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll,int> pii;
typedef double db;

#define fi first
#define se second
#define mp make_pair
#define fastIO std::ios::sync_with_stdio(false);cin.tie(NULL);
#define TEST freopen("in.txt","r",stdin);
#define ones(a) __builtin_popcount(a);
#define pq priority_queue

struct Edge{
  int to;
  ll weight;
};


const int N = (int)2e5 + 9;
vector<Edge> T[N];
int n;
ll dep[N];

void Dijikstra(){
  set<pii> Q;
  for(int i = 1;i <= n;i ++ ){
    Q.insert(mp(dep[i], i));
  }
  int nod;
  while(!Q.empty()){
    nod = Q.begin() -> se;
    Q.erase(Q.begin());
    for(Edge nex : T[nod]){
      if(dep[nod] + nex.weight < dep[nex.to]){
        Q.erase(mp(dep[nex.to], nex.to));
        dep[nex.to] = dep[nod] + nex.weight;
        Q.insert(mp(dep[nex.to], nex.to));
      }
    }
  }
}

int main(){
  fastIO;
  int m;
  cin >> n >> m;
  int ui, vi;
  ll wi;
  for(int i = 0;i < m;i ++ ){
    cin >> ui >> vi >> wi;
    wi *= 2;
    T[ui].push_back({vi, wi});
    T[vi].push_back({ui, wi});
  }
  for(int i = 1;i <= n;i ++ )
    cin >> dep[i];
  Dijikstra();
  for(int i = 1 ;i <= n;i ++ ){
    cout << dep[i] << " ";
  }
  cout << "\n";
  return 0;
}