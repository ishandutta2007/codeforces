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
const double eps = 1e-9;
const int inf = 2000000000;
using namespace std;

int main() {
   int n; scanf("%d",&n);
   int a[n+1];
   for (int i=1;i<=n;i++) scanf("%d",&a[i]);
   sort(a+1,a+n+1);
   int s = 10; int f = 0; int m = 0;
   for (int i=1;i<=n;i++)
    if (s+a[i]<360) { s+=a[i]; m++; } else if (s+a[i]>720) break;
     else { s+=a[i]; f+=abs(s-360); m++; }
   cout << m << " " << f << endl;
   return 0;
}