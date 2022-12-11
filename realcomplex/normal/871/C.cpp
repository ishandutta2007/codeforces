#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)1e5 + 9;
const int MOD = (int)1e9 + 7;
int pwr[N * 4];
vector<int> T[N];

struct Point{
  int xi;
  int yi;
  int id;
};

bool cmp1(const Point &F1, const Point &F2) {
  if(F1.xi == F2.xi) return F1.yi < F2.yi;
  else return F1.xi < F2.xi;
}

bool cmp2(const Point &F1, const Point &F2) {
  if(F1.yi == F2.yi) return F1.xi < F2.xi;
  else return F1.yi < F2.yi;
}

int xx[N], yy[N];
bool vis[N];
set<int> xc, yc;
int rem;

void dfs(int u, int par){
  vis[u]=true;
  xc.insert(xx[u]);
  yc.insert(yy[u]);
  for(auto x : T[u]){
    if(x == par) continue;
    if(vis[x]){
      rem=0;
    }
    else{
      dfs(x,u);
    }
  }
}


int main(){
  fastIO;
  pwr[0]=1;
  for(int i = 1; i < 4*N; i ++ ){
    pwr[i]=(pwr[i-1]*2ll)%MOD;
  }
  int n;
  cin >> n;
  vector<Point> cx(n), cy(n);
  vector<pii> cr;
  for(int i = 0 ; i < n; i  ++ ){
    cx[i].id = i;
    cy[i].id = i;
    cin >> cx[i].xi >> cx[i].yi;
    cy[i].xi = cx[i].xi;
    cy[i].yi = cx[i].yi;
    xx[i] = cx[i].xi;
    yy[i] = cx[i].yi;
  }
  sort(cx.begin(), cx.end(), cmp1);
  sort(cy.begin(), cy.end(), cmp2);
  for(int i = 0 ; i < n; i ++ ){
    if(i > 0 && cx[i].xi == cx[i-1].xi){
      T[cx[i].id].push_back(cx[i-1].id);
      T[cx[i-1].id].push_back(cx[i].id);
    }
    if(i > 0 && cy[i].yi == cy[i-1].yi){
      T[cy[i].id].push_back(cy[i-1].id);
      T[cy[i-1].id].push_back(cy[i].id);
    }
  }
  int res = 1;
  int cur;
  for(int i = 0 ; i < n; i ++ ){
    if(!vis[i]){
      rem=1;
      xc.clear();
      yc.clear();
      dfs(i,-1);
      cur = pwr[(int)xc.size()+(int)yc.size()]-rem;
      res = (res * 1ll * cur) % MOD;
    }
  }
  cout << res << "\n";
  return 0;
}