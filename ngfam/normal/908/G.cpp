#include<bits/stdc++.h>
#define int long long

using namespace std;

const int N = 707;
const int mod = 1e9 + 7;

string s;

int cnt[10];
int pw10[N];
int f[10][N][N];

void add(int &a, int b) {
  (a += b) %= mod;
}

void ins(int c, int val) {
  for(int d = c; d >= 0; --d) cnt[d] += val;
}

main() {
  if(fopen("inp", "r")) freopen("inp", "r", stdin);
  for(int i = 1; i < 10; ++i) {
    f[i][0][0] = 1;
    for(int j = 0; j < N - 1; ++j) {
      for(int k = 0; k <= j; ++k) {
        add(f[i][j + 1][k], f[i][j][k] * i);
        add(f[i][j + 1][k + 1], f[i][j][k] * (10 - i));
      }
    }
  }


  pw10[0] = 1;
  for(int i = 1; i < N; ++i) {
    pw10[i] = (pw10[i - 1] * 10 + 1) % mod;
  }
  int ans = 0;

  cin >> s;
  for(int i = 0; i < s.size(); ++i) {
    for(int c = 0; c < s[i] - '0'; ++c) {
      ins(c, 1);
      int rem = s.size() - i - 1;
      for(int d = 1; d < 10; ++d) {
        for(int take = (cnt[d] == 0); take <= rem; ++take) {
          add(ans, f[d][rem][take] * pw10[take + cnt[d] - 1]);
        }
      }
      ins(c, -1);
    }
    ins(s[i] - '0', 1);
  }

  sort(s.begin(), s.end());

  add(ans, s.back() - '0');
  for(int i = 0; i + 1 < s.size(); ++i) {
    add(ans, (s[i] - '0') * (pw10[s.size() - i - 1] - pw10[s.size() - i - 2]));
  }


  cout << (ans + mod) % mod;

  return 0;
}