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

typedef multiset<int> mset;

const int N = (int)1e5 + 9;

struct Node{
  Node *nex[26];
  bool ends;
  int value;
  Node(){
    for(int i = 0;i < 26;i ++ )
      nex[i] = NULL;
    ends = false;
  }
};

Node *trie;
int tt = 1;

void add_to_trie(string s){
  Node *cur = trie;
  for(char I : s){
    if(cur -> nex[I - 'a'] == NULL){
      cur -> nex[I - 'a'] = new Node();
      (cur -> nex[I - 'a']) -> value = tt;
      tt ++ ;
    }
    cur = cur -> nex[I - 'a'];
  }
  cur -> ends = true;
}

mset sets[N];

void merge(int a, int b){
  if(sets[a].size() > sets[b].size()){
    swap(sets[a], sets[b]);
  }
  for(auto x : sets[a])
    sets[b].insert(x);
  sets[a].clear();
}

void dfs(Node *current, int depth){
  for(int i = 0;i < 26;i ++ ){
    if(current -> nex[i] != NULL){
      dfs(current -> nex[i], depth + 1);
      merge((current -> nex[i]) -> value, current -> value);
    }
  }
  if(current -> value == 0)
    return;
  if(current -> ends == true){
    sets[current -> value].insert(depth);
  }
  else{
    auto x = sets[current -> value].end();
    -- x;
    sets[current -> value].erase(x);
    sets[current -> value].insert(depth);
  }
}

int main(){
  fastIO;
  trie = new Node();
  trie -> value = 0;
  int n;
  cin >> n;
  string s;
  for(int i = 0;i < n;i ++ ){
    cin >> s;
    add_to_trie(s);
  }
  dfs(trie, 0);
  int ans = 0;
  for(auto x : sets[0]){
    ans += x;
  }
  cout << ans;
  return 0;
}