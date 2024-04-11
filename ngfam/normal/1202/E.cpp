#include <bits/stdc++.h>

using namespace std;

const int N = 300029;

int n;
string t; 
string s[N];

struct AhoKorasick{
  int f[N]; /// longest matched suffix for each node
  int par[N]; /// Direct parent for each node
  int val[N]; /// number of given string for each node
  int chr[N]; /// 
  int cntTrie; /// number of nodes in trie
  int trie[N][26]; /// trie

  AhoKorasick() {
    for(int i = 0; i < 26; ++i) {
      trie[0][i] = ++cntTrie;
    }
  }

  void add(string s) {
    int node = 0;
    for(auto c : s) {
      c -= 'a';
      if(trie[node][c] == 0) trie[node][c] = ++cntTrie;
      node = trie[node][c];
    }
    ++val[node];
  }

  void build() {
    queue < int > bfs; bfs.push(0);
    while(!bfs.empty()) {
      int x = bfs.front(); bfs.pop();
      
      if(x > 26) {
        int y = f[par[x]];
        while(!trie[y][chr[x]]) y = f[y];
        f[x] = trie[y][chr[x]];
        val[x] += val[f[x]];
     //   if(x == 52) for(int lmao = x; lmao != 0; lmao = f[lmao]) cout << lmao << " " << val[lmao] << endl;
      }
      for(int i = 0; i < 26; ++i) if(trie[x][i] != 0) {
        par[trie[x][i]] = x;
        chr[trie[x][i]] = i;
        bfs.emplace(trie[x][i]);
      }
    }
  }

  int go(int cur, int i) {
    while(!trie[cur][i]) cur = f[cur];
    return trie[cur][i];
  }

  int calc(int cur) {
    return val[cur];
  }
}aho[2];

int lef[N], rig[N];

int main(){
	ios_base::sync_with_stdio(false); 
  cin.tie(NULL); cout.tie(NULL); 

  cin >> t >> n;
  for(int i = 1; i <= n; ++i) {
    cin >> s[i];
    aho[0].add(s[i]);
    reverse(s[i].begin(), s[i].end());
    aho[1].add(s[i]);
  }

  aho[0].build();
  aho[1].build();

  int node = 0;
  for(int i = 0; i < t.size(); ++i) {
    node = aho[0].go(node, t[i] - 'a');
 //   cout << i << " " << node << " " << aho[0].calc(node) <<  endl;
    lef[i] = aho[0].calc(node);
  }

  node = 0;
  for(int i = t.size() - 1; i >= 0; --i){
    node = aho[1].go(node, t[i] - 'a');
    rig[i] = aho[1].calc(node);
  }


  long long ans = 0;
  for(int i = 0; i < t.size() - 1; ++i) {
    ans += 1LL * lef[i] * rig[i + 1];
  }

  cout << ans;

  return 0;
}