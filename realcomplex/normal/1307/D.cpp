#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)2e5 + 9;
bool is[N];
int d2[N];
int d1[N];
vector<int> T[N];

struct P{ 
  int cmp;
  int dv;
  int ev;
  bool operator< (const P &F) const {
    if(cmp == F.cmp){
      if(dv == F.dv) return ev < F.ev;
      return dv < F.dv;
    }
    return cmp < F.cmp;
  }
};

int main(){
  fastIO;
  int n, m, k;
  cin >> n >> m >> k;
  int a;
  for(int i =1 ; i <= k ; i ++ ){
    cin >> a;
    is[a] = true;
  }
  for(int i =1 ; i <= n; i ++ ){
    d1[i]=d2[i]=(int)1e9;
  }
  int x, y;
  for(int i = 0 ; i < m ; i ++ ){
    cin >> x >> y;
    T[x].push_back(y);
    T[y].push_back(x);
  }
  queue<int> ff;
  ff.push(1);
  d1[1]=0;
  int node;
  while(!ff.empty()){
    node = ff.front();
    ff.pop();
    for(auto x : T[node]){
      if(d1[x] == (int)1e9){
        d1[x]=d1[node]+1;
        ff.push(x);
      }
    }
  }
  d2[n]=0;
  ff.push(n);
  while(!ff.empty()){
    node = ff.front();
    ff.pop();
    for(auto x : T[node]){
      if(d2[x] == (int)1e9){
        d2[x]=d2[node]+1;
        ff.push(x);
      }
    }
  }
  int res = d1[n];
  vector<P> qq;
  for(int i = 1; i <= n; i ++ ){
    if(is[i])
      qq.push_back({d1[i]-d2[i],d1[i],d2[i]});
  }
  sort(qq.begin(), qq.end());
  int sd=-1,es = -1;
  int bes = -1;
  for(int i = qq.size() - 1; i >= 0 ; i -- ){
    if(es != -1){
      bes = max(bes, qq[i].dv + es + 1);
    }
    es = max(es, qq[i].ev);
  }
  if(bes!=-1)res=min(res,bes);
  cout << res << "\n";
  return 0;
}