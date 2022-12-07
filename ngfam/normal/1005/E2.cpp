#include<bits/stdc++.h>

using namespace std;

const int MAXN = 200025;

long long solve(vector<int> a){
  vector<int> fwt(MAXN << 1, 0);

  auto f = [&](int x) {
    x += MAXN;
    for(; x < fwt.size(); x += x & -x) fwt[x]++;
    return;
  };
  auto g = [&](int x) {
    x += MAXN;
    int ans = 0;
    for(; x > 0; x -= x & -x) ans += fwt[x];
    return ans;
  };

  f(0);

  long long answer = 0;
  for(int i = 0; i < a.size(); ++i) {
    if(i > 0) a[i] += a[i - 1];
    answer += g(a[i]);
    f(a[i]);
  }
  return answer;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  int n, m;
  cin >> n >> m;

  vector<int> a(n), b(n), c(n);
  for(int &x : a) cin >> x;

  for(int i = 0; i < n; ++i) {
    b[i] = (a[i] <= m ? 1 : -1);
    c[i] = (a[i] < m ? 1 : -1);
  }

  cout << solve(b) - solve(c) << endl;

  return 0;
}