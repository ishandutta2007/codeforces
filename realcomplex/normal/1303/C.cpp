#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)

vector <int> adj[26];
int ord[26];
int cnt = 0;
string res;

void dfs(int u){
  res.push_back(char('a'+u));
  ord[u]=cnt++;
  for(auto x : adj[u]){
    if(ord[x]==-1)dfs(x);
  }
}

void solve(){
  cnt=0;
  res.clear();
  for(int i = 0 ; i < 26; i ++ )
    adj[i].clear();
  string t;
  cin >> t;
  int n = t.size();
  for(int i = 1 ; i < n; i ++ ){
    adj[t[i] - 'a'].push_back(t[i-1]-'a');
    adj[t[i-1]-'a'].push_back(t[i]-'a');
  }
  for(int i = 0 ; i < 26; i ++ ){
    ord[i]=-1;
    sort(adj[i].begin(), adj[i].end());
    adj[i].resize(unique(adj[i].begin(), adj[i].end()) - adj[i].begin());
  }
  for(int i = 0 ; i < 26; i ++ ){
    if(ord[i]==-1 && adj[i].size() <= 1){
      dfs(i);
    }
  }
  for(int i = 0 ; i < 26; i ++ ){
    if(ord[i]==-1) dfs(i);
  }
  int a, b;
  for(int i = 1; i < n; i ++ ){
    a = t[i - 1] - 'a';
    b = t[i] - 'a';
    if(abs(ord[a]-ord[b]) != 1){
      cout << "NO\n";
      return ;
    }
  }
  cout << "YES\n";
  cout << res << "\n";
}

int main(){ 
  fastIO;
  int tc;
  cin >> tc;
  for(int t = 0; t < tc; t ++ ){  
    solve();
  }
  return 0;
}