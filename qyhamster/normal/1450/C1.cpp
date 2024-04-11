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
    int mn[2] = {10000000,10000000}, cand[2]={-1,-1};
    for(int l = 0; l < 2; l++)
    for(int i = 0; i < 3; i++)
    {
      if(cnt[l][i] < mn[l])
      {
        mn[l] = cnt[l][i];
        cand[l] = i;
      }
    }
    for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
    {
      if(s[i][j] == 'X' && (i+j)%3 == cand[0]) s[i][j] = 'O';
      else if(s[i][j] == 'O' && (i+j)%3 == cand[1]) s[i][j] = 'X';
    }
    for(int i = 0; i < n; i++)
      cout << s[i] << '\n';
  }
  return 0;
}