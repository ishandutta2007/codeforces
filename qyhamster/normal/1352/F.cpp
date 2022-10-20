#ifdef LOCAL
#include <iostream>
#include <vector>
#include <queue>
#else
#include <bits/stdc++.h>
#endif
#define pii pair<int,int>
using namespace std;
const int maxn = 1e5;
long long a[maxn],s[maxn];
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while(T--)
  {
    int a,b,c;
    cin >> a >> b >> c;
    if(b == 0)
    {
      if(a)
      {
        for(int i = 0; i <= a; i++) cout << 0; 
      }
      if(c) for(int i = 0; i <= c; i++) cout << 1; cout << endl;
      continue;
    }
    for(int i = 0; i <= a; i++) cout << 0;
    b--;
    for(int i = 0; i <= c; i++) cout << 1;
    int x = 0;
    for(int i = 0; i < b; i++)
    {
      cout << x;
      x = 1-x;
    }
    cout << endl;
  }
  return 0;
}