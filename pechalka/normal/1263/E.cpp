#include <set>
#include <deque>
#include <vector>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<pair<int, int>> tree;
vector<int> mod;

void push(int v, int left, int right){
  tree[v] = make_pair(tree[v].first + mod[v], tree[v].second + mod[v]);
  if (left + 1 == right){
    mod[v] = 0;
    return;
  }
  mod[2 * v + 1] += mod[v];
  mod[2 * v + 2] += mod[v];
  mod[v] = 0;
}

const int INF = 1e9;

pair<int, int> combine(pair<int, int> a, pair<int, int> b){
  return make_pair(min(a.first, b.first), max(a.second, b.second));
}

pair<int, int> get(int v, int left, int right, int x, int y){
  push(v, left, right);
  if (y <= left || right <= x)
    return make_pair(INF, -INF);
  if (x <= left && right <= y)
    return tree[v];
  int mid = (left + right) / 2;
  return combine(get(2 * v + 1, left, mid, x, y), get(2 * v + 2, mid, right, x, y));
}

void add(int v, int left, int right, int x, int y, int t){
  //cout << v << ' ' << left << ' ' << right << ' ' << x << ' ' << y << ' ' << t << '\n';
  if (y <= left || right <= x)
    return;
  if (x <= left && right <= y){
    mod[v] += t;
    return;
  }
  int mid = (left + right) / 2;
  add(2 * v + 1, left, mid, x, y, t);
  add(2 * v + 2, mid, right, x, y, t);
  push(2 * v + 1, left, mid);
  push(2 * v + 2, mid, right);
  tree[v] = combine(tree[2 * v + 1], tree[2 * v + 2]);
}

const int MX = 1000000;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  tree.resize(4 * MX);
  mod.resize(4 * MX);
  int n;
  cin >> n;
  int j = 0;
  vector<char> s(MX, ' ');
  for (int i = 0; i < n; ++i){
    //for (int k = 0; k < 5; ++k)
    //  cout << s[k];
    //cout << '\n';
    char c;
    cin >> c;
    if (c == 'L')
      j = max(j - 1, 0);
    else if (c == 'R')
      ++j;
    else {
      if (s[j] == '(')
        add(0, 0, MX, j, MX, -1);
      if (s[j] == ')')
        add(0, 0, MX, j, MX, 1);
      s[j] = c;
      if (s[j] == '(')
        add(0, 0, MX, j, MX, 1);
      if (s[j] == ')')
        add(0, 0, MX, j, MX, -1);
    }
    auto tmp1 = get(0, 0, MX, 0, MX);
    auto tmp2 = get(0, 0, MX, MX - 1, MX);
    //cout << tmp.first << ' ' << tmp.second << '\n';
    if (tmp1.first < 0 || tmp2.first > 0)
      cout << -1 << ' ';
    else
      cout << tmp1.second << ' ';
    //cout << '\n';
  }
  return 0;
}