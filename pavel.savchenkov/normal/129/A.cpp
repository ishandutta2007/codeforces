#include <cstdio>

using namespace std;

int main() {
 int n; scanf("%d",&n); long long s=0; long long k1=0,k2=0;
 int a[n+1];
 for (int i=1;i<=n;i++)
  {scanf("%d",&a[i]);s+=a[i]; if (a[i]%2==0) k1++; else k2++;}
 if (s%2==0) printf("%d",k1); else printf("%d",k2);
 return 0;
 }