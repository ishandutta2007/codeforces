#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

char s[N];
int n;
int pos[N], tmp[N], sa[N], lcp[N], l;
int foo[N];
vector <pair<int, int> > res;
vector <int> d, e[N];

bool cmp(int u, int v) {
  if (pos[u] != pos[v]) {
    return pos[u] < pos[v];
  }
  u += l;
  v += l;
  if (u <= n && v <= n) {
    return pos[u] < pos[v];
  }
  return u > v;
}

void radixsort() {
  int lim = max(n, 30);
  for (int i = 1; i <= n; i++) {
    int u = sa[i];
    if (u + l > n) {
      d.push_back(u);
    } else {
      e[pos[u + l]].push_back(u);
    }
  }
  int top = 0;
  for (int i = 0; i < d.size(); i++) {
    foo[++top] = d[i];
  }
  d.clear();
  for (int i = 1; i <= lim; i++) {
    for (int j = 0; j < e[i].size(); j++) {
      foo[++top] = e[i][j];
    }
    e[i].clear();
  }
  for (int i = 1; i <= n; i++) {
    int u = foo[i];
    e[pos[u]].push_back(u);
  }
  top = 0;
  for (int i = 1; i <= lim; i++) {
    for (int j = 0; j < e[i].size(); j++) {
      sa[++top] = e[i][j];
    }
    e[i].clear();
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin >> (s + 1);
  n = strlen(s + 1);
  for (int i = 1; i <= n; i++) {
    sa[i] = i;
    pos[i] = s[i] - 'A' + 1;
  }
  tmp[1] = l = 1;
  while (1) {
    //sort(sa + 1, sa + n + 1, cmp);
    radixsort();
    for (int i = 2; i <= n; i++) {
      tmp[i] = tmp[i - 1] + cmp(sa[i - 1], sa[i]);
    }
    for (int i = 1; i <= n; i++) {
      pos[sa[i]] = tmp[i];
    }
    if (tmp[n] == n) {
      break;
    }
    l <<= 1;
  }
  l = 0;
  for (int i = 1; i <= n; i++) {
    if (pos[i] == n) {
      continue;
    }
    int v = sa[pos[i] + 1];
    while (s[i + l] == s[v + l]) {
      l++;
    }
    lcp[pos[i]] = l;
    if (l) {
      l--;
    }
  }
  res.push_back(make_pair(n, 1));
  vector <int> st;
  bool f = 0;
  for (int i = 1; i <= n; i++) {
    if (sa[i] == 1) {
      f = 1;
    }
    while (!st.empty() && lcp[i] < lcp[st.back()]) {
      if (f) {
        res.push_back(make_pair(lcp[st.back()], i - st.back() + 1));
      }
      st.pop_back();
    }
    if (!f && lcp[i] == n - sa[i] + 1) {
      st.push_back(i);
    }
  }
  sort(res.begin(), res.end());
  cout << res.size() << endl;
  for (int i = 0; i < res.size(); i++) {
    cout << res[i].first << " " << res[i].second << endl;
  }
  return 0;
}