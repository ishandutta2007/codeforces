#include <bits/stdc++.h>
#define left roadto2k4
#define right beforeMarch
 
using namespace std;
 
const int N = 200010;
const long long mod = 1e9 + 7;
 
int n; 
int a[N];
int left[N];
int right[N];
int whatever[N];
long long sum[N];
 
struct SegmentTree{
  
  #define mid ((l + r) >> 1)
  
  int T[N << 2];
  int lazy[N << 3];
 
  void push(int x, int l, int r) {
    if(lazy[x]) {
      T[x] = 1LL * lazy[x] * (r - l + 1) % mod;
      lazy[x + x] = lazy[x];
      lazy[x + x + 1] = lazy[x];
    }
    lazy[x] = 0;
  }
  
  void modify(int x, int l, int r, int u, int v, int val) {
    push(x, l, r);
    if(l > v || r < u) return;
    if(l >= u && r <= v) {
      lazy[x] = val;
      push(x, l, r);
      return;
    }
    modify(x + x, l, mid, u, v, val);
    modify(x + x + 1, mid + 1, r, u, v, val);
    T[x] = T[x + x] + T[x + x + 1];
    T[x] %= mod;
  }
  
  long long query(int x, int l, int r, int u, int v){
    push(x, l, r);
    if(l > v || r < u) return 0;
    if(l >= u && r <= v) return T[x];
    long long ret = query(x + x, l, mid, u, v) + query(x + x + 1, mid + 1, r, u, v);
    T[x] = T[x + x] + T[x + x + 1];
    T[x] %= mod; 
    return ret % mod;
  }
  
  #undef mid
}Tmax, Tmin;
 
int main(){
 
  scanf("%d", &n);
  for(int i = 1; i <= n; ++i) {
    scanf("%d", a + i);
    sum[i] = sum[i - 1] + i;
    sum[i] %= mod;
  }
 
  map < int, int > f;
  for(int i = 1; i <= n; ++i) {
    left[i] = f[a[i]] + 1;
    f[a[i]] = i;
  }
  
  f.clear();
  for(int i = n; i >= 1; --i) {
    right[i] = (f[a[i]] ? f[a[i]] - 1 : n);
    whatever[i] = (f[a[i]] ? f[a[i]] : n + 1);
    f[a[i]] = i;
  }
  
  int to = n;
  long long maxmin = 0, iright = 0, jleft = 0, ij = 0, answer = 0;
  deque < int > dqmax, dqmin;
  
  for(int i = n; i >= 1; --i){
    /// Fix the deques
    //ij = maxmin = iright = jleft = 0;
    iright = ij = 0;
    while(!dqmax.empty() && left[i] >= left[dqmax.back()]) {
      int j = dqmax.back(); dqmax.pop_back(); 
      int last = (dqmax.empty() ? to : dqmax.back() - 1);
      jleft += 1LL * (left[i] - left[j]) * (sum[last] - sum[j - 1] + mod);
      jleft %= mod;      
      maxmin += 1LL * Tmin.query(1, 1, n, j, last) * (left[i] - left[j]);
      maxmin %= mod;
      Tmax.modify(1, 1, n, j, last, left[i]);
    }
    
    while(!dqmin.empty() && right[i] <= right[dqmin.back()]) {
      int j = dqmin.back(); dqmin.pop_back(); 
      int last = (dqmin.empty() ? to : dqmin.back() - 1);
      maxmin += 1LL * Tmax.query(1, 1, n, j, last) * (right[i] - right[j]);
      maxmin = (maxmin % mod + mod) % mod;
      Tmin.modify(1, 1, n, j, last, right[i]);
    }
    
    /// Add i to the interval 
    
    maxmin += 1LL * left[i] * right[i];
    maxmin %= mod;
    jleft += 1LL * i * left[i];
    jleft %= mod;
    dqmax.push_back(i);
    dqmin.push_back(i);
    Tmax.modify(1, 1, n, i, i, left[i]);
    Tmin.modify(1, 1, n, i, i, right[i]);
    
    
    /// Fix the interval
    
    while(to >= whatever[i]) {
      maxmin -= 1LL * Tmin.query(1, 1, n, to, to) * Tmax.query(1, 1, n, to, to);
      maxmin = (maxmin % mod + mod) % mod;
      jleft -= 1LL * to * Tmax.query(1, 1, n, to, to);
      jleft = (jleft % mod + mod) % mod;
      if(dqmax.front() == to) dqmax.pop_front();
      if(dqmin.front() == to) dqmin.pop_front();
      --to;
    }
    
    /// Calculate iright andd ij
    
    ij += 1LL * i * (sum[to] - sum[i - 1] + mod); ij %= mod;
    iright += 1LL * i * (Tmin.query(1, 1, n, i, to)); iright %= mod;
    //return 0;
  
 //   cout << i << " " << iright << " " << jleft << " " << ij << " " << maxmin << " " << to << " " << sum[to] - sum[i - 1] << endl;
    //cout << (iright + jleft - ij - maxmin + mod * mod) % mod << endl;  
    answer += (iright + jleft - ij - maxmin + mod * mod) % mod; 
    answer %= mod;
    
   // cout << answer << endl;
    
  }
  
  cout << answer % mod << endl;
  
	return 0;
}
 
/// (i - left) * (right - j) = i * right + j * left - i * j - left * right