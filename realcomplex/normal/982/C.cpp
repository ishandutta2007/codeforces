#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef long double ld;
	
#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define TEST freopen("in.txt","r",stdin);
#define ab(a) ((a < 0) ? (-(a)) : (a))
#define len(x) ((int)(x).size())
#define ones(x) __builtin_popcount((x))
#define all(x) x.begin(), x.end()

int ans;
const int N = (int)1e5 + 9;
vector<int>T[N];
bool vis[N];

int tt;

int dfs(int u){
  int rz = 1;
  vis[u] = true;
  for(auto x : T[u]){
    if(!vis[x]){
      tt = dfs(x);
      if(tt % 2 == 0)
        ans ++ ;
      rz += tt;
    }
  }
  return rz;
}

int main(){
  fastIO;
  int n;
  cin >> n;
  if(n%2==1){
    cout << "-1";
    return 0;
  }
  int a,b;
  for(int i =1 ;i < n;i ++){
    cin >> a >> b;
    T[a].push_back(b);
    T[b].push_back(a);
  }
  dfs(1);
  cout << ans;
  return 0;
}