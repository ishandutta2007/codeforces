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
  int m, h;
  cin >> m >> h;
  vector<int> a(m), b(n);
  vector<vector<int> > v(n, vector<int>(m, 0));
  for (int &i : a)
    cin >> i;
  for (int &i : b)
    cin >> i;
  for (auto &it : v)
    for (int &i : it)
      cin >> i;
  for (int i = 0; i < n; i++)
  {
      for (int j = 0; j < m; j++)
      {
          if (!v[i][j])
              cout << "0 ";
          else
              cout << min(b[i], a[j]) << ' ';
      }
      cout << '\n';
  }
  return 0;
}

int32_t main()
{
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int TET = 1e9;
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