#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
 int n; scanf("%d",&n);
 int a[n];
 for (int i=0; i<n; i++)
  scanf("%d",&a[i]);
 sort(a,a+n);
 int res = 0, k = 1;
 for (int i=1; i<n; i++)
  if (a[i] == a[i-1]) k++; else { res+=k/2; k = 1; }
 res+=k/2;
 printf("%d",res/2);
 return 0;
 }