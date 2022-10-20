#include <iostream>
#include <vector>
using namespace std;
vector<int> ans;
bool check()
{
  for(int i = 1; i < ans.size(); i++)
  {
    if(abs(ans[i]-ans[i-1]) != 1) return false;
  }
  return true;
}
int main()
{
  int a,b,c,d;
  cin >> a >> b >> c >> d;
  if(abs(a+c-b-d) > 1)
  {
    cout << "NO" << endl;
    return 0;
  }
  if(a+c >= b+d)
  {
    while(a)
    {
      ans.push_back(0);
      a--;
      if(b > 0) ans.push_back(1);
      else break;
      b--;
    }
    while(c)
    {
      ans.push_back(2);
      c--;
      if(b > 0)
      {
        ans.push_back(1);
        b--;
      }
      else if(d > 0)
      {
        ans.push_back(3);
        d--;
      }
      else break;
    }
  }
  else
  {
    while(d)
    {
      ans.push_back(3);
      d--;
      if(c > 0) ans.push_back(2);
      else break;
      c--;
    }
    while(b)
    {
      ans.push_back(1);
      b--;
      if(c > 0)
      {
        ans.push_back(2);
        c--;
      }
      else if(a > 0)
      {
        ans.push_back(0);
        a--;
      }
      else break;
    }
  }
  if(a == 0 && b == 0 && c == 0 && d == 0 && check())
  {
    cout << "YES" << endl;
    for(int i = 0; i < ans.size(); i++)
      cout << ans[i] << " ";
    cout << endl;
  }
  else
  {
    cout << "NO" << endl;
  }
  return 0;
}