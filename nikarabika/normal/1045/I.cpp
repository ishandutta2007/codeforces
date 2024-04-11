//In the Name of God
//Ya Ali

#include <bits/stdc++.h>

#define err(A) cout << #A << " = " << (A) << endl

using namespace std;

int n;

map<int, int> cnt;
long long ans;

int main()
{
  ios::sync_with_stdio(0); cin.tie(0);

  cin >> n;

  for (; n --; )
    {
      string s;
      cin >> s;
      
      int msk = 0;
      for (int i = 0; i < s.size(); i ++)
	msk ^= 1 << (s[i] - 'a');

      for (int i = 0; i < 26; i ++)
	ans += cnt[msk ^ (1 << i)];
      ans += cnt[msk];

      cnt[msk] ++;
    }

  cout << ans << endl;
  
  return 0;
}