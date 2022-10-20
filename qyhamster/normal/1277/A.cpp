#include <iostream>
using namespace std;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while(T--)
  {
    int n;
    cin>>n;
    int ans = 0, a[10], cnt = 0;
    while(n)
    {
      ans += min(9, n);
      a[cnt++] = n%10;
      n /= 10;
    }
    bool check = 0;
    for(int i = cnt-2; i >= 0; i--)
    {
      if(a[i] != a[cnt-1])
      {
        if(a[i] < a[cnt-1])check = 1;
        break;
      }
    }
    cout << ans - check << '\n';
  }
  return 0;
}