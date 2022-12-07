#include<bits/stdc++.h>

using namespace std;

const int maxn = 1000005;

template <typename T> inline void read(T & x)
{
    char c; bool nega=0;
    while((!isdigit(c=getchar()))&&c!='-');
    if(c=='-')
    {
        c=getchar();
        nega=1;
    }
    x=c-48;
    while(isdigit(c=getchar()))
    {
        x=x*10+c-48;
    }
    if(nega) x=-x;
}


int n;
int a[maxn];
int last[maxn];
int answer[maxn];
pair<int, int> tree[maxn << 2];
vector<pair<int, int>> queries[maxn];

void modify(int pos, pair<int, int> val) {
  for(tree[pos += n] = val; pos > 1; pos >>= 1) tree[pos >> 1] = min(tree[pos], tree[pos ^ 1]);
}

pair<int, int> query(int l, int r) {
  pair<int, int> ans = *tree;
  for(l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
    if(l & 1) ans = min(ans, tree[l++]);
    if(r & 1) ans = min(ans, tree[--r]);
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  read(n);
  for(int i = 0; i < n; ++i) read(a[i]);

  int q; read(q);
  for(int i = 0; i < q; ++i) {
    int l, r; read(l); read(r);
    queries[--r].emplace_back(--l, i);
  }

  memset(answer, 0, sizeof answer);
  memset(last, -1, sizeof last);
  memset(tree, 60, sizeof tree);

  for(int i = 0; i < n; ++i) {
    int p = last[a[i]];
    if(p != -1) modify(p, *tree);
    modify(i, make_pair(p, i));
    for(auto w : queries[i]) {
      auto t = query(w.first, i);
      if(t.first < w.first) answer[w.second] = a[t.second];
    }
    last[a[i]] = i;
  }

  for(int i = 0; i < q; ++i) {
    cout << answer[i] << "\n";
  }

  return 0;
}