#include<bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  int ntest; cin >> ntest;
  while(ntest--) {
    int n, m; cin >> n >> m;

    int diag = 0, sym = 0;

    vector<vector<array<int, 2>>> a(n);
    for(int i = 0; i < n; ++i) {
      a[i].resize(2);
      for(int u = 0; u < 2; ++u) {
        for(int v = 0; v < 2; ++v) {
          cin >> a[i][u][v];
        }
      }
    }

    for(int v = 0; v < n; ++v) {
      int flag = 1;
      for(int i = 0; i < 2; ++i) {
        for(int j = 0; j < 2; ++j) {
          if(a[v][i][j] != a[v][j][i]) flag = 0;
        }
      }
      if(flag) diag = 1;
    }

    if(diag && m % 2 == 0) {
      cout << "YES" << endl;
    }
    else {
      cout << "NO" << endl;
    }
  }

  return 0;
}


/*
5 7
7 4
    5 7
    7 4
        5 7
        7 4
*/