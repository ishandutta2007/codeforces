#include<bits/stdc++.h>

using namespace std;

const char DUMMY = '.';

vector<int> manacher(string s) {
	int n = s.size() * 2 - 1;
	vector <int> f = vector <int>(n, 0);
	string a = string(n, DUMMY);
	for (int i = 0; i < n; i += 2) a[i] = s[i / 2];
	int l = 0, r = -1, center, res = 0;
	for (int i = 0, j = 0; i < n; i++) {
		j = (i > r ? 0 : min(f[l + r - i], r - i)) + 1;
		while (i - j >= 0 && i + j < n && a[i - j] == a[i + j]) j++;
		f[i] = --j;
		if (i + j > r) {
			r = i + j;
			l = i - j;
		}
    int len = (f[i] + i % 2) / 2 * 2 + 1 - i % 2;
		if (len > res) {
			res = len;
			center = i;
		}
	}
	return f;
}

const int maxn = 4000005;

int n;
string s;
int ans[maxn];

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  cin >> n >> s;

  string newS;
  for(int i = 0; i < s.size(); ++i) {
    newS += s[i];
    newS += s[n - i - 1];
  }

  vector<int> f = manacher(newS);

  memset(ans, -1, sizeof ans);

  int pter = f.size() / 2;
  for(int i = f.size() / 2 - 1; i > 0; i -= 2) {
    if(i % 2 != 1) --i;
    if((i / 2) % 2 == 1) continue;
    while(pter >= i) --pter;
    while(pter >= i - f[i]) {
      ans[pter--] = (i - pter + 1) / 2;
    }
  }
  for(int i = 0; i + i < n; ++i) {
    cout << ans[i << 2] << " ";
  }

  return 0;
}