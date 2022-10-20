#include <bits/stdc++.h>

using namespace std;

map<int, int> upper, lower;

long long cross(pair<int, int> u, pair<int, int> v) {
  return 1ll * u.first * v.second - 1ll * u.second * v.first;
}

bool check(map<int, int> &u, int x, int y) {
  auto pos = u.lower_bound(x);
  if (pos == u.end()) {
    return 0;
  }
  if (pos->first == x) {
    return y <= pos->second;
  }
  if (pos == u.begin()) {
    return 0;
  }
  auto pos1 = pos;
  pos1--;
  return cross(make_pair(x - pos1->first, y - pos1->second), make_pair(pos->first - x, pos->second - y)) >= 0;
}

void add(map<int, int> &u, int x, int y) {
  if (check(u, x, y)) {
    return;
  }
  u[x] = y;
  auto pos = u.lower_bound(x);
  auto pos1 = pos;
  pos1++;
  while (pos1 != u.end()) {
    pos = pos1;
    pos1++;
    if (pos1 == u.end()) {
      break;
    }
    if (cross(make_pair(pos->first - x, pos->second - y), make_pair(pos1->first - pos->first, pos1->second - pos->second)) <= 0) {
      break;
    }
    u.erase(pos);
  }
  pos = u.lower_bound(x);
  if (pos == u.begin()) {
    return;
  }
  pos1 = pos;
  pos1--;
  while (pos1 != u.begin()) {
    pos = pos1;
    pos1--;
    if (cross(make_pair(pos->first - x, pos->second - y), make_pair(pos1->first - pos->first, pos1->second - pos->second)) >= 0) {
      break;
    }
    u.erase(pos);
  }
}

int main() {
  int q;
  scanf("%d", &q);
  while (q--) {
    int op, x, y;
    scanf("%d %d %d", &op, &x, &y);
    if (op == 1) {
      add(upper, x, y);
      add(lower, x, -y);
    } else {
      if (check(upper, x, y) && check(lower, x, -y)) {
        puts("YES");
      } else {
        puts("NO");
      }
    }
  }
//  cout << endl;
//  for (auto u : upper) {
//    cout << u.first << " " << u.second << endl;
//  }
//  cout << endl;
//  for (auto u : lower) {
//    cout << u.first << " " << u.second << endl;
//  }
  return 0;
}