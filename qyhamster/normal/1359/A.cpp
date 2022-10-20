#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while(T--)
  {
    int n,m,k;
    cin >> n >> m >> k;
    int d = n/k;
    if(m <= d) cout << m << endl;
    else
    {
      cout << d - (m-d-1)/(k-1) - 1 << endl;
    }
  }
  return 0;
}