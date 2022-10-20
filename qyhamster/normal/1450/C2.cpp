#include <iostream>
#include <cmath>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <iomanip>
#include <random>
#include <stack>
using namespace std;
#define int long long
#define pii pair<long long, long long>
const double pi = acos(-1);
const int maxn = 300 + 10;
const int mod = 998244353;
int x[maxn],y[maxn];
string s[maxn];
int cnt[2][3];
int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while(T--)
  {
    memset(cnt,0,sizeof(cnt));
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
      cin >> s[i];
    }
    for(int i = 0; i < n; i++)
    {
      for(int j = 0; j < n; j++)
      {
        if(s[i][j] == 'X') cnt[0][(i+j)%3]++;
        if(s[i][j] == 'O') cnt[1][(i+j)%3]++;
      }
    }
    int mn = 1000000000, cand = -1;
    for(int i = 0; i < 3; i++)
    {
      if(cnt[0][i] + cnt[1][(i+1)%3] < mn)
      {
        mn = cnt[0][i] + cnt[1][(i+1)%3];
        cand = i;
      }
    }
    for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
    {
      if(s[i][j] == 'X' && (i+j)%3 == cand) s[i][j] = 'O';
      else if(s[i][j] == 'O' && (i+j)%3 == (cand+1)%3) s[i][j] = 'X';
    }
    for(int i = 0; i < n; i++)
      cout << s[i] << '\n';
  }
  return 0;
}