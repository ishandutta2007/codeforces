#include <bits/stdc++.h>
using namespace std;

void Main() {
  // a[x] xor y < a[y] xor x
  // a[x] xor y = a[y] xor x
  // a[x] xor x = a[y] xor y
  // keep a[x] xor x considering only first few b bits
  // then keep the b+1-th bit
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  struct Node {
    array<int, 2> nxt;
    array<array<int, 2>, 2> lazy;
    Node() {
      nxt[0] = nxt[1] = -1;
      lazy[0][0] = lazy[0][1] = lazy[1][0] = lazy[1][1] = 0;
    }
  };
  vector<Node> nodes(1);
  for (int i = 0; i < n; i++) {
    int val = a[i] ^ i;
    int nd = 0;
    for (int b = 30; b >= 1; b--) {
      int curBit = (val >> b) & 1;
      if (nodes[nd].nxt[curBit] == -1) {
        nodes[nd].nxt[curBit] = nodes.size();
        nodes.emplace_back();
      }
      nd = nodes[nd].nxt[curBit];      
    }
  }
  
  vector<int> dp(n, 1);
  for (int i = 0; i < n; i++) {
    int nd = 0;
    for (int b = 30; b >= 1; b--) {
      int curBit = ((a[i] ^ i) >> b) & 1;
      nd = nodes[nd].nxt[curBit];
      int nxtId = !!(i & (1 << (b - 1)));
      int nxtAi = !!(a[i] & (1 << (b - 1)));
      for (int othId = 0; othId < 2; othId++) {
        for (int othAi = 0; othAi < 2; othAi++) {
          if (!((othAi ^ nxtId) < (nxtAi ^ othId))) {
            continue;
          }
          auto &j = nodes[nd].lazy[nxtId][nxtAi];
          dp[i] = max(dp[i], j);
        }
      }
    }
    nd = 0;
    for (int b = 30; b >= 1; b--) {
      int curBit = ((a[i] ^ i) >> b) & 1;
      nd = nodes[nd].nxt[curBit];
      int nxtId = !!(i & (1 << (b - 1)));
      int nxtAi = !!(a[i] & (1 << (b - 1)));
      for (int othId = 0; othId < 2; othId++) {
        for (int othAi = 0; othAi < 2; othAi++) {
          if (!((nxtAi ^ othId) < (othAi ^ nxtId))) {
            continue;
          }
          auto &j = nodes[nd].lazy[othId][othAi];
          j = max(j, dp[i] + 1);
        }
      }
    }
  }
  cout << *max_element(begin(dp), end(dp)) << '\n';
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T = 1;
  cin >> T;
  while (T--) {
    Main();
  }
}