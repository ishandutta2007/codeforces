#include <cstdio>
#include <iostream>

using namespace std;

const int N = 100005;
int n, q;
int ans;
char a[N];

int query(int i) {
  int cnt = 0;
  for (int j = i - 2; j <= i; j++)
    if (j > 0 && j + 2 <= n)
      if (a[j] == 'a' && a[j + 1] == 'b' && a[j + 2] == 'c')
        cnt++;
  return cnt;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  cin >> n >> q >> (a + 1);

  for (int i = 1; i <= n; i++)
    ans += query(i);
  ans /= 3;

  while (q--) {
    int pos;
    char c;
    cin >> pos >> c;
    ans -= query(pos);
    a[pos] = c;
    ans += query(pos);
    cout << ans << '\n';
  }
}