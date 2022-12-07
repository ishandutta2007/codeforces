#include<bits/stdc++.h>

using namespace std;

const int MAXK = 808;
const int MAXN = 4040;

int readInt () {
	bool minus = false;
	int result = 0;
	char ch;
	ch = getchar();
	while (true) {
		if (ch == '-') break;
		if (ch >= '0' && ch <= '9') break;
		ch = getchar();
	}
	if (ch == '-') minus = true; else result = ch-'0';
	while (true) {
		ch = getchar();
		if (ch < '0' || ch > '9') break;
		result = result*10 + (ch - '0');
	}
	if (minus)
		return -result;
	else
		return result;
}

int n, k;
int a[MAXN][MAXN];

int get(int i, int j) {
  return (a[j][j] - a[i - 1][j] - a[j][i - 1] + a[i - 1][i - 1]) / 2;
}

int f[MAXN][MAXK];

void solve(int j, int l, int r, int ll, int rr) {
  if(l > r) return;
  int mid = (l + r) >> 1;

  int best = ll;
  for(int t = ll; t <= min(rr, mid); ++t) {
    int cst = get(t, mid) + f[t - 1][j - 1];
    if(f[mid][j] > cst) {
      f[mid][j] = cst;
      best = t;
    }
  }

  solve(j, l, mid - 1, ll, best);
  solve(j, mid + 1, r, best, rr);
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  n = readInt(); k = readInt();

  for(int i = 1; i <= n; ++i) {
    for(int j = 1; j <= n; ++j) {
      a[i][j] = readInt();
//      cin >> a[i][j];
      a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
    }
  }

  memset(f, 60, sizeof f);
  f[0][0] = 0;

  for(int i = 1; i <= k; ++i) {
    solve(i, 1, n, 1, n);
  }

  cout << f[n][k] << endl;

  return 0;
}