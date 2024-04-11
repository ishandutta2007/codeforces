#include <iostream>
#include <vector>

using namespace std;

const int kModular = 5;
const int kMaxN = 500;
const int kMaxM = 500;

struct Mutation {
  Mutation() = default;
  Mutation(int row1, int factor1, int row2, int factor2) : row1(row1), factor1(factor1), row2(row2), factor2(factor2) {}
  int row1;
  int factor1;
  int row2;
  int factor2;
};

int n, m;
int a[kMaxM][kMaxN];

int main() {
  cin.sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    for (int j = 0; j < m; ++j) {
      a[j][i] = s[j] - 'a';
    }
  }
  vector<int> free_rows;
  vector<Mutation> mutations;
  for (int row = 0; row < m; ++row) {
    int col = 0;
    while (col < n && a[row][col] == 0) {
      ++col;
    }
    if (col == n) {
      free_rows.push_back(row);
    } else {
      for (int next_row = row + 1; next_row < m; ++next_row) {
        if (a[next_row][col] == 0) {
          continue;
        }
        int factor1 = kModular - a[next_row][col];
        int factor2 = a[row][col];
        mutations.emplace_back(row, factor1, next_row, factor2);
        for (int i = 0; i < n; ++i) {
          a[next_row][i] = (a[row][i] * factor1 + a[next_row][i] * factor2) % kModular;
          if (a[next_row][i] < 0) {
            a[next_row][i] += kModular;
          }
        }
      }
    }
  }
  int num_queries;
  cin >> num_queries;
  int64_t results = 1;
  for (int i = 0; i < n - m + free_rows.size(); ++i) {
    results = (results * 5) % 1000000007;
  }
  for (int query_count = 0; query_count < num_queries; ++query_count) {
    string query_str;
    cin >> query_str;
    int b[kMaxM];
    for (int i = 0; i < m; ++i) {
      b[i] = query_str[i] - 'a';
    }
    for (const auto& mutation : mutations) {
      b[mutation.row2] = (b[mutation.row1] * mutation.factor1 + b[mutation.row2] * mutation.factor2) % kModular;
      if (b[mutation.row2] < 0) {
        b[mutation.row2] += kModular;
      }
    }
    bool has_solution = true;
    for (int row : free_rows) {
      if (b[row]) {
        has_solution = false;
      }
    }
    cout << (has_solution ? results : 0) << endl;
  }
  return 0;
}