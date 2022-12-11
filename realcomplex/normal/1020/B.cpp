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

int p[1005];
bool vis[1005];
int n;

int calc(int k){
  for(int j = 0;j < 1005;j ++ )
    vis[j] = false;
  while(vis[k] == false){
    vis[k] = true;
    k = p[k];
  }
  return k;
}

int main(){
  fastIO;
  cin >> n;
  for(int i = 1;i <= n;i ++ )
    cin >> p[i];
  for(int i = 1;i <= n;i ++ )
    cout << calc(i) << " ";
  cout << "\n";
  return 0;
}