#include <bits/stdc++.h>

std::map<int, int> value_for_pos;
const int inf = (int) 1e9 + 10;

int get_value(int pos) {
  if (value_for_pos.find(pos) == value_for_pos.end()) {
    value_for_pos[pos] = pos;
  }
  return value_for_pos[pos];
}

void swap(int p1, int p2) {
  int v1 = get_value(p1), v2 = get_value(p2);
  value_for_pos[p1] = v2;
  value_for_pos[p2] = v1;
}

int get_fenw(int pos, std::map<int, int>& vals, int n) {
  int res = 0;
  for (; pos >= 0; pos = (pos & (pos + 1)) - 1) {
    res += vals[pos];
  }
  return res;
}

void add_fenw(int pos, std::map<int, int>& vals, int n, int add_val) {
  for (; pos < n; pos = pos | (pos + 1)) {
    vals[pos] += add_val;
  } 
} 

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int foo, bar;
    scanf("%d %d", &foo, &bar);
    swap(foo, bar); 
  }
  std::vector<int> all_changes;
  for (auto it = value_for_pos.begin(); it != value_for_pos.end(); ++it) {
    all_changes.push_back(it->first); 
  }
  std::map<int, int> cur_values;
  long long result = 0;
  int ssum = 0;
  for (auto it = value_for_pos.begin(); it != value_for_pos.end(); ++it) {
    result += ssum - get_fenw(it->second, cur_values, inf);    
    ssum++;
    int my_min = std::min(it->first, it->second);
    int my_max = std::max(it->first, it->second);
    result += (my_max - my_min + 1) - (std::upper_bound(all_changes.begin(), all_changes.end(), my_max) - std::lower_bound(all_changes.begin(), all_changes.end(), my_min));
    add_fenw(it->second, cur_values, inf, 1);
  }
  std::cout << result << std::endl;
}