#include <iostream>
#include <cstring>
using namespace std;
const int maxn = 400005;
bool res[maxn];
int a[maxn], rev[maxn];
int main()
{
  int T;
  cin >> T;
  while(T--)
  {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
      cin >> a[i];
    }
    if(n <= 8)
    {
      cout << "0 0 0" << endl;
      continue;
    }
    int bronze = n/2;
    while(bronze > 0 && a[bronze] == a[bronze+1]) bronze--;
    int gold = 1;
    while(gold < n/2 && a[gold] == a[gold+1]) gold++;
    int silver = gold * 2 + 1;
    while(silver < n && a[silver] == a[silver+1]) silver++;
    if(bronze - silver <= gold)
    {
      cout << "0 0 0" << endl;
      continue;
    }
    cout << gold << " " << silver - gold << " " << bronze - silver << endl;
  }
  return 0;
}