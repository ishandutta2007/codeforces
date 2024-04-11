#include <bits/stdc++.h>
using namespace std;
const int maxn = 1010;
int a[maxn],b[maxn];
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while(T--)
  {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    sort(a,a+n);
    sort(b,b+n);
    for(int i = 0; i < n; i++) cout << a[i] << " ";cout << endl;
    for(int i = 0; i < n; i++) cout << b[i] << " ";cout << endl;
  }
  return 0;
}