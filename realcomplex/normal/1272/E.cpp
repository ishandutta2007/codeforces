#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);


const int N = (int)2e5 + 9;
vector<int> T[N];
int a[N];

vector<int> ev, od;

int low[N];

int main(){
  fastIO;
  int n;
  cin >> n;
  for(int i = 1; i <= n; i ++ ){
    cin >> a[i];
    if(a[i] % 2 == 0) ev.push_back(i);
    else od.push_back(i);
    if(i - a[i] >= 1) 
      T[i - a[i]].push_back(i);
    if(i + a[i] <= n)
      T[i + a[i]].push_back(i);
  }
  for(int i = 1; i <= n; i ++ ){
    low[i] = (int)1e9;
  }
  queue<int> ff;
  bool ok = false;
  for(int i = 1; i <= n; i ++ ){
    if((i - a[i] >= 1 && a[i - a[i]] % 2 != a[i] % 2) || (i + a[i] <= n && a[i + a[i]] % 2 != a[i] % 2) ){
      ff.push(i);
      low[i] = 1;
    }
  }
  int node;
  while(!ff.empty()){
    node = ff.front();
    ff.pop();
    for(auto x : T[node]){
      if(a[x] % 2 != a[node] % 2)
        continue;
      if(low[x] > low[node] + 1){
        low[x] = low[node] + 1;
        ff.push(x);
      }
    }
  }
  for(int i = 1; i <= n; i ++ )
    if(low[i] == (int)1e9){
      cout << -1 << " ";
    }
    else{
      cout << low[i] << " ";
    }
  return 0;
}