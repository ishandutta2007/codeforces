#include <bits/stdc++.h>
using namespace std;

const int K = 1001;
const int LN = 30;
const int MOD = 7340033;

vector<int> ans[LN];

vector<int> multiply(vector<int> P, vector<int> Q) {
  vector<int> ret(P.size() + Q.size() - 1);
  for (int i = 0; i < P.size(); ++i) for (int j = 0; j < Q.size(); ++j) {
    ret[i + j] = (1LL * P[i] * Q[j] + ret[i + j]) % MOD;
  }
  if (ret.size() > K) ret.resize(K);
  return ret;
}

void init() {
  vector<int> P = {1};
  ans[0] = P;
  for (int i = 1; i < LN; ++i) {
    vector<int> nP = multiply(P, P);
    P = multiply(nP, nP);
    P.push_back(0);
    for (int j = (int) P.size() - 1; j > 0; --j) {
      P[j] = P[j - 1];
    }

    ans[i] = P;
  }
}

int main() {
  init();
  int q;
  scanf("%d", &q);
  while (q--) {
    int n, k;
    scanf("%d %d", &n, &k);
    int depth = 0;
    while (n > 1 && n % 2 == 1) ++depth, n >>= 1;
    printf("%d\n", k < ans[depth].size() ? ans[depth][k] : 0);
  }
  return 0;
}