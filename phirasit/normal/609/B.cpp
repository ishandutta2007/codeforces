#include <iostream>
#include <algorithm>

using namespace std;

const int N = 20;

int cnt[N];
int n, m;

int main() {
  cin >> n >> m;
  long long sum = 0ll;
  for(int i = 0;i < n;i++) {
    int val;
    cin >> val;
    cnt[val]++;
  }
  sum = (long long) n * n;
  for(int i = 0;i <= m;i++) {
    sum -= (long long) cnt[i] * cnt[i];
  }
  sum /= 2;
  cout << sum << endl;
  return 0;
}