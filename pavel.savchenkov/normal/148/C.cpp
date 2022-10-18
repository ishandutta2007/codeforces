//#pragma comment (linker, "/STACK:200000000") 
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <math.h>
#define pb push_back
#define i64 long long
const double eps = 1e-9;
const int inf = 2000000000;
const double pi = acos(-1.0);
using namespace std;
int a[201];
int n,aa,bb;

bool check()
{
	int a1 = 0; int b1 = 0;
	int m = a[1];
	
	for (int i=2;i<=n;i++)
	{
		int s = 0;
		for (int j=1;j<i;j++) s+=a[j];
		if (a[i] > s) { b1++; continue; }
		if (a[i] > m) { a1++; m = a[i]; continue; }
	}
	return (a1 == aa && b1 == bb);
};

int main() {
  // freopen("input.txt","r",stdin);
   //freopen("output.txt","w",stdout);
   cin >> n >> aa >> bb;
   if (n == 1)
   {
	   if (!(aa == 0 && bb == 0))  { cout << "-1" << endl; return 0; }
	   cout << "1" << endl;
	   return 0;
   }
   if (bb == 0)
   {
	if (aa == n-1) { cout << "-1" << endl; return 0; }
	a[1] = 1; a[2] = 1;
    for (int i=3; i<3+aa; i++)
    {
		a[i] = a[i-1] + 1;
		if (a[i] > 50000) { cout << "-1" << endl; return 0; }
	}
    for (int i=3+aa; i<=n; i++)
        a[i] = 1;
	if (!check()) { cout << "-1" << endl; return 0; }
	
    for (int i=1;i<=n;i++)
        cout << a[i] << " ";
    return 0;	
   };
   
   
   a[1] = 1; a[0] = 0;
   for (int i=2; i<=bb+1; i++)
	{ 
		a[i] = 0;
		for (int j=1; j<i; j++) a[i]+=a[j];
		a[i]++;
		if (a[i] > 50000) { cout << "-1" << endl; return 0; }
    }
   
   for (int i=bb+2; i<=aa+bb+1; i++)
	{
		a[i] = a[i-1] + 1;
		if (a[i] > 50000) { cout << "-1" << endl; return 0; }
    }
   for (int i=aa+bb+2; i<=n; i++)
	   a[i] = 1;
   
   if (!check()) { cout << "-1" << endl; return 0; }
   
   for (int i=1;i<=n;i++)
	   cout << a[i] << " ";
   return 0;
}