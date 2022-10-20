#ifdef LOCAL
#include <iostream>
#else
#include <bits/stdc++.h>
#endif
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while(T--)
  {
    int n,k;
    cin >> n >> k;
    string s;
    cin >> s;
    bool ok = 1;
    for(int i = 0; i < k; i++)
    {
      int num = -1;
      for(int j = i; j < n; j+=k)
      {
        if(s[j] == '?') continue;
        if(num == -1)
        {
          num = s[j] - '0';
        }
        else
        {
          if(num == s[j] - '0') continue;
          else
          {
            ok = false;
            break;
          }
        }
      }
      if(!ok) break;
      if(num != -1) s[i] = num+'0';
    }
    int sum = 0, buffer = 0;
    for(int i = 0; i < k; i++)
    {
      if(s[i] == '1') sum++;
      if(s[i] == '?') buffer++;
    }
    if(sum <= k/2 && sum+buffer>=k/2 && ok)
    {
      cout << "YES" << '\n';
    }
    else cout << "NO" << '\n';
  }

  return 0;
}