// LUOGU_RID: 91280286
#include <iostream>
#include <cstdio>

using namespace std;

const int N = 100005;
int n;
char s[N];

int gcd(int n, int m) { return !m ? n : gcd(m, n % m); }

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int t;
  cin >> t;
  while (t--) {
    cin >> n >> (s + 1);
    int sum = 0;
    s[0] = '0';
    for (int i = n; i; i--)
      sum += (s[i] - '0') ^ (s[i - 1] - '0');
    cout << max(0, sum - 1) << endl;
  }
}