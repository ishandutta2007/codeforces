#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<ll,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ab(x) ((x) < 0 ? -(x) : (x))
#define all(x) ((x).begin(),(x).end())
#define len(x) ((int)(x).size())

const int N = (int)2e5 + 9;
vector<int>T[N];
vector<int>R[N];
bool vis[N];
int col[N];
int dist[N];

int cnt = 1;

struct max_dist{
  int node;
  int dis;
};

void dfs(int u ,int center){
  vis[u] = true;
  for(auto x : T[u]){
    if(vis[x])
      continue;
    if(col[x] == col[u]){
      dfs(x,center);
    }
    else{
      cnt++;
      R[center].push_back(cnt);
      R[cnt].push_back(center);
      dfs(x,cnt);
    }
  }
}

void maxdis(){
  for(int i = 0 ;i<N;i++)
  dist[i] = (int)1e9;
}

max_dist findDiameter(int u){
  queue<int>cur;
  cur.push(u);
  int nod;
  dist[u] = 0;
  max_dist ans;
  ans.node = -1,ans.dis = -1;
  while(!cur.empty()){
    nod = cur.front();
    if(ans.dis < dist[nod])
      ans.dis = dist[nod],ans.node = nod;
    cur.pop();
    for(auto x : R[nod]){
      if(dist[x] > dist[nod] + 1){
        dist[x] = dist[nod]+1;
        cur.push(x);
      }
    }
  }
  return ans;
}

int main(){
  fastIO;
  int n;
  cin >> n;
  for(int i = 1;i<=n;i++){
    cin >> col[i];
  }
  int a,b;
  for(int i = 1;i<n;i++){
    cin >> a >> b;
    T[a].push_back(b);
    T[b].push_back(a);
  }
  dfs(1,1);
  maxdis();
  int l = findDiameter(1).node;
  maxdis();
  cout << (findDiameter(l).dis + 1) / 2;
  return 0;
}