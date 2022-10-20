#include <bits/stdc++.h>
using namespace std;
int main()
{
  int T;
  cin >> T;
  while(T--)
  {
    string a,b,c;
    cin >> a >> b >> c;
    int ok = 1;
    for(int i = 0; i < a.length(); i++)
    {
      if(c[i] != a[i] && c[i] != b[i]) ok = 0;
    }
    if(!ok) cout << "NO" << '\n';
    else cout << "YES" << '\n';
  }
  return 0;
}