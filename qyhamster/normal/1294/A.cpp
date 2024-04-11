#include<iostream>
using namespace std;
int main()
{
  int T;
  cin >> T;
  while(T--)
  {
    int a,b,c,n;
    cin >> a >> b >> c >> n;
    int mx = max(a,max(b,c));
    n -= (mx-a) + (mx-b) + (mx-c);
    if(n >= 0 && n%3 == 0)
    {
      cout << "Yes" << endl;
    }
    else cout << "No" << endl;
  }
  return 0;
}