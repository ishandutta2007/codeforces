#include <iostream>

using namespace std;

long long calc(long long x) {
  long long cnt = 0;
  for(long long i = 1;i <= 2ll*x;i *= 2) {
    long long val = i-1;
    for(long long j = 1;j < val and 2*j < i;j *= 2) {
      if(val - j <= x) {
        cnt++;
      }
    }
  }
  return cnt;
}
int main() {
  long long a, b;
  cin >> a >> b;
  long long ans = calc(b) - calc(a-1);
  cout << ans << endl;
  return 0;
}