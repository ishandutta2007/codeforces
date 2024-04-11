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

const int N=  (int)1e5 + 9;
vector<int>P[N];

vector<int>leafs;

int main(){
  fastIO;
  int n;
  cin >> n;
  int u,v;
  for(int i = 1;i < n;i ++ ){
    cin >> u >> v;
    P[u].push_back(v);
    P[v].push_back(u);
  }
  int calc = 0;
  for(int i = 1;i <= n;i ++ )
    calc += (P[i].size() > 2);
  if(calc > 1){
    cout << "No\n";
    return 0;
  }
  if(calc == 0){
    int v1 = 0,v2 = 0;
    for(int i = 1;i <= n;i ++)
      if(P[i].size() == 1){
        if(v1 == 0)
          v1 = i;
        else
          v2 = i;
      }
    cout << "Yes\n1\n" << v1 << " " << v2 << "\n";
    return 0;
  }
  int node = 0;
  for(int i = 1;i <= n;i ++ ){
    if(P[i].size() > 2)
      node = i;
  }
  for(int i = 1;i <= n;i ++ )
    if(P[i].size() == 1)
      leafs.push_back(i);
  cout << "Yes\n";
  cout << leafs.size() << "\n";
  for(auto x : leafs)
    cout << node << " " << x << "\n";
  return 0;
}