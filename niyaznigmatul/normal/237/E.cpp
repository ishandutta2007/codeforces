#include <iostream>

using namespace std;

const int N = 12345;
const int INF = 1 << 30;
int he[N], ne[N], ss[N], ff[N], cn[N], a[N], inq[N], q[N], d[N], rev[N], cost[N], cap[N], flow[N], laste[N];
string s[N];
int m;

void addedge(int v, int u, int cp, int cs) {
  ss[m] = v;
  ff[m] = u;
  rev[m] = m + 1;
  cost[m] = cs;
  cost[m + 1] = -cs;
  flow[m] = flow[m + 1] = 0;
  cap[m] = cp;
  cap[m + 1] = 0;  
  rev[m + 1] = m;
  ss[m + 1] = u;
  ff[m + 1] = v;
  m += 2;  
}

int main() {
  string t;
  int n;
  cin >> t;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> s[i] >> a[i];
  }
  int src = 26 + n;
  int tar = src + 1;
  m = 0;
  for (int i = 0; i < n; i++) {
    addedge(src, i, a[i], i + 1);
    for (int j = 0; j < 26; j++) cn[j] = 0;
    for (int j = 0; j < (int) s[i].length(); j++) cn[s[i][j] - 'a']++;
    for (int j = 0; j < 26; j++) {
      addedge(i, n + j, cn[j], 0);
    }
  }
  for (int j = 0; j < 26; j++) cn[j] = 0;
  for (int j = 0; j < (int) t.length(); j++) cn[t[j] - 'a']++;
  for (int i = 0; i < 26; i++) addedge(i + n, tar, cn[i], 0);
  int cv = src + 2;
  for (int i = 0; i < cv; i++) he[i] = -1;
  for (int i = 0; i < m; i++) {
    ne[i] = he[ss[i]];
    he[ss[i]] = i;
  }
  int mq = src + 4;
  int cst = 0;
  int flw = 0;
  while (true) {
    int head = 0;
    int tail = 1;
    q[head] = src;
    for (int i = 0; i < cv; i++) {
      d[i] = INF;
      inq[i] = 0;
    }
    d[src] = 0;
    inq[src] = 1;
    while (head != tail) {
      int v = q[head++];
      if (head == mq) head = 0;
      inq[v] = 0;
      for (int e = he[v]; e >= 0; e = ne[e]) {
        if (cap[e] == flow[e]) continue;
        if (cost[e] + d[v] < d[ff[e]]) {
          d[ff[e]] = cost[e] + d[v];
          laste[ff[e]] = e;
          if (!inq[ff[e]]) {
            q[tail++] = ff[e];
            if (tail == mq) tail = 0;
            inq[ff[e]] = true;
          }
        }
      } 
    }
    if (d[tar] == INF) break;
    cst += d[tar];
    flw++;
    for (int i = tar; i != src; i = ss[laste[i]]) {
      flow[laste[i]]++;
      flow[rev[laste[i]]]--;
    }    
  }
  cout << (flw == (int) t.length() ? cst : -1);
}