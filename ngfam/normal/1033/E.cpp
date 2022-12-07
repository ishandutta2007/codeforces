#include<bits/stdc++.h>

using namespace std;

const int maxn = 605;

vector<pair<int,int>> edges = {{1,4}
,{2,4}
,{1,2}
,{3,1}};

int ask(vector<int> vec) {
  //
  // int cnt = 0;
  // for(int x : vec) for(int y : vec) for(auto p : edges){
  //   if(make_pair(x, y) == p) cnt++;
  // }
  // return cnt;

  if(vec.size() == 1 || vec.size() == 0) return 0;

  cout << "? " << vec.size();
  for(int x : vec) cout << " " << x;
  cout << endl;
  int risan; cin >> risan;
  return risan;
}

int find(int v, vector<int> vec, int calculated = 0) {
  if(!calculated) {
    vec.push_back(v);
    int a = ask(vec);
    vec.pop_back();
    int b = ask(vec);
    if(a == b) return -1;
  }
  if(vec.size() == 1) return vec.back();
  int x = find(v, vector<int>(vec.begin(), vec.begin() + vec.size() / 2), 0);
  if(x != -1) return x;
  return find(v, vector<int>(vec.begin() + vec.size() / 2, vec.end()), 1);
}

int n;
int visited[maxn];

vector<int> odd;
vector<int> even;
vector<int> g[maxn];
vector<int> vertices;

void dfs(int v, int color) {
  visited[v] = 1;
  vertices.erase(find(vertices.begin(), vertices.end(), v));
  if(color) odd.push_back(v);
  else even.push_back(v);
  while(true) {
    int u = find(v, vertices);
    if(u == -1) return;
    g[v].push_back(u);
    g[u].push_back(v);
    dfs(u, 1 - color);
  }
}

vector<int> path;

bool find_path(int v, int p, int q) {
  if(v == q) {
    path.push_back(v);
    return true;
  }
  bool flag = false;
  for(int s : g[v]) if(s != p) {
    flag |= find_path(s, v, q);
  }
  if(flag) path.push_back(v);
  return flag;
}

void found_cycle(int v, vector<int> of) {
  int node = find(v, of, 0);
  find_path(v, -1, node);
  cout << "N " << path.size() << endl;
  for(int x : path) cout << x << " ";
  cout << endl;
  exit(0);
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);


  cin >> n;
  for(int i = 1; i <= n; ++i) vertices.push_back(i);
  int allEdge = ask(vertices);

  for(int i = 1; i <= n; ++i) if(!visited[i]) dfs(i, 0);

  int count_odd = ask(odd);
  int count_even = ask(even);

  allEdge -= count_odd + count_even;

  for(int x : odd) {
    vector<int> newodd;
    for(int y : odd) if(y != x) newodd.push_back(y);
    if(ask(newodd) != count_odd) found_cycle(x, newodd);

  }

  swap(odd, even);

  for(int x : odd) {
    vector<int> newodd;
    for(int y : odd) if(y != x) newodd.push_back(y);
    if(ask(newodd) != count_even) found_cycle(x, newodd);
  }

  cout << "Y " << odd.size() << endl;
  for(int x : odd) cout << x << " ";
  cout << endl;

  return 0;
}

/***
1 4
2 4
1 2
3 1
***/