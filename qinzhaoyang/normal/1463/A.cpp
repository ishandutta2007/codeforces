#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int T;

int main()
{
 ios::sync_with_stdio(false);
 cin >> T;
 while(T--)
 {
  int a , b , c;
  cin >> a >> b >> c;
  int sum = a + b + c;
  if(sum % 9 != 0)
  {
   cout << "NO" << endl;
   continue;
  }
  int min1 = min(a , min(b , c));
  if(min1 < sum / 9)
   cout << "NO" << endl;
  else
   cout << "YES" << endl;
 }
 return 0;
}