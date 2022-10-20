#include <bits/stdc++.h>

using namespace std;

const int N = 210;

int n, l, m;
int a[N * 2][N * 2], vower[N], conso[N];
char s[30];
char res[N];

bool checkvower(int u) {
  if (vower[u] == 0) {
    return 0;
  }
  for (int i = 1; i < u; i++) {
    if (s[res[i] - 'a'] == 'V') {
      if (a[u][i + n]) {
        return 0;
      }
    } else {
      if (a[u][i]) {
        return 0;
      }
    }
  }
  return 1;
}

bool checkconso(int u) {
  if (conso[u] == 0) {
    return 0;
  }
  for (int i = 1; i < u; i++) {
    if (s[res[i] - 'a'] == 'V') {
      if (a[u + n][i + n]) {
        return 0;
      }
    } else {
      if (a[u + n][i]) {
        return 0;
      }
    }
  }
  return 1;
}

bool check(int u) {
  for (int i = 1; i <= u; i++) {
    if (s[res[i] - 'a'] == 'V') {
      if (!checkvower(i)) {
        return 0;
      }
    } else {
      if (!checkconso(i)) {
        return 0;
      }
    }
  }
  for (int i = u + 1; i <= n; i++) {
    int pos = (i == u + 1 ? res[u + 1] - 'a' + 1: 0);
    int posvower = -1, posconso = -1;
    for (int j = pos; j < l; j++) {
      if (posvower == -1 && s[j] == 'V') {
        posvower = j;
      }
      if (posconso == -1 && s[j] == 'C') {
        posconso = j;
      }
    }
    vector <int> x;
    if (posvower >= 0) {
      x.push_back(posvower);
    }
    if (posconso >= 0) {
      x.push_back(posconso);
    }
    sort(x.begin(), x.end());
    int f = 0;
    for (int j = 0; j < (int)x.size(); j++) {
      if (s[x[j]] == 'V') {
        if (checkvower(i)) {
          res[i] = x[j] + 'a';
          f = 1;
          break;
        }
      } else {
        if (checkconso(i)) {
          res[i] = x[j] + 'a';
          f = 1;
          break;
        }
      }
    }
    if (!f) {
      return 0;
    }
  }
  return 1;
}

int main() {
  ios_base::sync_with_stdio(0);
  #ifdef Doflamingo
  freopen("input", "r", stdin);
  #endif // Doflamingo
  cin >> s;
  l = strlen(s);
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    char t1, t2;
    int pos1, pos2;
    cin >> pos1 >> t1 >> pos2 >> t2;
    a[pos1 + n * (t1 == 'C')][pos2 + n * (t2 == 'C')] = 1;
    a[pos2 + n * (t2 != 'C')][pos1 + n * (t1 != 'C')] = 1;
  }
  cin >> (res + 1);
  for (int k = 1; k <= n + n; k++) {
    for (int i = 1; i <= n + n; i++) {
      for (int j = 1; j <= n + n; j++) {
        a[i][j] |= (a[i][k] & a[k][j]);
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    vower[i] = conso[i] = 1;
    if (a[i][i + n] == 1) {
      vower[i] = 0;
    }
    if (a[i + n][i]) {
      conso[i] = 0;
    }
    for (int j = 1; j <= n; j++) {
      if (i != j && a[i][j] && a[i][j + n]) {
        vower[i] = 0;
      }
    }
    for (int j = 1; j <= n; j++) {
      if (i != j && a[i + n][j] && a[i + n][j + n]) {
        conso[i] = 0;
      }
    }
  }
  for (int i = n; i >= 0; i--) {
    if (check(i)) {
      cout << (res + 1) << endl;
      return 0;
    }
  }
  cout << -1 << endl;
  return 0;
}