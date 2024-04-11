#include<bits/stdc++.h>

using namespace std;

const int LG = 20;
const int MAXN = 105;
const int MAXM = 1 << LG;

int n, m, b;
long long f[2][MAXM];


int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  cin >> n >> m >> b;

  vector<pair<int, pair<int, int>>> a(n);

  for(auto &p : a) {
    int k;
    cin >> p.second.second >> p.first >> k;
    while(k--) {
      int x; cin >> x;
      p.second.first |= (1 << (--x));
    }
  }

  sort(a.begin(), a.end());

  memset(f[0], 60, sizeof f[0]);
  f[0][0] = 0;

  long long ans = f[0][1];

  int flag = 0;
  for(auto &p : a) {
    int nwflag = 1 - flag;
    memset(f[nwflag], 60, sizeof f[nwflag]);
    for(int msk = 0; msk < (1 << m); ++msk) {
      int newmask = msk | (p.second.first);
      f[nwflag][newmask] = min(f[nwflag][newmask], f[flag][msk] + p.second.second);
      f[nwflag][msk] = min(f[nwflag][msk], f[flag][msk]);
    }

    ans = min(ans, f[nwflag][(1 << m) - 1] + 1LL * p.first * b);
    swap(flag, nwflag);
  }

  if(ans > (long long)2e18) {
    cout << -1;
    return 0;
  }


  cout << ans << endl;

  return 0;
}