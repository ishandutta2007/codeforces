#include <bits/stdc++.h>

using namespace std;

const int N = (1 << 21);
const int rev = N - 1;

int n;
int a[N];
int f[N];

int main(){
	ios_base::sync_with_stdio(false); 
  cin.tie(NULL); cout.tie(NULL); 

  cin >> n;
  for(int i = 1; i <= n; ++i) {
    cin >> a[i];
    ++f[rev ^ a[i]];
  }

  for(int i = 0; i < 21; ++i) {
    for(int mask = 0; mask < (1 << 21); ++mask) {
      if(mask & (1 << i)) {
        f[mask] += f[mask ^ (1 << i)];
      }
    }
  }

  int res = 0;

  for(int i = 1; i <= n; ++i) {
    int cur = 0, ans = 0;
    for(int b = 20; b >= 0; --b) {
      if(a[i] & (1 << b)) {
        ans += (1 << b);
        continue;
      } 
      cur += (1 << b);
      if(f[rev ^ cur] < 2) {
        cur -= (1 << b);
      }
      else {
        ans += (1 << b);
      }
    }
    res = max(res, ans);
  }

  cout << res;

  return 0;
}