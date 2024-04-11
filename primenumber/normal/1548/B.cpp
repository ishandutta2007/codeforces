#include <bits/stdc++.h>
#include <variant>

#define rep2(i,k,n) for(i64 i=(i64)(k);i<(i64)(n);i++)
#define rep(i,n) rep2(i,0,n)
#define all(x) begin(x),end(x)
#ifdef ENV_LOCAL
#define dump if (1) cerr
#else
#define dump if (0) cerr
#endif

using namespace std;
using namespace std::string_literals;

using i32 = int32_t;
using i64 = int64_t;
using f64 = double;
using f80 = long double;
using vi32 = vector<i32>;
using vi64 = vector<i64>;

//using namespace harudake;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  i32 t;
  cin>>t;
  while(t--) {
    i32 n;
    cin>>n;
    vi64 a(n);
    rep(i,n) cin>>a[i];
    --n;
    vi64 d(n);
    rep(i,n) d[i] = abs(a[i] - a[i+1]);
    vector<vi64> v;
    rep(i,20) {
      v.push_back(d);
      vi64 nxt(n);
      rep(j,n) {
        i32 k = j + (1 << i);
        if ((k + (1 << i)) > n) {
          nxt[j] = 1;
        } else {
          nxt[j] = gcd(d[j], d[k]);
        }
      }
      swap(d, nxt);
    }
    i32 ans = 0;
    rep(i,n) {
      i64 mxj = 20;
      rep(j,20) {
        if (v[j][i] == 1) {
          mxj = j;
          break;
        }
      }
      if (mxj == 0) continue;
      //dump<<i<<" "<<mxj<<endl;
      --mxj;
      i32 sz = 1 << mxj;
      i32 le = sz;
      i32 gt = 2 * sz;
      while (gt - le > 1) {
        i32 mid = (gt + le) / 2;
        //dump<<i<<" "<<mxj<<" "<<mid<<endl;
        if (i+mid-sz < n && gcd(v[mxj][i], v[mxj][i+mid-sz]) > 1) {
          le = mid;
        } else {
          gt = mid;
        }
      }
      ans = max(ans, le);
    }
    cout<<ans+1<<"\n";
  }
  return 0;
}