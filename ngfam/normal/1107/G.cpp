#include <bits/stdc++.h>

using namespace std;

const long long N = 300030;

struct SegmentTreeMax{
  long long it[N << 2];
  long long lazy[N << 3];

  #define mid ((l + r) >> 1)

  void Init(){
    memset(it, 0, sizeof it);
    memset(lazy, 0, sizeof lazy);
  }

  void push(long long x){
    it[x] += lazy[x];
    lazy[x + x] += lazy[x];
    lazy[x + x + 1] += lazy[x];
    lazy[x] = 0;
  }

  void update(long long x, long long l, long long r, long long u, long long v, long long val){
    if(v < u) return;
    push(x);
    if(l > v || r < u) return;
    if(l >= u && r <= v){
      lazy[x] += val;
      push(x);
      return;
    }
    update(x + x, l, mid, u, v, val);
    update(x + x + 1, mid + 1, r, u, v, val);
    it[x] = max(it[x + x], it[x + x + 1]);  
  }

  void modify(long long x, long long l, long long r, long long pos, long long val){
    push(x);
    if(l > pos || r < pos) return;
    it[x] = max(it[x], val);
    if(l == r) {
      it[x] = val;
      return;
    }
    modify(x + x, l, mid, pos, val);
    modify(x + x + 1, mid + 1, r, pos, val);
    it[x] = max(it[x + x], it[x + x + 1]);
  }

  long long query(long long x, long long l, long long r, long long u, long long v){
    push(x);
    if(u > v) return -3e18;
    if(l > v || r < u) return -3e18;
    if(l >= u && r <= v) return it[x];
    long long ret = max(query(x + x, l, mid, u, v), query(x + x + 1, mid + 1, r, u, v));
    it[x] = max(it[x + x], it[x + x + 1]);
    return ret;
  }
}seg;

main(){
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL); cout.tie(NULL);

  long long n, a;
  cin >> n >> a;

  vector < long long > c(n + 1), d(n + 1), sum(n + 1);
  for(long long i = 1; i <= n; ++i) {
    cin >> d[i] >> c[i];
    sum[i] = sum[i - 1] + c[i];
  }

  long long ans = max(0LL, a - c[1]);

  stack < long long > st;

  #define cost(x) (1LL * (d[x] - d[x + 1]) * (d[x] - d[x + 1]))

  /// a * r - a * (l - 1) - sum[r] + sum[l - 1] - cost


  for(long long i = 2; i <= n; ++i) {
    
    seg.modify(1, 1, n, i - 1, -a * (i - 2) - cost(i - 1) + sum[i - 2]);

    long long last = i - 1;
    while(!st.empty()) {
      if(cost(i - 1) >= cost(st.top())) {
        //seg.update(1LL, 1LL, n, st.top(), last - 1, st.top(), cost(i - 1) - cost(st.top()));
        int pos = 1, save = st.top();
        st.pop();
        if(st.size() > 0) pos = st.top() + 1;
        seg.update(1, 1, n, pos, last - 1, cost(save) - cost(i - 1));
        last = pos;
      }
      else break;
    }

    st.push(i - 1);

    ans = max(ans, a - c[i]);
    ans = max(ans, a * i + seg.query(1, 1, n, 1, i - 1) - sum[i]);
  }

  cout << ans << endl;
	
  return 0;
}