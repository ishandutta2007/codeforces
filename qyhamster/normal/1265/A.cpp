#include <iostream>
#include <cstring>
using namespace std;
bool check(string s)
{
  for(int i = 1; i < s.length(); i++)
  {
    if(s[i] == s[i-1])
    return false;
  }
  return true;
}
int main()
{
  int T;
  cin >> T;
  string s;
  while(T--)
  {
    cin >> s;
    for(int i = 0; i < s.length(); i++)
    {
      if(s[i] != '?') continue;
      bool used[3] = {0,0,0};
      if(i != 0 && s[i-1] != '?') used[s[i-1]-'a'] = 1;
      if(i != (int)s.length() - 1 && s[i+1] != '?') used[s[i+1]-'a'] = 1;
      for(int j = 0; j < 3; j++)
      {
        if(!used[j])
        {
          s[i] = 'a' + j;
          break;
        }
      }
    }
    if(!check(s)) cout << "-1" << endl;
    else cout << s << endl;
  }
  return 0;
}