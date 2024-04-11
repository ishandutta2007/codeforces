#include <bits/stdc++.h>

using namespace std;

const int N = 500010, CHARACTER = 2;

int n;
char t[N];
int freeMem, sufLink[N * 2], nxt[N * 2][CHARACTER], last, len[N * 2], firstPos[N * 2];

void append(int u) {
  int newNode = ++freeMem;
  firstPos[newNode] = len[newNode] = len[last] + 1;
  while (last != -1 && nxt[last][u] == -1) {
    nxt[last][u] = newNode;
    last = sufLink[last];
  }
  if (last == -1) {
    sufLink[newNode] = 0;
    last = newNode;
    return;
  }
  int q = nxt[last][u];
  if (len[q] == len[last] + 1) {
    sufLink[newNode] = q;
    last = newNode;
    return;
  }
  int clone = ++freeMem;
  for (int i = 0; i < CHARACTER; i++) {
    nxt[clone][i] = nxt[q][i];
  }
  len[clone] = len[last] + 1;
  firstPos[clone] = firstPos[q];
  while (last != -1 && nxt[last][u] == q) {
    nxt[last][u] = clone;
    last = sufLink[last];
  }
  sufLink[clone] = sufLink[q];
  sufLink[q] = sufLink[newNode] = clone;
  last = newNode;
}

int sum[N];
int st[N], top;
int pos[N];
vector <int> a[N + N];

int getNum(int u, int len) {
  int val = sum[u] + N;
  int x = pos[u];
  x = max(x, u - len - 1);
  int res = lower_bound(a[val].begin(), a[val].end(), u) - a[val].begin();
  int res2 = upper_bound(a[val].begin(), a[val].end(), x) - a[val].begin();
  return res - res2;
}

int main() {
  scanf("%d", &n);
  scanf("%s", t + 1);
  memset(sufLink, -1, sizeof sufLink);
  memset(nxt, -1, sizeof nxt);
  a[N].push_back(0);
  for (int i = 1; i <= n; i++) {
    int val = t[i] == '(' ? 0 : 1;
    append(val);
    if (val) {
      val = -1;
    } else {
      val = 1;
    }
    sum[i] = sum[i - 1] + val;
    a[sum[i] + N].push_back(i);
  }
  top = 0;
  sum[0] = 0;
  for (int i = n; i >= 0; i--) {
    while (top && sum[st[top - 1]] > sum[i]) {
      pos[st[--top]] = i;
    }
    st[top++] = i;
  }
  for (int i = top - 1; i >= 0; i--) {
    pos[st[i]] = -1;
  }
  long long res = 0;
  for (int i = 1; i <= freeMem; i++) {
    res += getNum(firstPos[i], len[i]);
    res -= getNum(firstPos[i], len[sufLink[i]]);
  }
  cout << res << endl;
  return 0;
}