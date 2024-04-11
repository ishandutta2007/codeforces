#include <bits/stdc++.h>
using namespace std;

void Impossible() {
  printf("-1\n");
  exit(0);
}

vector<pair<long long, int>> ans;
struct Node {
  long long l, r;
  Node *child[2];
  
  // 1 whitelist, -1 blacklist, 0 none, 2 both
  int val;
  int lazy;
  
  Node(long long _l = 0, long long _r = (1LL << 32) - 1, int _val = 0) {
    l = _l;
    r = _r;
    val = _val;
    lazy = 0;
    
    child[0] = child[1] = 0;
  }
  
  void propagate() {
    long long mid = l + r >> 1;
    if (!child[0]) child[0] = new Node(l, mid);
    if (!child[1]) child[1] = new Node(mid+1, r);
    if (lazy) {
      for (int i=0; i<2; i++) {
          child[i]->val = lazy;
          child[i]->lazy = lazy;
      }
    }
    
    lazy = 0;
  }
  
  void insert(long long num, int cnt, int v, int d=31) {
    if (cnt == 0) {
      if (val == 2 || v == -1 && val == 1 || v == 1 && val == -1) Impossible();
      val = v;
      lazy = v;
      return;
    }
    
    propagate();
    
    int nchild = num >> d & 1;
    child[nchild]->insert(num, cnt-1, v, d-1);
    
    if (child[0]->val == 0) val = child[1]->val;
    else if (child[1]->val == 0) val = child[0]->val;
    else if (child[0]->val != child[1]->val) val = 2;
    else val = child[0]->val;
  }
  
  long long query(int d=0) {
    if (val == 0) return 0;
    if (val == 1) return 0;
    if (val == -1) {
      ans.push_back({l, d});
      return 1;
    }
    
    int ret = 0;
    if (child[0]) ret += child[0]->query(d+1);
    if (child[1]) ret += child[1]->query(d+1);
    return ret;
  }
} *root = new Node();

pair<long long, int> parse(char *c) {
  long long ret = 0;
  
  int cur = 0;
  for (int i=0; i<4; i++) {
    int tmp = 0;
    while (c[cur] && c[cur] != '.' && c[cur] != '/') {
      tmp = tmp * 10 + c[cur++] - '0';
    }
    
    // cerr << tmp << endl;
    ret = (ret << 8) + tmp;
    ++cur;
  }
  
  int ret2 = 32;
  if (c[cur-1] == '/') {
    ret2 = 0;
    
    while (c[cur]) {
      ret2 = ret2 * 10 + c[cur++] - '0';
    }
  }
  
  return {ret, ret2};
}

int main() {
  int n;
  scanf("%d", &n);
  
  char s[33];
  for (int i=0; i<n; i++) {
    scanf("%s", s);
    
    pair<long long, int> p = parse(s + 1);
    // cerr << p.first << " " << p.second << endl;
    
    if (s[0] == '-') {
      root->insert(p.first, p.second, -1);
    } else {
      root->insert(p.first, p.second, 1);
    }
  }
  
  printf("%d\n", root->query());
  for (int i=0; i<ans.size(); i++) {
    for (int j=0; j<4; j++) {
      printf("%d", ans[i].first >> (8 * (3-j)) & 255);
      if (j == 3) printf("/");
      else printf(".");
    }
    printf("%d\n", ans[i].second);
  }
  return 0;
}