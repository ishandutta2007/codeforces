#include <bits/stdc++.h>
#include <variant>

#define rep2(i,k,n) for(i64 i=(i64)(k);i<(i64)(n);i++)
#define rep(i,n) rep2(i,0,n)
#define all(x) begin(x),end(x)

using namespace std;
using namespace std::string_literals;

using i32 = int32_t;
using i64 = int64_t;
using f64 = double;
using f80 = long double;
using vi32 = vector<i32>;
using vi64 = vector<i64>;

struct bucket {
  bucket(const vi64& data) : data(data), psum(), chmax(0), th(size(data)) {}
  void reset() {
    psum.assign(size(data)+1, 0);
    partial_sum(all(data), begin(psum)+1);
    th = lower_bound(all(data), chmax, greater<i64>()) - begin(data);
  }
  i64 get_sum() const {
    return psum[th] + chmax * (size(data) - th);
  }
  i64 operator[](size_t idx) {
    return max(chmax, data[idx]);
  }
  vi64 data;
  vi64 psum;
  i64 chmax;
  i64 th;
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  i64 n,q;
  cin>>n>>q;
  vi64 a(n);
  rep(i,n) cin>>a[i];
  constexpr i64 bkt_size = 500;
  i64 m = (n + bkt_size - 1) / bkt_size;
  vector<bucket> vb;
  rep(i,m) {
    i64 from = i * bkt_size;
    i64 to = min((i+1) * bkt_size, n);
    vi64 sub(begin(a)+from, begin(a)+to);
    vb.emplace_back(sub);
    vb.back().reset();
  }
  rep(i,q) {
    i64 t,x,y;
    cin>>t>>x>>y;
    if (t == 1) {
      i64 xb = x / bkt_size;
      rep(j,xb) {
        vb[j].chmax = max(vb[j].chmax, y);
        vb[j].th = lower_bound(all(vb[j].data), vb[j].chmax, greater<i64>()) - begin(vb[j].data);
      }
      i64 rem = x % bkt_size;
      rep(j,rem) {
        vb[xb].data[j] = max(vb[xb].data[j], y);
      }
      vb[xb].reset();
    } else {
      --x;
      i64 xb = x / bkt_size;
      i64 rem = x % bkt_size;
      i32 cnt = 0;
      rep2(k, rem, size(vb[xb].data)) {
        if (vb[xb][k] <= y) {
          y -= vb[xb][k];
          ++cnt;
        }
      }
      rep2(j,xb+1,m) {
        i64 s = vb[j].get_sum();
        if (s <= y) {
          y -= s;
          cnt += size(vb[j].data);
        } else if (y < vb[j][size(vb[j].data)-1]) {
          continue;
        } else {
          rep(k,size(vb[j].data)) {
            if (vb[j][k] <= y) {
              y -= vb[j][k];
              ++cnt;
            }
          }
        }
      }
      cout<<cnt<<"\n";
    }
  }
  return 0;
}