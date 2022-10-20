#include <bits/stdc++.h>
#define Task "A"
#define fi freopen(Task".inp", "r", stdin)
#define fo freopen(Task".out", "w", stdout)

using namespace std;

pair<long long, long long> nha, truong;
int n;

bool Check(long long a, long long b, long long c) {
  long long p1 = a * nha.first + b * nha.second + c;
  long long p2 = a * truong.first + b * truong.second + c;
  return ((p1 < 0) ^ (p2 < 0));
}

int main() {
  ios_base::sync_with_stdio(0);
  //fi, fo;
  cin >> nha.first >> nha.second >> truong.first >> truong.second >> n;
  int res = 0;
  for (int i = 1; i <= n; i++) {
    long long a, b, c;
    cin >> a >> b >> c;
    if(Check(a, b, c)) res++;
  }
  cout << res;
  return 0;
}