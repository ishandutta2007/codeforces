#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int a[maxn];
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  string s;
  cin >> s;
  int n = s.length();
  s = "#" + s;
  bool check = 0;
  for(int i = 1; i < n; i++)
  if(s[i] == '(' && s[i+1] == ')') check = 1;
  if(!check)
  {
    cout << 0 << endl;
    return 0;
  }
  cout << 1 << endl;
  for(int i = 1; i <= n; i++)
  {
    if(s[i] == '(') a[i]++;
    a[i] += a[i-1];
  }
  int cnt = 0,cut = 0;
  for(int i = n; i > 0; i--)
  {
    if(s[i] == ')')
    {
      if(cnt+1 > a[i])
      {
        cut = i;
        break;
      }
      else
      {
        cnt++;
      }
    }
  }
  cout << cnt * 2 << endl;
  int num = cnt;
  for(int i = 1; i <= n; i++)
  {
    if(!num) break;
    if(s[i] == '(')
    {
      cout << i << " ";
      num--;
    }
  }
  for(int i = cut+1; i <= n; i++)
  {
    if(s[i] == ')')
    {
      cout << i << " ";
    }
  }
  cout << endl;
  return 0;
}