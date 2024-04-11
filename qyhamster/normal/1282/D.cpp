#include <bits/stdc++.h>
using namespace std;
int query(string s)
{
  cout << s << endl;
  fflush(stdout);
  int x;
  cin >> x;
  if(x == -1 || x == 0) exit(0);
  return x;
}
int main()
{
  string A,B;
  for(int i = 0; i < 300; i++)
  {
    A = A + 'a';
    B = B + 'b';
  }
  int a = 300 - query(A);
  int b = 300 - query(B);
  int ln = a+b;
  string s;
  for(int i = 0; i < ln; i++)
  {
    s = s + 'a';
  }
  for(int i = 0; i < ln; i++)
  {
    if(b == 0)
    {
      query(s);
      return 0;
    }
    s[i] = 'b';
    int x = query(s);
    if(x < b)
    {
      b--;
    }
    else
    {
      a--;
      s[i] = 'a';
    }
  }
  return 0;
}