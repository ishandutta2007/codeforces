#include <iostream>
#include <cstdio>
#include <cassert>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

bool local_test = false;
int local_p1 = 123;
int local_p2 = 541;
int query_count = 0;

int n = 999;
int x = 12;
int y = 347;

int Query(const vector<int>& a) {
  if (a.empty()) {
    return 0;
  }
  if (local_test) {
    int ret = 0;
    for (int p : a) {
      ret ^= (p == local_p1 || p == local_p2 ? y : x);
    }
    ++query_count;
    printf("QUERY # %d\n", query_count);
    return ret;
  } else {
    printf("? %d", static_cast<int>(a.size()));
    for (int p : a) {
      printf(" %d", p + 1);
    }
    printf("\n");
    fflush(stdout);
    int ret;
    cin >> ret;
    return ret;
  }
}

int Answer(int p1, int p2) {
  if (p1 > p2) {
    swap(p1, p2);
  }
  if (local_test) {
    if (local_p1 > local_p2) {
      swap(local_p1, local_p2);
    }
    assert(p1 == local_p1 && p2 == local_p2);
    if (p1 == local_p1 && p2 == local_p2) {
      printf("Correct.\n");
    } else {
      printf("Not-correct!!!!!!!!!!!!!");
    }
  } else {
    printf("! %d %d\n", p1 + 1, p2 + 1);
    fflush(stdout);
  }
  exit(0);
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(nullptr);
  if (!local_test) {
    cin >> n >> x >> y;
  }
  if (n <= 10) {
    vector<int> ret;
    for (int i = 0; i < n; ++i) {
      if (Query({i}) == y) {
        ret.push_back(i);
      }
    }
    Answer(ret[0], ret[1]);
    return 0;
  }
  int same_bits = 0;
  int diff_bits = 0;
  for (int i = 0; i < 10; ++i) {
    vector<int> p;
    for (int id = 0; id < n; ++id) {
      if (id & (1 << i)) {
        p.push_back(id);
      }
    }
    int query = Query(p);
    int even = (static_cast<int>(p.size()) % 2) * x;
    int odd = ((((static_cast<int>(p.size()) + 1) % 2) * x) ^ y);
    assert(query == even || query == odd);
    if (query == odd) {
      diff_bits |= (1 << i);
    } else {
      same_bits |= (1 << i);
    }
  }

  int value_known_bits = 0;
  int value_at_diff_bits = 0;
  bool first_diff_bits = true;
  for (int i = 0; i < 10; ++i) {
    if (diff_bits & (1 << i)) {
      if (first_diff_bits) {
        first_diff_bits = false;
      } else {
        vector<int> p;
        for (int id = 0; id < n; ++id) {
          if ((id & value_known_bits) != value_at_diff_bits) {
            continue;
          }
          if (id & (1 << i)) {
            p.push_back(id);
          }
        }
        int query = Query(p);
        int even = (static_cast<int>(p.size()) % 2) * x;
        int odd = ((((static_cast<int>(p.size()) + 1) % 2) * x) ^ y);
        assert(query == even || query == odd);
        if (query == odd) {
          value_at_diff_bits |= (1 << i);
        }
      }
      value_known_bits |= (1 << i);
    }
  }
  int ret = value_at_diff_bits;
  for (int i = 0; i < 10; ++i) {
    if (same_bits & (1 << i)) {
      vector<int> p;
      for (int id = 0; id < n; ++id) {
        if ((id & value_known_bits) != value_at_diff_bits) {
          continue;
        }
        if (id & (1 << i)) {
          p.push_back(id);
        }
      }
      int query = Query(p);
      int even = (static_cast<int>(p.size()) % 2) * x;
      int odd = ((((static_cast<int>(p.size()) + 1) % 2) * x) ^ y);
      assert(query == even || query == odd);
      if (query == odd) {
        ret |= (1 << i);
      }
    }
  }
  Answer(ret, ret ^ value_known_bits);
  return 0;
}