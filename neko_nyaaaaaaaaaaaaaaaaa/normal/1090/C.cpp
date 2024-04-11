#include <bits/stdc++.h>
using namespace std;
#define popCnt(x) (__builtin_popcountll(x))
typedef long long Long;
typedef unsigned long long ULong;

const int N = 100005;
const int SQRT = sqrt(N) + 1;

vector<int> boxes[N][SQRT];
int curr_sz[N];

int move(vector<int>& a, vector<int>& b) {
  int i = 0, j = 0;
  for (i = 0; i < b.size();) {
    if (j == a.size()) break;
    if (a[j] < b[i]) {
      ++j;
      continue;
    }
    if (a[j] == b[i]) {
      ++i, ++j;
      continue;
    }
    if (a[j] > b[i]) {
      break;
    }
  }
  int tmp = b[i];
  a.insert(a.begin() + j, b[i]);
  b.erase(b.begin() + i);
  return tmp;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  int n, m;

  cin >> n >> m;
  vector<pair<int, int>> sizes;
  int total = 0;
  for (int i = 1; i <= n; ++i) {
    int s;
    cin >> s;
    total += s;
    curr_sz[i] = s;
    sizes.emplace_back(s, i);
    for (int j = 0; j < s; ++j) {
      int x;
      cin >> x;
      boxes[i][x / SQRT].push_back(x);
    }
    for (int j = 0; j < SQRT; ++j) {
      sort(boxes[i][j].begin(), boxes[i][j].end());
    }
  }

  sort(sizes.begin(), sizes.end());
  int ones = total % n;
  int sz = total / n;

  int l_ind = 0, r_ind = n - 1;
  vector<tuple<int, int, int>> res;
  while (l_ind < r_ind) {
    int l_box = sizes[l_ind].second;
    int r_box = sizes[r_ind].second;

    if (curr_sz[r_box] == sz + (n - 1 - r_ind < ones)) {
      --r_ind;
      continue;
    }
    if (curr_sz[l_box] == sz + (n - 1 - l_ind < ones)) {
      ++l_ind;
      continue;
    }

    for (int i = 0; i < SQRT; ++i) {
      if (boxes[r_box][i].size() > boxes[l_box][i].size()) {
        res.emplace_back(r_box, l_box, move(boxes[l_box][i], boxes[r_box][i]));
        --curr_sz[r_box];
        ++curr_sz[l_box];
        break;
      }
    }
  }
  cout << res.size() << endl;

  for (auto& t : res) {
    cout << get<0>(t) << " " << get<1>(t) << " " << get<2>(t) << endl;
  }
}