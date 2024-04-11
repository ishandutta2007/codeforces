#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 100005;
int a[maxn], winner;
void print()
{
  if(winner) cout << "sjfnb" << endl;
  else cout << "cslnb" << endl;
  exit(0);
}
int main()
{
  long long n;
  cin >> n;
  for(int i = 0; i < n; i++)
    cin >> a[i];
  if(n == 1)
  {
    if(a[0]%2 == 0) winner = 0;
    else winner = 1;
    print();
  }
  sort(a,a+n);
  int minus = 0;
  for(int i = 1; i < n; i++)
  {
    if(a[i] == a[i-1])
    {
      a[i-1]--;
      minus++;
      break;
    }
  }
  if(a[0] == -1)
  {
    winner = 0;
    print();
  }
  for(int i = 1; i < n; i++)
  {
    if(a[i] == a[i-1])
    {
      winner = 0;
      print();
    }
  }
  long long sum = minus;
  for(int i = 0; i < n; i++)
  {
    sum += a[i];
  }
  sum -= n * (n-1) / 2;
  if(sum&1) winner = 1;
  else winner = 0;
  print();
  return 0;
}