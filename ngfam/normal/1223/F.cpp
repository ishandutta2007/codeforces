#include<bits/stdc++.h>

using namespace std;

const int MAXN = 300030;

int n;
int a[MAXN];
int f[MAXN];
map < int, int > g[MAXN];

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  int ntest; cin >> ntest;
  while(ntest--) {
    cin >> n;
    for(int i = 0; i < n; ++i) {
      cin >> a[i];
    }

    long long answer = 0;
    for(int i = n - 2; i >= 0; --i) {
      int next_val = -1;
      if(a[i] == a[i + 1]) {
        next_val = i + 1;
      }
      else{
        if(g[i + 1].count(a[i])) next_val = g[i + 1][a[i]];
      }
      if(next_val == -1) continue;
      f[i] = f[next_val + 1] + 1;
      swap(g[i], g[next_val + 1]);
      g[i][a[next_val + 1]] = next_val + 1;
      answer += f[i];
    }

    for(int i = 0; i <= n; ++i) g[i].clear(), a[i] = 0, f[i] = 0;

    cout << answer << "\n";
  }

  return 0;
}