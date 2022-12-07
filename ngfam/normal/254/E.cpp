#include<bits/stdc++.h>

using namespace std;

const int maxn = 405;

int n, k, m;
int a[maxn];


int f[maxn][maxn];
pair<int, int> pre[maxn][maxn];

vector<pair<int, int>> frens[maxn];

bool optimize(int &x, int y) {
  if(x < y) {
    x = y; return true;
  }
  return false;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  #ifndef ngfam
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  cin >> n >> k;
  for(int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  cin >> m;
  for(int id = 0; id < m; ++id) {
    int l, r, w;
    cin >> l >> r >> w;
    for(int i = --l; i < r; ++i) frens[i].emplace_back(w, id + 1);
  }

  for(int i = 0; i < maxn; ++i) {
    sort(frens[i].begin(), frens[i].end());
    for(int j = 0; j < maxn; ++j) f[i][j] = -1e9;
  }

  f[0][0] = 0;
  for(int i = 0; i < n; ++i) {
    for(int j = 0; j < maxn; ++j) {
      int curfood = a[i] + j - k;
      if(optimize(f[i + 1][min(a[i], a[i] - k + j)], f[i][j])) {
        pre[i + 1][min(a[i], a[i] - k + j)] = make_pair(0, j);
      }
      for(int feed = 0; feed < frens[i].size(); feed++){
        curfood -= frens[i][feed].first;
        if(curfood < 0) break;
        int nextfood = min(curfood, a[i]);
        if(optimize(f[i + 1][nextfood], f[i][j] + feed + 1)) {
          pre[i + 1][nextfood] = make_pair(feed + 1, j);
        }
      }
    }
  }

  int now = max_element(f[n], f[n] + maxn) - f[n];

  cout << f[n][now] << endl;

  vector<vector<int>> trace(n);
  for(int i = n; i > 0; --i) {
    int nxt = pre[i][now].second, take = pre[i][now].first;
    for(int j = 0; j < take; ++j) {
      trace[i - 1].emplace_back(frens[i - 1][j].second);
    }
    now = nxt;
  }

  for(int i = 0; i < n; ++i) {
    cout << trace[i].size() << " ";
    for(int x : trace[i]) cout << x << " ";
    cout << endl;
  }

  return 0;
}