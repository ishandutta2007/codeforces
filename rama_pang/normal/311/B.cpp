#include <bits/stdc++.h>
using namespace std;
using lint = long long;

const int MAXN = 100005;

int N, M, P;
lint D[MAXN], C[MAXN];
lint pref[MAXN];

int H[MAXN], T[MAXN];

lint DP[2][MAXN];

void dnc(int n, int l, int r, int optl, int optr) {
  if (l > r) {
    return;
  }
  int mid = (l + r) / 2;
  lint best = 1e18, opt = -1;
  for (int k = optl; k <= mid && k <= optr; k++) {
    lint cur = DP[n ^ 1][k - 1] + 1ll * (mid - k + 1) * C[mid] - (pref[mid] - pref[k - 1]);
    if (best > cur) {
      best = cur;
      opt = k;
    }
  }
  DP[n][mid] = best;
  dnc(n, l, mid - 1, optl, opt);
  dnc(n, mid + 1, r, opt, optr);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  cin >> N >> M >> P;
  for (int i = 2; i <= N; i++) {
    cin >> D[i];
    D[i] += D[i - 1];
  }

  for (int i = 1; i <= M; i++) {
    cin >> H[i] >> T[i];
    C[i] = T[i] - D[H[i]];
  }
  sort(C + 1, C + M + 1); // time the cat is leaving for hill. 
  for (int i = 1; i <= M; i++) {
    pref[i] = pref[i - 1] + C[i];
  }
  for (int i = 1; i <= M; i++) {
    DP[0][i] = 1e18;
  }
  // cout << "COST: "; for (int i = 1; i <= M; i++) cout << C[i] << " \n"[i == M];
  for (int i = 1; i <= P; i++) {
    dnc(i & 1, 1, M, 1, M);
  }

  cout << DP[P & 1][M] << "\n";
  return 0;
}