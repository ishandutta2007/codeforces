#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false); 
  cin.tie(NULL); cout.tie(NULL); 

  multiset < int > students;

  int n, m; cin >> n >> m;
  int sum = 0;

  vector < int > cnt(101, 0);

  for(int i = 1; i <= n; ++i) {
    int x; cin >> x;
    int cursum = sum, ans = 0;
    for(int j = 100; j >= 1; --j) {
      int take = min(cnt[j], max(0, (cursum - (m - x) + j - 1) / j));
      cursum -= j * take;
      ans += take;
    }
    cout << ans << " ";
    ++cnt[x];
    sum += x;
  }

  return 0;
}