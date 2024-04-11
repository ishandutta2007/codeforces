#include <iostream>
using namespace std;
const int maxn = 100005;
int d[maxn];
int main()
{
  int n;
  cin >> n;
  for(int i = 1; i < n; i++)
  {
    int u,v;
    cin >> u >> v;
    d[u]++;
    d[v]++;
  }
  int ok = 1;
  for(int i = 1; i <= n; i++)
  {
    if(d[i] == 2) ok = 0;
  }
  if(ok) cout << "YES" << endl;
  else cout << "NO" << endl;
  return 0;
}