#include<bits/stdc++.h>
#define left chem
#define right than

using namespace std;

const int maxn = 200005;

int n;
int a[maxn];

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  int ntest; cin >> ntest;
  while(ntest--) {
    cin >> n;
    for(int i = 0; i < n; ++i) {
      cin >> a[i];
    }

    sort(a, a + n);
    n = unique(a, a + n) - a;

    int ans = *max_element(a, a + n);

    for(int i = 1; i < n; ++i) {
      int j = i - 1;
      while(j >= 0 && a[i] % a[j] == 0) j--;
      if(j >= 0) ans = max(ans, a[i] + a[j]);
      if(j < 1) continue;
      int k = j - 1;
      while(k >= 0 && (a[i] % a[k] == 0 || a[j] % a[k] == 0)) --k;
      if(k < 0) continue;
      ans = max(ans, a[i] + a[j] + a[k]);
    }

    cout << ans << endl;
  }

  return 0;
}