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
const int maxn = 1e6 + 10;
const int mod = 998244353;

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while(T--)
  {
    int n;
    cin >> n;
    string s;
    cin >> s;
    sort(s.begin(),s.end());
    cout << s << endl;
  }
  return 0;
}