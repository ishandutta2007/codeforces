#include <bits/stdc++.h>
using namespace std;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  int sq = sqrt(n);
  for(int i = sq; i > 0; i--)
  {
    if(n % i == 0)
    {
      cout << i << n/i << endl;
      exit(0);
    }
  }
  return 0;
}