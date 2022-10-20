#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

string x = "abdefhijklmopqrstvwxyzcugn";

int n;
char s[N][110];
int a[26][26];
int deg[26];

void go(int u, int l, int r) {
  while (l <= r && s[l][u] == 0) {
    l++;
  }
  if (l > r) {
    return;
  }
  int used[26];
  memset(used, 0, sizeof used);
  used[s[l][u] - 'a'] = 1;
  int last = l;
  for (int i = l + 1; i <= r; i++) {
    if (s[i][u] == 0) {
      puts("Impossible");
      exit(0);
    }
    if (s[i][u] != s[i - 1][u]) {
      if (used[s[i][u] - 'a']) {
        puts("Impossible");
        exit(0);
      }
      a[s[i - 1][u] - 'a'][s[i][u] - 'a'] = 1;
      if (a[s[i][u] - 'a'][s[i - 1][u] - 'a']) {
        puts("Impossible");
        exit(0);
      }
      go(u + 1, last, i - 1);
      last = i;
    }
    used[s[i][u] - 'a'] = 1;
  }
  go(u + 1, last, r);
}

bool cmp(int u, int v) {
  return a[u][v];
}

int main() {
  //freopen("key.inp", "r", stdin);
  //freopen("key.out", "w", stdout);
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%s", s[i]);
  }
  go(0, 1, n);
  for (int k = 0; k < 26; k++) {
    for (int i = 0; i < 26; i++) {
      for (int j = 0; j < 26; j++) {
        if (a[i][k] && a[k][j]) {
          a[i][j] = 1;
          if (a[j][i]) {
            puts("Impossible");
            return 0;
          }
        }
      }
    }
  }
  for (int i = 0; i < 26; i++) {
    for (int j = 0; j < 26; j++) {
      if (a[i][j]) {
        deg[j]++;
      }
    }
  }
  vector <int> q;
  for (int i = 0; i < 26; i++) {
    if (!deg[i]) {
      q.push_back(i);
    }
  }
  for (int i = 0; i < q.size(); i++) {
    printf("%c", 'a' + q[i]);
    for (int j = 0; j < 26; j++) {
      if (a[q[i]][j]) {
        if (--deg[j] == 0) {
          q.push_back(j);
        }
      }
    }
  }
//  for (int i =1; i <= n; i++) {
//    for (int j = 0; j < strlen(s[i]); j++) {
//      char foo = s[i][j];
//      for (int k = 0; k < 26; k++) {
//        if (x[k] == foo) {
//          cout << (char)(k + 'a');
//          break;
//        }
//      }
//    }
//    cout << endl;
//  }
  return 0;
}