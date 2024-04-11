#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef long double db;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO std::ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define TEST freopen("in.txt","r",stdin);
#define ones(a) __builtin_popcount(a);
#define pq priority_queue

const int N = (int)2e5 + 9;
vector<pii> T[N];
bool exist[N];
int deg[N];

int main(){
  fastIO;
  int n, m, k;
  cin >> n >> m >> k;
  int x[m], y[m];
  for(int i = 0;i < m; i ++ ){
    cin >> x[i] >> y[i];
    exist[i] = true;
    T[x[i]].push_back(mp(y[i], i));
    T[y[i]].push_back(mp(x[i], i));
    deg[x[i]] ++ ;
    deg[y[i]] ++ ;
  }
  int good_set = n;
  queue<int> vis;
  for(int i = 1; i <= n; i ++ ){
    if(deg[i] < k){
      vis.push(i);
    }
  }
  int ans[m];
  int cur;
  for(int move = m - 1;move >= 0;move -- ){
    while(!vis.empty()){
      cur = vis.front();
      good_set -- ;
      vis.pop();
      for(auto xx : T[cur]){
        if(!exist[xx.se])
          continue;
        exist[xx.se] = false;
        if(deg[xx.fi] == k){
          vis.push(xx.fi);
        }
        deg[xx.fi] -- ;
      }
    }
    ans[move] = good_set;
    if(!exist[move])  
      continue;
    exist[move] = false;
    if(deg[x[move]] == k){
      vis.push(x[move]);
    }
    if(deg[y[move]] == k){
      vis.push(y[move]);
    }
    deg[x[move]] -- ;
    deg[y[move]] -- ;
  }
  for(int i = 0;i < m; i ++ )
    cout << ans[i] << "\n";
  return 0;
}