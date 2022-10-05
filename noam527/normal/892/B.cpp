//this is a test
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int Math_Max(long num1, long num2)
{
	if (num1 < num2)
		return num2;
	return num1;
}
int main()
{ 
   ios::sync_with_stdio(0);
   long long n, cnt1 = 0, cnt2 = 0;
   cin >> n;
   vector<long long> a(n);
   for (int i = 0; i < n; i++)
	   cin >> a[i];
   for (long long i = n - 1; i >= 0; i--)
   {
	   if (cnt1 == 0)
	   {
		   cnt1 = a[i];
		   cnt2++;
	   }
	   else
	   {
		   cnt1--;
		   cnt1 = Math_Max(cnt1, a[i]);
	   }
   }
   cout << cnt2 << endl;
}