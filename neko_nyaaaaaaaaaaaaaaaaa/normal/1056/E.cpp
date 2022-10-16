#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll M[] = {982451653, 1000000009, 998244353, 1000000007};

string s, t;
int n, ans, fi;
ll hs[4][1000007];
ll power[4][1000007];

void init() {
      for (int j = 0; j < 4; j++) {
            hs[j][0] = t[0];
            for (int i = 1; i <= n; i++) {
                  hs[j][i] = (hs[j][i-1]*256 + t[i]) % M[j];
            }

            power[j][0] = 1;
            for (int i = 1; i <= n; i++) {
                  power[j][i] = power[j][i-1]*256 % M[j];
            }
      }
}

int cmp(int l, int r, int x, int y) {
      int len1 = r-l+1;
      int len2 = y-x+1;
      if (len1 != len2) return 0;
      ll ans1, ans2;
      for (int i = 0; i < 4; i++) {
            ans1 = (hs[i][r] - (hs[i][l-1] * power[i][len1]) % M[i] + M[i]*M[i]) % M[i];
            ans2 = (hs[i][y] - (hs[i][x-1] * power[i][len2]) % M[i] + M[i]*M[i]) % M[i];
            if (ans1 != ans2) return 0;
      }
      return 1;
}

int solve(int a, int b) {
      int la = 0, ra = 0, lb = 0, rb = 0;
      la = 1, ra = a;
      lb = a*fi + 1, rb = a*fi + b;
      if (cmp(la, ra, lb, rb)) return 0;

      int petr = 1;
      for (char c: s) {
            if (c == '0') {
                  if (!cmp(petr, petr+a-1, la, ra)) return 0;
                  petr += a;
            } else {
                  if (!cmp(petr, petr+b-1, lb, rb)) return 0;
                  petr += b;
            }
      }
      return 1;
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

      cin >> s >> t;
      n = t.size();
      t = '#' + t;
      init();

      if (s[0] == '1') {
            for (int i = 0; i < s.size(); i++) {
                  if (s[i] == '0') s[i] = '1';
                  else s[i] = '0';
            }
      }
      for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1') {fi = i; break;}
      }

      int z = 0, o = 0;
      for (char c: s) {
            if (c == '0') z++;
            else o++;
      }
      //cout << o << ' ' << z << endl;

      for (int i = 1; i*z < n; i++) {
            int k = n - i*z;
            if (k % o) continue;
            //cout << i << ' ' << k/z << endl;

            ans += solve(i, k/o);
      }
      cout << ans;

	return 0;
}