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
int n;

int main() {
   // freopen("input.txt","r",stdin);
   //freopen("output.txt","w",stdout);
   scanf("%d",&n); int a[n+1]; int rmin = 1; int rmax = 1;
   for (int i=1;i<=n;i++) { scanf("%d",&a[i]); if (a[i] > a[rmax]) rmax = i; if (a[i] <= a[rmin]) rmin = i; }
   if (a[rmax] == a[rmin]) { cout << "0"; return 0; }
   if (rmax > rmin) { cout << rmax + n - rmin - 2; return 0; }
   cout << rmax + n - rmin - 1;
   return 0;
}