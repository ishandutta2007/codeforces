#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while(T--)
  {
    vector<int> ans;
    string s;
    cin >> s;
    s = s + "##";
    s = "##" + s;
    int n = s.length();
    for(int i = 0; i < n; i++)
    {
      if(s[i] != 'o' || s[i-1] == 'o') continue;
      int last = i;
      while(s[last+1] == 'o') last++;
      bool front = 0, back = 0;
      if(s[i-1] == 'w' && s[i-2] == 't')front = 1;
      if(s[last+1] == 'n' && s[last+2] == 'e')back = 1;
      if(i == last)
      {
        if(front || back)ans.push_back(i-1);
      }
      else
      {
        if(front) ans.push_back(i-2);
        if(back) ans.push_back(last);
      }
    }
    cout << ans.size() << '\n';
    for(int i = 0; i < ans.size(); i++)
      cout << ans[i] << " ";
    cout << '\n';
  }
  return 0;
}