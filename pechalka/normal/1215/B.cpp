#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <deque>
#include <set>

using namespace std;

int main(){
  long long n;
  cin >> n;
  long long cnt[2];
  cnt[0] = 1;
  cnt[1] = 0;
  int prev = 0;
  for (int i = 0; i < n; ++i){
    int x;
    cin >> x;
    prev = (prev + (x < 0)) % 2;
    ++cnt[prev];
  }
  long long c = cnt[0] * (cnt[0] - 1) / 2 + cnt[1] * (cnt[1] - 1) / 2;
  cout << n * (n + 1) / 2ll - c << ' ' << c << '\n';
  return 0;
}