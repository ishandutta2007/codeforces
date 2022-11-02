
#include <bits/stdc++.h>
using namespace std;

vector <int> adj[100005];
vector <bool> tree[100005]; vector <int> child[100005];
vector <pair<int,int> > ep;
vector <pair<int,int> > epn;
queue <int> alleven;
queue <int> allodd;
queue <int> evenodd;
queue <int> oddeven;
bool taken[100005];
bool flip[100005];
int parent[100005];
int numin[100005];
int numout[100005];
vector <pair<int,int> > ans;

int n, m, i;
int a, b;

void dfs(int x) {
  for (int i = 0; i < adj[x].size(); i++) {
    if (parent[adj[x][i]] == -1) {
      parent[adj[x][i]] = x;
      child[x].push_back(adj[x][i]);
      tree[x][i] = true;
      dfs(adj[x][i]);
    }
  }
}

int dfs2(int x) {
  int res = 0;
  for (int i = 0; i < child[x].size(); i++) {
    int tmp = dfs2(child[x][i]);
    if (tmp % 2 == 0) {
      ans.push_back(make_pair(x, child[x][i]));
    } else {
      ans.push_back(make_pair(child[x][i], x));
    }
    res += tmp;
  }
  if (flip[x]) ++res;
  return res;
}
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; i++) {
    scanf("%d %d", &a, &b);
    --a;--b;
    adj[a].push_back(b);
    tree[a].push_back(false);
    tree[b].push_back(false);
    adj[b].push_back(a);
    ep.push_back(make_pair(a,b));
  }
  memset(parent, -1, sizeof(parent));
  parent[0] = -2;
  dfs(0);
  for (int i = 0; i < ep.size(); i++) {
    if (parent[ep[i].first] == ep[i].second && !taken[ep[i].first]) {
      taken[ep[i].first] = true;
    } else if (parent[ep[i].second] == ep[i].first && !taken[ep[i].second]) {
      taken[ep[i].second] = true;
    } else {
      epn.push_back(ep[i]);
    }
  }
  for (int i = 1; i < n; i++) {
    numin[i]++;
    numout[parent[i]]++;
  }
  for (int i = 0; i < epn.size(); i++) {
    ++numin[epn[i].second];
    ++numout[epn[i].first];
  }
  for (int i = 0; i < n; i++) {
    if (numin[i] % 2 == 0 && numout[i] % 2 == 0) {
      alleven.push(i);
    } else if (numin[i] % 2 == 1 && numout[i] % 2 == 1) {
      allodd.push(i);
    } else if (numin[i] %2 == 0 && numout[i] % 2 == 1) {
      evenodd.push(i);
    } else {
      oddeven.push(i);
    }
  }
  while (oddeven.size() > evenodd.size() && allodd.size() > 0) {
    int one, two;
    if (allodd.size() > 0) {
      one = allodd.front();
      allodd.pop();
      alleven.push(one);

      two = oddeven.front();
      oddeven.pop();
      evenodd.push(two);
      flip[one] = !flip[one];
      flip[two] = !flip[two];
    } else {
      one = alleven.front();
      alleven.pop();
      allodd.push(one);
    }
  }

  while (evenodd.size() > oddeven.size() && allodd.size() > 0) {
    int one, two;
    if (allodd.size() > 0) {
      one = allodd.front();
      allodd.pop();
      alleven.push(one);
    } else {
      one = alleven.front();
      alleven.pop();
      allodd.push(one);
    }
    two = evenodd.front();
    evenodd.pop();
    oddeven.push(two);
    flip[one] = !flip[one];
    flip[two] = !flip[two];
  }
  while (allodd.size() > 1) {
    int one = allodd.front();
    allodd.pop();
    int two = allodd.front();
    allodd.pop();
    flip[one] = !flip[one];
    flip[two] = !flip[two];
    alleven.push(one);
    alleven.push(two);
  }

  while (evenodd.size() >= 4 + oddeven.size()) {
    int one = evenodd.front();
    evenodd.pop();
    int two = evenodd.front();
    evenodd.pop();
    oddeven.push(one);
    oddeven.push(two);
    flip[one] = !flip[one];
    flip[two] = !flip[two];
  }

  while (oddeven.size() >= 4 + evenodd.size()) {
    int one = oddeven.front();
    oddeven.pop();
    int two = oddeven.front();
    oddeven.pop();
    evenodd.push(one);
    evenodd.push(two);
    flip[one] = !flip[one];
    flip[two] = !flip[two];
  }

  dfs2(0);
  for (int i = 0; i < epn.size(); i++) {
    ans.push_back(epn[i]);
  }

  while (oddeven.size() > evenodd.size()) {
    int one = oddeven.front();
    ans.push_back(make_pair(one, one));
    oddeven.pop();
    evenodd.push(one);
  }

  while (oddeven.size() < evenodd.size()) {
    int one = oddeven.front();
    ans.push_back(make_pair(one, one));
    evenodd.pop();
    oddeven.push(one);
  }

  while (oddeven.size() > 0 && evenodd.size() > 0) {
    int one = evenodd.front();
    int two = oddeven.front();
    ans.push_back(make_pair(one, two));
    evenodd.pop();
    oddeven.pop();
  }
  while (allodd.size() > 0) {
    int one = allodd.front();
    ans.push_back(make_pair(one, one));
    allodd.pop();
  }
  printf("%d\n", ans.size());
  for (int i = 0; i < ans.size(); i++) {
    printf("%d %d\n", ans[i].first + 1, ans[i].second + 1);
  }
}