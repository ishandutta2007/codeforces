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

const int MAX_UNI = (int)4e5 + 9123;
const int MAX_N = (int)1e5 + 9;

struct Union{
  int pi[MAX_UNI];
  int sz[MAX_UNI];
  void Init(){
    for(int i = 0;i < MAX_UNI; i ++ ){
      pi[i] = i;
      sz[i] = 1;
    }
  }
  int fin(int a){
    if(pi[a] == a)
      return a;
    pi[a] = fin(pi[a]);
    return pi[a];
  }
  bool same(int a, int b){
    return fin(a) == fin(b);
  }
  void merge(int a, int b){
    a = fin(a);
    b = fin(b);
    if(a == b)
      return;
    if(sz[a] > sz[b])
      swap(a, b);
    sz[b] += sz[a];
    pi[a] = pi[b];
  }
};

Union al;

vector<int> colors[MAX_N];
int dsum[MAX_N];

int finIndex(int a, int cl){
  int y = lower_bound(colors[a].begin(), colors[a].end(), cl) - colors[a].begin();
  if(y >= colors[a].size()){
    return -1;
  }
  if(colors[a][y] != cl){
    return -1;
  }
  y += dsum[a - 1] + 1;
  return y;
}

map<pii, int> st_ans;
map<pii, bool> is_ok;

int main(){
  fastIO;
  al.Init();
  int n,m;
  cin >> n >> m;
  int ui[m], vi[m], cl[m];
  for(int i = 0;i < m; i ++ ){
    cin >> ui[i] >> vi[i] >> cl[i];
    colors[ui[i]].push_back(cl[i]);
    colors[vi[i]].push_back(cl[i]);
  }
  for(int i = 1;i <= n;i ++ ){
    sort(colors[i].begin(), colors[i].end());
    colors[i].resize(unique(colors[i].begin(), colors[i].end()) - colors[i].begin());
    dsum[i] += dsum[i - 1];
    dsum[i] += colors[i].size();
  }
  int ai, bi;
  for(int i = 0;i < m; i ++ ){
    ai = finIndex(ui[i], cl[i]);
    bi = finIndex(vi[i], cl[i]);
    al.merge(ai, bi);
  }
  int q;
  cin >> q;
  int uu, vv;
  int ans;
  for(int i = 0; i < q;i ++ ){
    cin >> uu >> vv;
    if(colors[uu].size() > colors[vv].size())
      swap(uu, vv);
    if(!is_ok[mp(uu, vv)]){
      ans = 0;
      for(auto Col : colors[uu]){
        ai = finIndex(uu, Col);
        bi = finIndex(vv, Col);
        if(ai == -1 or bi == -1)
          continue;
        if(al.same(ai, bi))
          ans ++ ;
      }
      st_ans[mp(uu, vv)] = ans;
      is_ok[mp(uu, vv)] = true;
    }
    cout << st_ans[mp(uu, vv)] << "\n";
  }
  return 0;
}