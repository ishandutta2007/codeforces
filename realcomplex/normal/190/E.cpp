#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

#define fi first
#define se second
#define mp make_pair
#define pii pair<int,int>
#define fastIO std::ios::sync_with_stdio(false);cin.tie(NULL);
#define TEST freopen("in.txt","r",stdin);
#define _ones(a) __builtin_popcount(a)

const int N = (int)5e5 + 5;

vector<int>ans[N];
int cnt,n,m,u,v,node,sk;

vector<int>T[N];
set<int>s;

int main(){
  fastIO;
  cin >> n >> m;
  for(int j = 0;j < m;j ++ ){
    cin >> u >> v;
    T[u].push_back(v);
    T[v].push_back(u);
  }
  for(int i = 1;i <= n;i ++ ){
    s.insert(i);
    sort(T[i].begin(), T[i].end());
  }
  while(!s.empty()){
    node = *s.begin();
    s.erase(s.begin());
    queue<int> q;
    q.push(node);
    while(!q.empty()){
      node = q.front();
      q.pop();
      ans[cnt].push_back(node);
      vector<int>er;
      for(auto it : s){
        sk = it;
        auto y = lower_bound(T[node].begin(), T[node].end(), sk);
        if(y == T[node].end() or *y > sk){
          q.push(sk);
          er.push_back(sk);
        }
      }
      for(auto x : er){
        s.erase(x);
      }
    }
    cnt ++ ;
  }
  cout << cnt << "\n";
  for(int i = 0;i < cnt; i ++ ){
    cout << ans[i].size() << " ";
    for(auto x : ans[i]){
      cout << x << " ";
    }
    cout << "\n";
  }
  return 0;
}