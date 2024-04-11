#include<bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  int ntest; cin >> ntest;
  while(ntest--) {
    int n, m; cin >> n >> m;

    int each = (n - m) / (m + 1);
    int rem = (n - m) % (m + 1);

    long long tot = 1LL * n * (n + 1) / 2;
    tot -= (1LL * each * (each + 1) / 2) * (m + 1);
    tot -= 1LL * (each + 1) * rem;
    cout << tot << "\n";
  }

  return 0;
}