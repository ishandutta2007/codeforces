#include<iostream>
#include <algorithm>
#include <vector>
using namespace std;
pair<int,int>a[1010];
int main()
{
  int T;
  cin >> T;
  while(T--)
  {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
      cin >> a[i].first >> a[i].second;
    }
    sort(a,a+n);
    int x = 0, y = 0;
    vector<char> ans;
    int ok = 1;
    for(int i = 0; i < n; i++)
    {
      while(x < a[i].first)
      {
        x++;
        ans.push_back('R');
      }
      if(y > a[i].second) ok = 0;
      while(y < a[i].second)
      {
        y++;
        ans.push_back('U');
      }
    }
    if(!ok) cout << "NO" << endl;
    else
    {
      cout << "YES" << endl;
      for(int i = 0; i < ans.size(); i++)cout << ans[i];
      cout << endl;
    }
  }
  return 0;
}