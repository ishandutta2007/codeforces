#include <bits/stdc++.h>
#include <variant>
#define FOR(i,k,n)  for(int i = (k);i < (n);++i)
#define REP(i,n)    FOR(i,0,n)
#define ALL(x) begin(x),end(x)

using namespace std;
using ll = int64_t;
using vecint = vector<int>;
using vecll = vector<ll>;

struct Data {
  int num;
  Data() : num(0) {;}
  Data(int n) : num(n) {;}
};

inline Data Merge(Data left, Data right) {
  return Data(left.num + right.num);
}

struct SegmentTree {
  int n; vector<Data> data;
  SegmentTree(int N) : n(1 << N), data(n * 2) {}
  Data get(int pos) {
    auto value = data[pos];
    while (pos < 2*n-1) {
      pos = pos / 2 + n;
      value = Merge(value, data[pos]);
    }
    return value;
  }
  void sub(int fr, int to, int node, int la, int ra, Data value) {
    if (ra<=fr || to<=la) return;
    if (fr<=la && ra<=to) {
      data[node] = Merge(data[node], value);
      return;
    }
    sub(fr, to, (node-n)*2+0, la, (la+ra)/2, value);
    sub(fr, to, (node-n)*2+1, (la+ra)/2, ra, value);
  }
  void update(int fr, int to, Data value) { sub(fr, to, 2*n-2, 0, n, value); }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n;
  cin>>n;
  string s;
  cin>>s;
  SegmentTree st(19);
  ll old_apple = -1;
  ll ans = 0;
  ll sum = 0;
  REP(i,n) {
    if (s[i] == '0') {
      old_apple = -1;
    } else {
      int old_len;
      if (old_apple >= 0) {
        old_len = i - old_apple;
      } else {
        old_len = 0;
      }
      int lt = -1;
      int ge = i;
      while (ge - lt > 1) {
        int mid = (ge + lt) / 2;
        int val = st.get(mid).num;
        if (val > old_len) {
          lt = mid;
        } else {
          ge = mid;
        }
      }
      sum += i - ge + 1;
      st.update(ge, i+1, Data(1));
      if (old_apple < 0) old_apple = i;
    }
    ans += sum;
  }
  cout<<ans<<endl;
  return 0;
}