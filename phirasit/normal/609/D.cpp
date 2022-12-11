#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 200010;

long long val1[N], val2[N];
vector<int> v[3];
int a[N], b[N], t[N], c[N];
int n, m, k;

long long s;

int ans[N];

int cmpC(int idx1, int idx2) {
  return c[idx1] < c[idx2];
}
bool check(int idx) {
  int mn1 = 0, mn2 = 0;
  for(int i = 0;i <= idx;i++) {
    if(a[i] < a[mn1]) mn1 = i;
    if(b[i] < b[mn2]) mn2 = i;
  }
  for(int i = 0;i < v[1].size();i++) {
    val1[i] = (i > 0 ? val1[i-1] : 0ll);
    val1[i] += (long long) a[mn1] * c[v[1][i]];
  }
  for(int i = 0;i < v[2].size();i++) {
    val2[i] = (i > 0 ? val2[i-1] : 0ll);
    val2[i] += (long long) b[mn2] * c[v[2][i]];
  }
  int pos = -2;
  for(int i = -1;i < (int)v[1].size() and i < k;i++) {
    int i2 = k - (i+1) - 1;
    if(i2 >= (int)v[2].size()) continue;
    long long sum = (i >= 0 ? val1[i] : 0ll) + (i2 >= 0 ? val2[i2] : 0ll);
    if(sum <= s) {
      pos = i;
      break;
    }
  }

  if(pos == -2) return false;

  for(int i = 0;i <= pos;i++) {
    ans[i] = v[1][i];
  }
  for(int i = 0;i <= k - pos - 2;i++) {
    ans[i+pos+1] = v[2][i];
  }

  return true;
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m >> k >> s;
  for(int i = 0;i < n;i++) cin >> a[i];
  for(int i = 0;i < n;i++) cin >> b[i];
  for(int i = 0;i < m;i++) cin >> t[i] >> c[i];
  for(int i = 0;i < m;i++) v[t[i]].push_back(i);
  sort(v[1].begin(), v[1].end(), cmpC);
  sort(v[2].begin(), v[2].end(), cmpC);
  if(!check(n-1)) {
    cout << -1 << endl;
    return 0;
  }
  int lo = 0, hi = n-1;
  while(lo < hi) {
    int mid = (lo + hi) / 2;
    if(check(mid)) {
      hi = mid;
    }else {
      lo = mid + 1;
    }
  }
  check(lo);
  cout << (lo+1) << endl;
  int mn1 = 0, mn2 = 0;
  for(int i = 0;i <= lo;i++) {
    if(a[i] < a[mn1]) mn1 = i;
    if(b[i] < b[mn2]) mn2 = i;
  }
  for(int i = 0;i < k;i++) {
    cout << (ans[i]+1) << " " << ((t[ans[i]] == 1 ? mn1 : mn2) + 1) << endl;
  }
  return 0;
}