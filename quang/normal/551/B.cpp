#include <bits/stdc++.h>

using namespace std;

string a, b, c;
int numa[30];
int numb[30], numc[30];

void get(int x, int &slmax) {
  int num[30];
  for (int i = 0; i < 26; i++) {
    num[i] = numa[i] - x * numb[i];
    if (num[i] < 0) {
      slmax = -1;
      return;
    }
  }
  slmax = 123456789;
  for (int i = 0; i < 26; i++) {
    if (numc[i] == 0) {
      continue;
    }
    slmax = min(slmax, num[i] / numc[i]);
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin >> a >> b >> c;
  for (int i = 0; i < a.size(); i++) {
    numa[a[i] - 'a']++;
  }
  for (int i = 0; i < b.size(); i++) {
    numb[b[i] - 'a']++;
  }
  for (int i = 0; i < c.size(); i++) {
    numc[c[i] - 'a']++;
  }
  pair <int, int> ans = make_pair(0, 0);
  for (int i = 0; i <= a.size(); i++) {
    int foo;
    get(i, foo);
    if (foo == -1) {
      break;
    }
    if (foo + i > ans.first + ans.second) {
      ans = make_pair(i, foo);
    }
  }
  //cout << ans.first << " " << ans.second << endl;
  for (int i = 1; i <= ans.first; i++) {
    cout << b;
  }
  for (int i = 1; i <= ans.second; i++) {
    cout << c;
  }
  for (int i = 0; i < 26; i++) {
    int cl = numa[i] - numb[i] * ans.first - numc[i] * ans.second;
    for (int j = 1; j <= cl; j++) {
      cout << (char) (i + 'a');
    }
  }
  return 0;
}