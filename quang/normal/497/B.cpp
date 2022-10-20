#include <bits/stdc++.h>
#define Task "B"
#define fi freopen(Task".inp", "r", stdin)
#define fo freopen(Task".out", "w", stdout)

using namespace std;

const int N = 100100;

int n;
int a[N], s1[N], s2[N];
vector <pair<int, int> > ans;

int Get1(int sl) {
  int res = lower_bound(s1, s1 + n + 2, sl) - s1;
  return res;
}

int Get2(int sl) {
  int res = lower_bound(s2, s2 + n + 2, sl) - s2;
  return res;
}

void Go(int u) {
  int vt = 0;
  int win1 = 0, win2 = 0, cuoi = 0;
  while(vt < n) {
    int vt1 = Get1(s1[vt] + u);
    int vt2 = Get2(s2[vt] + u);
    if(vt1 == vt2) return;
    if(vt1 < vt2) {
      win1++;
      cuoi = 1;
      vt = vt1;
    }
    else {
      win2++;
      cuoi = 2;
      vt = vt2;
    }
  }
  if(cuoi == 1 && win1 > win2) ans.push_back(make_pair(win1, u));
  if(cuoi == 2 && win1 < win2) ans.push_back(make_pair(win2, u));
}

int main() {
  ios_base::sync_with_stdio(0);
  //fi, fo;
  cin >> n;
  for(int i = 1; i <= n; i++) cin >> a[i];
  s1[0] = s2[0] = 0;
  for(int i = 1; i <= n; i++) {
    s1[i] = s1[i - 1] + (a[i] == 1);
    s2[i] = s2[i - 1] + (a[i] == 2);
  }
  s1[n + 1] = s2[n + 1] = 123456789;
  for(int i = 1; i <= n; i++)
    Go(i);
  sort(ans.begin(), ans.end());
  cout << ans.size() << endl;
  for(int i = 0; i < (int)ans.size(); i++)
    cout << ans[i].first << " " << ans[i].second << endl;
  return 0;
}