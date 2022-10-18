//#pragma comment (linker, "/STACK:200000000") 
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#define pb push_back
const double eps = 1e-9;
const int inf = 2000000000;
using namespace std;

int main() {
    //freopen("input.txt","r",stdin);
   //freopen("output.txt","w",stdout);
   int r1,r2,c1,c2,d1,d2;
   cin>>r1>>r2>>c1>>c2>>d1>>d2;
   for (int i=1;i<=9;i++)
   for (int j=1;j<=9;j++)
   for (int k=1;k<=9;k++)
   for (int x=1;x<=9;x++)
   {
	   if (i+j==r1 && k+x==r2 && i+k==c1 && j+x==c2 && k+j==d2 && i+x==d1 && i!=j && j!=k && i!=k && i!=x && k!=x && j!=x)
	   {
		   cout << i << " " << j << endl;
		   cout << k << " " << x << endl;
		   return 0;
	   }
   }
   
   puts("-1");
   return 0;
}