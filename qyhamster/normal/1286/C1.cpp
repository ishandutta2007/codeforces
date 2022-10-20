#include <bits/stdc++.h>
using namespace std;
multiset<string> st;
pair<int,string> a[110];
int main()
{
  int n;
  cin >> n;
  cout << "? 1 " << n << endl;
  fflush(stdout);
  if(n == 1)
  {
      string s;
      cin >> s;
      cout << "! " << s << endl;
      exit(0);
  }
  for(int i = 0; i < n * (n+1) / 2; i++)
  {
    string s;
    cin >> s;
    sort(s.begin(),s.end());
    st.insert(s);
  }
  cout << "? 1 " << n-1 << endl;
  fflush(stdout);
  for(int i = 0; i < n * (n-1) / 2; i++)
  {
    string s;
    cin >> s;
    sort(s.begin(),s.end());
    st.erase(st.lower_bound(s));
  }
  int cnt = 1;
  for(auto x:st)
  {
    if(x.length() == 0) continue;
    a[cnt++] = make_pair((int)x.length(),x);
  }
  a[0] = make_pair(0,"");
  sort(a+1,a+cnt);
  string ans="";
  for(int i = 1; i <= n; i++)
  {
    int num[26];
    memset(num,0,sizeof(num));
    for(int k = 0; k < a[i].first; k++)
      num[a[i].second[k]-'a']++;
    for(int k = 0; k < a[i-1].first; k++)
      num[a[i-1].second[k]-'a']--;
    for(int j = 0; j < 26; j++)
    {
      if(num[j])
      {
        char c = 'a'+j;
        ans = c+ans;
        break;
      }
    }
  }
  cout << "! " << ans << endl;
  fflush(stdout);
  return 0;
}