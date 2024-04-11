#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  string s;
  cin >> s;
  int sum = 0;
  for(int i = 0; i < n; i++) if(s[i] == '(') sum++; else sum--;
  if(sum)
  {
    cout << -1 << endl;
    return 0;
  }
  int ans = 0, cnt = 0;
  for(int i = 0; i < n; i++)
  {
    int pre = cnt;
    if(s[i] == '(') cnt++;
    else cnt--;
    if(cnt < 0 || pre < 0) ans++;
  }
  cout << ans << endl;
  return 0;
}