#include <bits/stdc++.h>

using namespace std;

const int N = 1000010;
const int mod = 1e9 + 7;

int f[N];

int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  int n, m;
  cin >> n >> m;

  f[0] = 1;
  f[1] = 1;
  for(int i = 2; i <= max(n, m); ++i) {
    f[i] = f[i - 1] + f[i - 2];
    if(f[i] >= mod) f[i] -= mod;
  }

  cout << (f[n] + f[m] - 1) * 2LL % mod << endl;

  return 0;
}