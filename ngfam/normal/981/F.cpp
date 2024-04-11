#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 1000020;

int n, L;
int a[N];
int b[N];
int s[N];

bool check(int x) {

  memset(s, 0, sizeof s);
  for(int i = n + 1; i <= n + n; ++i) {
    int l = lower_bound(b + 1, b + n + n + n + 1, a[i] - x) - b;
    int r = upper_bound(b + 1, b + n + n + n + 1, a[i] + x) - b - 1;
    if(l > r) {
      continue;
    }
    l = i - l + n + n;
    r = i - r + n + n;
    ++s[r];
    --s[l + 1];
  }
  for(int i = 0; i < N; ++i) {
    if(i > 0) {
      s[i] += s[i - 1];
    }
    if(s[i] >= n) {
      return true;
    }
  }
  return false;
}

main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  cin >> n >> L;
  for(int i = 1; i <= n; ++i) {
    cin >> a[i];
  }

  for(int i = 1; i <= n; ++i) {
    cin >> b[i];
  }

  sort(a + 1, a + n + 1);
  sort(b + 1, b + n + 1);

  for(int i = n + 1; i <= 3 * n; ++i) {
    a[i] = a[i - n] + L;
    b[i] = b[i - n] + L;
  }

  int low = 0, high = L / 2, ans = L;
  while(low <= high) {
    int mid = (low + high) >> 1;
    if(check(mid)) {
      ans = mid;
      high = mid - 1;
    }
    else {
      low = mid + 1;
    }
  }

  cout << ans;

  return 0;
}