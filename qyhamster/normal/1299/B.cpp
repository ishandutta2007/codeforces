#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int x[maxn],y[maxn];
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  for(int i = 0; i < n; i++)
  {
    cin >> x[i] >> y[i];
  }
  if(n&1)
  {
    cout << "NO" << endl;
    exit(0);
  }
  for(int i = 0; i < n/2; i++)
  {
    x[i] += x[i+n/2];
    y[i] += y[i+n/2];
  }
  int ok = 1;
  for(int i = 1; i < n/2; i++)
  {
    if(x[i] != x[i-1] || y[i] != y[i-1]) ok = 0;
  }
  if(ok) cout << "YES" << endl;
  else cout << "NO" << endl;
  return 0;
}