#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int,int> pii;
typedef double db;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define TEST freopen("in.txt","r",stdin);
#define ab(a) ((a < 0) ? (-(a)) : (a))
#define all(a) a.begin(), a.end()

const int N = 22;
const int MX = 1 << N;

int n;

bool has[MX];
bool vis[MX];
bool num[MX];

void bfs(int node){
  vis[node] = true;
  queue<pii> nd;
  nd.push(mp(node, 1));
  int tt;
  int rem;
  while(!nd.empty()){ // works in O(2^N) since only 2^N states in total
    node = nd.front().fi;
    tt = nd.front().se;
    nd.pop();
    if(tt == 1){
      if(!num[node]){
        num[node] = true;
        nd.push(mp(node, 2));
      }
    }
    else{
      rem = (1 << n) - 1 - node;
      if(!vis[rem] and has[rem]){
        vis[rem] = true;
        nd.push(mp(rem, 1));
      }
      for(int j = 0;j < n;j ++ ){
        if(num[node | (1 << j)] == false){
          num[node | (1 << j)] = true;
          nd.push(mp(node | (1 << j), 2));
        }
      }
    }
  }
}

int main(){
  fastIO;
  int m;
  cin >> n >> m;
  int x;
  for(int i = 0;i < m;i ++ ){
    cin >> x;
    has[x] = true;
  }
  int ans = 0;
  for(int i = 0;i < (1 << n); i ++ ){
    if(has[i]){
      if(!vis[i]){
        bfs(i);
        ans ++ ;
      }
    }
  }
  cout << ans << "\n";
  return 0;
}