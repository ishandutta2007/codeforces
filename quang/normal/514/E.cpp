#include <bits/stdc++.h>

#define Task "E"
#define fi freopen(Task".inp", "r", stdin)
#define fo freopen(Task".out", "w", stdout)

using namespace std;

const int MOD = 1000000007;

int cnt[101], sum[111], dp[111];
vector<vector<int> > A(1, vector<int>(101, 0));
vector<vector<int> > B(101, vector<int>(101, 0));

vector <vector<int> > MatrixMul(const vector <vector<int> > &u, const vector <vector<int> > &v) {
  vector <vector<int> > ans(u.size(), vector<int>(v[0].size(), 0));
  for (int i = 0; i < u.size(); i++) {
    for (int j = 0; j < v[0].size(); j++) {
      for (int k = 0; k < u[0].size(); k++) {
        ans[i][j] = (ans[i][j] + (1ll * u[i][k] * v[k][j]) % MOD) % MOD;
      }
    }
  }
  return ans;
}

vector <vector<int> > MatrixPow(vector <vector<int> > u, long long v) {
  vector <vector<int> > ans(u.size(), vector<int>(u.size(), 0));
  for (int i = 0; i < u.size(); i++) {
    ans[i][i] = 1;
  }
  while (v) {
    if (v & 1) {
      ans = MatrixMul(ans, u);
    }
    u = MatrixMul(u, u);
    v /= 2;
  }
  return ans;
}

void Init() {
  dp[0] = sum[0] = 1;
  for (int i = 1; i <= 100; i++) {
    for (int j = i; j; j--) {
      dp[i] = (dp[i] + (1ll * dp[i - j] * cnt[j]) % MOD) % MOD;
    }
    sum[i] = (sum[i - 1] + dp[i]) % MOD;
  }
  for (int i = 0; i <= 99; i++) {
    A[0][i] = dp[i + 1];
  }
  A[0][100] = sum[100];
  for (int i = 0; i < 99; i++) {
    B[i + 1][i] = 1;
    B[i][99] = B[i][100] = cnt[100 - i];
  }
  B[100][100] = 1;
  B[99][99] = B[99][100] = cnt[1];
}

int main() {
  ios_base::sync_with_stdio(0);
  //fi, fo;
  int n, x;
  cin >> n >> x;
  while (n--) {
    int u;
    cin >> u;
    cnt[u]++;
  }
  Init();
  if (x <= 100) {
    cout << sum[x] << endl;
  } else {
    cout << MatrixMul(A, MatrixPow(B, x - 100))[0][100];
  }
  return 0;
}