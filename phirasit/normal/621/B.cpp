#include <iostream>
#include <map>

using namespace std;

map<int, int> d1, d2;

int main() {
  int n;
  cin >> n;
  long long ans = 0ll;
  for(int i = 0;i < n;i++) {
    int x, y;
    cin >> x >> y;
    ans += d1[x+y] + d2[x-y];
    d1[x+y]++;
    d2[x-y]++;
  }
  cout << ans << endl;
  return 0;
}