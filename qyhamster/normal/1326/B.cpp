#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
long long a[maxn],b[maxn];
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  for(int i = 0; i < n; i++) cin >> b[i];
  long long mx = 0;
  for(int i = 0; i < n; i++)
  {
    a[i] = b[i] + mx;
    mx = max(mx, a[i]);
  }
  for(int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
  return 0;
}