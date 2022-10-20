#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
long long a[26], num[26][26];
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  string s;
  cin >> s;
  int n = s.length();
  for(int i = 0; i < n; i++)
  {
    int x = s[i] - 'a';
    for(int j = 0; j < 26; j++) num[j][x] += a[j];
    a[x]++;
  }
  long long ans = 0;
  for(int i = 0; i < 26; i++)
  {
    for(int j = 0; j < 26; j++) ans = max(ans,num[i][j]);
    ans = max(ans,a[i]);
  }
  cout << ans << '\n';
  return 0;
}