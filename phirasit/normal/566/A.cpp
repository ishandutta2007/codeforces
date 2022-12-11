#include <stdio.h>
#include <vector>

using namespace std;

const int N = 800010;

int nxt[N][30];
vector<int> c1[N], c2[N];

int cnt = 2;

char str[N];
int n;

typedef pair<int, int> pii;
long long ans = 0ll;
vector<pii> ls;

void ins(int id) {
  scanf("%s", str);
  int idx = 1;
  for(int i = 0;str[i];i++) {
    int val = str[i] - 'a';
    if(nxt[idx][val] == 0) {
      nxt[idx][val] = cnt++;
    }
    idx = nxt[idx][val];
  }
  if(id < 0) {
    c1[idx].push_back(-id);
  }else {
    c2[idx].push_back(id);
  }
}
pii dfs(int idx, int depth) {
  if(idx == 0) return {0, 0};
  int r1 = idx, r2 = idx;
  while(c1[r1].size() and c2[r2].size()) {
    ans += (long long) depth;
    ls.push_back({c1[r1].back(), c2[r2].back()});
    c1[r1].pop_back();
    c2[r2].pop_back();
  }
  str[depth] = 0;
  for(int i = 0;i < 30;i++) {
    str[depth] = i + 'a';
    pii x = dfs(nxt[idx][i], depth+1);
    int id1 = x.first, id2 = x.second;
    if(c1[id1].size()) {
      if(c1[r1].size() < c1[id1].size()) swap(r1, id1);
      for(int val : c1[id1]) {
        c1[r1].push_back(val);
      }
      c1[id1].clear();
    }
    if(c2[id2].size()) {
      if(c2[r2].size() < c2[id2].size()) swap(r2, id2);
      for(int val : c2[id2]) {
        c2[r2].push_back(val);
      }
      c2[id2].clear();
    }
    while(c1[r1].size() and c2[r2].size()) {
      ans += (long long) depth;
      ls.push_back({c1[r1].back(), c2[r2].back()});
      c1[r1].pop_back();
      c2[r2].pop_back();
    }
  }
  return {r1, r2};
}
int main() {
  scanf("%d", &n);
  for(int i = 0;i < n;i++) {
    ins(-(i+1));
  }
  for(int i = 0;i < n;i++) {
    ins((i+1));
  }
  dfs(1, 0);
  printf("%I64d\n", ans);
  for(auto p : ls) {
    printf("%d %d\n", p.first, p.second);
  }
  return 0;
}