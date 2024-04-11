#include <bits/stdc++.h>

using namespace std;

const int N = 200020;

int cnt[N][2];

int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  string a, b;
  cin >> a >> b;

  for(int i = 0; i < a.size(); ++i) {
    ++cnt[i][a[i] - '0'];
  }

  for(int i = 1; i < a.size(); ++i) {
    cnt[i][0] += cnt[i - 1][0];
    cnt[i][1] += cnt[i - 1][1];
  }

  long long ans = 0;

  for(int i = 0; i < b.size(); ++i) {
    int r = min(i, (int)a.size() - 1);
    int l = max(0, (int)a.size() + i - (int)b.size());


    int x = 1 - (b[i] - '0');
    ans += cnt[r][x] - (l == 0 ? 0 : cnt[l - 1][x]);
  }

  cout << ans;

  return 0;
}