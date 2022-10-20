#ifdef LOCAL
#include <iostream>
#include <vector>
#else
#include <bits/stdc++.h>
#endif
using namespace std;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while(T--)
  {
    string s;
    cin >> s;
    bool check = 1;
    for(int i = 1; i < s.length(); i++)
      if(s[i] != s[i-1]) check = 0;
    if(check) cout << s << '\n';
    else
    {
      for(int i = 0; i < s.length(); i++)
        cout << "10";
      cout << '\n';
    }
  }
  return 0;
}