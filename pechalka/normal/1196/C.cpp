#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <tuple>

using namespace std;

const int INF = 100000;
const int END = 2 * INF + 1;

pair<int, int> tree[4 * END];
int mod[4 * END];
int col[4 * END];

int color = 0;

pair<int, int> combine(const pair<int, int> &a, const pair<int, int> &b){
  if (a.first > b.first)
    return a;
  return b;
}

pair<int, int> operator +(const pair<int, int> &a, const pair<int, int> &b){
  return make_pair(a.first + b.first, a.second + b.second);
}

void push(int p, int left, int right){
  if (col[p] != color){
    tree[p] = {0, left};
    mod[p] = 0;
    col[p] = color;
  }
  if (left + 1 == right){
    tree[p] = {tree[p].first + mod[p], left};
    mod[p] = 0;
    return;
  }
  if (col[2 * p + 1] != color){
    tree[2 * p + 1] = {0, left};
    mod[2 * p + 1] = 0;
    col[2 * p + 1] = color;
  }
  if (col[2 * p + 2] != color){
    tree[2 * p + 2] = {0, (left + right) / 2};
    mod[2 * p + 2] = 0;
    col[2 * p + 2] = color;
  }
  mod[2 * p + 1] += mod[p];
  mod[2 * p + 2] += mod[p];
  tree[p] = combine(tree[2 * p + 1] + make_pair(mod[2 * p + 1], 0), tree[2 * p + 2] + make_pair(mod[2 * p + 2], 0));
  mod[p] = 0;
}

void add(int p, int left, int right, int x, int y, int val){
  push(p, left, right);
  if (y <= left || right <= x)
    return;
  if (x <= left && right <= y){
    mod[p] += val;
    return;
  }
  int mid = (left + right) / 2;
  add(2 * p + 1, left, mid, x, y, val);
  add(2 * p + 2, mid, right, x, y, val);
  tree[p] = combine(tree[2 * p + 1] + make_pair(mod[2 * p + 1], 0), tree[2 * p + 2] + make_pair(mod[2 * p + 2], 0));
}

struct Event{
  int x, y1, y2;
  bool start;
  Event(int _x, int _y1, int _y2, bool _start){
    x = _x;
    y1 = _y1;
    y2 = _y2;
    start = _start;
  }
};

bool operator <(Event a, Event b){
  return tie(a.x, a.start, a.y1, a.y2) < tie(b.x, b.start, b.y1, b.y2);
}

int main(){
  int q;
  cin >> q;
  for (int query = 0; query < q; ++query){
    ++color;
    int n;
    cin >> n;
    vector<Event> events;
    for (int i = 0; i < n; ++i){
      int x, y, f1, f2, f3, f4;
      cin >> x >> y >> f1 >> f2 >> f3 >> f4;
      int x1 = (f1) ? -INF : x;
      int x2 = (f3) ? INF : x;
      int y1 = (f4) ? -INF : y;
      int y2 = (f2) ? INF : y;
      events.emplace_back(x1, y1, y2, true);
      events.emplace_back(x2 + 1, y1, y2, false);
    }
    sort(events.begin(), events.end());
    int ansx = -1, ansy = -1;
    for (auto e : events){
      //cout << e.x << ' ' << e.y1 << ' ' << e.y2 << ' ' << e.start << '\n';
      if (e.start)
        add(0, 0, END, e.y1 + INF, e.y2 + INF + 1, 1);
      else
        add(0, 0, END, e.y1 + INF, e.y2 + INF + 1, -1);
      auto x = tree[0] + make_pair(mod[0], 0);
      //cout << x.first << " " << x.second << "\n";
      if (x.first == n){
        ansx = e.x;
        ansy = x.second;
      }
    }
    if (ansx == -1 && ansy == -1)
      cout << 0 << '\n';
    else
      cout << 1 << ' ' << ansx << ' ' << ansy - INF << '\n';
  }
  return 0;
}