#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n;
pair < int, int > a[N];
int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  cin >> n;
  for(int i = 0; i < n; ++i) {
    int x; cin >> x;
    a[x - 1].first = i;
  }
  for(int i = 0; i < n; ++i) {
    int x; cin >> x;
    a[x - 1].second = i;
  }

  sort(a, a + n);

  int mx = 0, ans = 0;

  for(int i = 0; i < n; ++i) {
    if(a[i].second < mx) ++ans;
    mx = max(a[i].second, mx);
  }

  cout << ans << endl;

  return 0;
}