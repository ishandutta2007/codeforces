
/***
  probably blocks from 2 to T - 1 will have the same values
  or else we can always move the changes back to block 1 or to block n
  so that they fit the elements with max frequenc


  brainded solution:
  f(i, j, k)
  2 ^ k blocks, values in range i, j
  should work lol
***/

#include<bits/stdc++.h>

using namespace std;

int solve_lis(vector<int> &a, int l, int r) {
  vector<int> f(a.size() + 1, r + 1);

  int ans = 0;
  f[0] = l;

  for(int i = 0; i < a.size(); ++i) {
    if(a[i] <= r && a[i] >= l) {
      auto p = upper_bound(f.begin(), f.end(), a[i]) - f.begin();
      ans = max(ans, p);
      f[p] = a[i];
    }
  }
  return ans;
}

const int MAXN = 303;
const int LOG = 25;

struct Matrix{
  int a[MAXN][MAXN];

  Matrix() {
    memset(a, 0, sizeof a);
  }

  Matrix operator+(const Matrix &rhs)const{
    Matrix res;
    for(int i = 0; i < MAXN; ++i) {
      for(int j = i; j < MAXN; ++j) {
        for(int k = i; k <= j; ++k){
          res.a[i][j] = max(res.a[i][j], a[i][k] + rhs.a[k][j]);
        }
      }
    }
    return res;
  }
};


Matrix f[LOG], res;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  int n, T;
  cin >> n >> T;

  vector<int> a(n);
  for(auto &x : a) cin >> x;

  for(int i = 0; i < MAXN; ++i) {
    for(int j = i; j < MAXN; ++j) {
      f[0].a[i][j] = solve_lis(a, i, j);
    }
  }

  for(int i = 0; i < LOG; ++i) {
    if(i > 0) f[i] = f[i - 1] + f[i - 1];
    if(T & (1 << i)) res = res + f[i];
  }

  int answer = 0;
  for(int i = 0; i < MAXN; ++i) {
    for(int j = 0; j < MAXN; ++j) {
      answer = max(answer, res.a[i][j]);
    }
  }

  cout << answer << "\n";

  return 0;
}