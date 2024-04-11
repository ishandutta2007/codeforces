#include <bits/stdc++.h>

using namespace std;

const int N = 100010;
const long long maxval = -1e18;

int n, m;
int a[N];
int val[N];
long long f[N];

int main(){
  #ifdef pts
    freopen("1.inp", "r", stdin);
  #endif // pts
  scanf("%d%d", &n, &m);
  for(int i = 1; i <= n; ++i){
    scanf("%d", val + i);
  }
  for(int i = 1; i <= n; ++i){
    scanf("%d", a + i);
  }
  while(m--){
    int u, v;
    scanf("%d%d", &u, &v);
    memset(f, 0, sizeof f);
    int good = N - 1, bad = N - 2;
    fill(f, f + N - 5, maxval);
    for(int i = 1; i <= n; ++i){
      long long x = maxval, y = maxval;
      if(good == a[i]){
        x = f[good] + 1LL * val[i] * u;
      }
      else{
        x = f[good] + 1LL * val[i] * v;
      }
      if(bad == a[i]){
        y = f[bad] + 1LL * val[i] * u;
      }
      else{
        y = f[bad] + 1LL * val[i] * v;
      }
      long long z = f[a[i]] + 1LL * val[i] * u;
      if(f[a[i]] == maxval){
        z = f[a[i]] + 1LL * val[i] * v;
      }
      f[a[i]] = max(f[a[i]], max(x, max(y, z)));
      if(f[good] < f[bad]){
        swap(good, bad);
      }
      if(good == a[i] || bad == a[i]){
        continue;
      }
      if(f[a[i]] >= f[good]){
        bad = good;
        good = a[i];
      }
      else{
        if(f[a[i]] >= f[bad]){
          bad = a[i];
        }
      }
    }
    printf("%lld\n", f[good]);
  }
  return 0;
}