#include <iostream>
#include <cstdio>
using namespace std;

int main ()
{
  int l, r, a;
  cin >> l >> r >> a;
  int pairs = 0;
  if (r > l)
    {
      int temp = l;
      l = r;
      r = temp;
    }
  pairs += r;
  l = l - r;
  if (l >= a)
    {
      pairs += a;
    }
  else
    {
      pairs += l;
      a = a - l;
      pairs += a / 2;
    }
  cout << 2 * pairs << endl;
  return 0;
}