#include <iostream>
#include <cstring>
using namespace std;
int n,k;
string s;
void check()
{
  int ok = 0, l = n, r = 0, other = 1;
  for(int i = 0; i < n; i++)
  {
    if(s[i] == '0')
    {
      l=min(l,i);
      r=max(r,i);
    }
  }
  if(r - l < k) ok = 1;
  if(r - l > k) other = 0;
  l = n; r = 0;
  for(int i = 0; i < n; i++)
  {
    if(s[i] == '1')
    {
      l=min(l,i);
      r=max(r,i);
    }
  }
  int alter = 0;
  for(int i = 1; i < n; i++)
  {
    if(s[i] != s[i-1])alter++;
  }
  if(r - l < k) ok = 1;
  if(r - l > k) other = 0;
  if(ok)
  {
    cout << "tokitsukaze" << endl;
    exit(0);
  }
  if(other && alter > 1)
  {
      cout << "quailty" << endl;
      exit(0);
  }
}
int main()
{
  cin >> n >> k;
  cin >> s;
  check();
  if(n <= k + 1)
  {
    cout << "tokitsukaze" << endl;
    exit(0);
  }
  if(n == k+2)
  {
    cout << "quailty" << endl;
    exit(0);
  }
  cout << "once again" << endl;
}