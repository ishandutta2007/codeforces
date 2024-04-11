#include <iostream>
#include <algorithm>
#include <cstring>
#include <set>
#include <queue>
#define pii pair<long long,long long>
using namespace std;
const int maxn = 3e5 + 10;
const int maxr = 1e6 + 10;
const int MOD = 1000000007;
#define int long long
int a[maxn], t[maxn];
int32_t main()
{
  int n,k;
  cin >> n >> k;
  cout << "? 1" << endl;
  int x;
  cin >> x;
  int cur = 1;
  for(int i = 1; i < 500; i++)
  {
    cout << "? " << cur << endl;
    cin >> x;
    if(x > k) break;
    cur += i;
    cur %= n;
    if(cur == 0) cur = n;
  }
  while(x != k)
  {
    cur--;
    if(cur == 0) cur = n;
    cout << "? " << cur << endl;
    cin >> x;
  }
  cout << "! " << cur << endl;
}