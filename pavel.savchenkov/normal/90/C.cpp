#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
 long long n,m,k;
 scanf("%I64d%I64d%I64d",&n,&m,&k);
 if (n%2==0) {printf("0");return 0;}
 long long x=m/((n+1)/2); x*=k;
 long long res=2000000000;
 for (int i=1;i<=n;i++)
  {long long a; scanf("%I64d",&a);if (i%2==1) res=min(res,a);}
 res=min(res,x); 
 printf("%I64d",res);
 return 0;
 }