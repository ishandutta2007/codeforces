#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int num[31],a[maxn];
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  for(int i = 0; i < n; i++)
  {
    cin >> a[i];
    int x = a[i];
    int cnt = 0;
    while(x)
    {
      num[cnt++] += x&1;
      x /= 2;
    }
  }
  int key_bit = 0, first = 0;
  for(int i = 30; i >= 0; i--)
  {
    if(num[i] == 1)
    {
      key_bit = i;
      break;
    }
  }
  for(int i = 0; i < n; i++)
  {
    if(a[i] & (1<<key_bit))
    {
      first = i;
      break;
    }
  }
  cout << a[first];
  for(int i = 0; i < n; i++)
  {
    if(i == first) continue;
    cout << " " << a[i];
  }
  cout << endl;
  return 0;
}