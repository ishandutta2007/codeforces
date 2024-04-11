#include <algorithm>
#include <cstdio>
#include <iostream>

using namespace std;

const int N = 505;
int n, m;
pair<int, int> a[N];
char g[N];

int main() {
  cin >> n >> m;
  for (int i = 0; i != m; i++) {
    cout << "? ";
    for (int j = 0; j != i; j++)
      cout << '0';
    cout << '1';
    for (int j = i + 1; j != m; j++)
      cout << '0';
    cout << endl;
    int x;
    cin >> x;
    a[i] = {x, i};
  }
  sort(a, a + m);

  int ans = 0;
  for (int i = 0; i != m; i++)
    g[i] = '0';
  for (int i = 0; i != m; i++) {
    g[a[i].second] = '1';
    cout << "? " << g << endl;
    int x;
    cin >> x;
    if (x == ans + a[i].first)
      ans += a[i].first;
    else
      g[a[i].second] = '0';
  }
  cout << "! " << ans << endl;
}