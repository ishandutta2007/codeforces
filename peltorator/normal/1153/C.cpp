#ifdef ONPC
  # define _GLIBCXX_DEBUG
  #define deb(a) cerr << "========" << #a << " = " << a << endl;
#else
  #define deb(a)
#endif
#define sz(a) (int)(a).size()


#include <bits/stdc++.h>

using namespace std;
//mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnd(time(0));

typedef long long ll;

int solve()
{
  int n;
  if (!(cin >> n))
    return 1;
  string s;
  cin >> s;
  if (n % 2 == 1 || s[0] == ')' || s.back() == '(')
  {
      cout << ":(\n";
      return 0;
  }
  string t = "";
  for (int i = 1; i + 1 < n; i++)
    t.push_back(s[i]);
  s = t;
  n = sz(s);
  int op = 0;
  for (int i = 0; i < n; i++)
    if (s[i] == '(')
      op++;
  int bal = 0;
  for (int i = 0; i < n; i++)
  {
      if (s[i] == '(')
      {
          bal++;
          op--;
      }
      else if (s[i] == ')')
      {
          bal--;
          if (bal < 0)
          {
              cout << ":(\n";
              return 0;
          }
      }
      else
      {
          int cnt = n - i - 1;
          int degbal = op - (cnt - op);
          if (bal + 1 + degbal <= 0)
              s[i] = '(', bal++;
          else
              s[i] = ')', bal--;
          if (bal < 0)
          {
              cout << ":(\n";
              return 0;
          }
      }
  }
  if (bal != 0)
  {
      cout << ":(\n";
      return 0;
  }
  cout << '(';
  cout << s;
  cout << ")\n";
  return 0;
}

int32_t main()
{
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int TET = 1;
  //cin >> TET;
  while (TET--)
  {
    if (solve())
      break;
    #ifdef ONPC
      cout << "\n__________________________" << endl;
    #endif
  }
  #ifdef ONPC
    cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
  #endif
  return 0;
}