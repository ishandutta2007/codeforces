//#pragma comment (linker, "/STACK:200000000") 
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <bitset>
#include <set>
#include <map>
#define pb push_back
#define eps 1e-9
#define inf 2000000000
using namespace std;

int main() {
   //freopen("input.txt","r",stdin);
   //freopen("output.txt","w",stdout);
   int n;scanf("%d",&n);
   int d[8];
   for (int i=1;i<=7;i++)
	   scanf("%d",&d[i]);
   
   int nn=0;
   while (true)
   {
	   for (int i=1;i<=7;i++)
		   if (nn+d[i]>=n) {cout<<i;return 0;} else nn+=d[i];
   }
   return 0;
}