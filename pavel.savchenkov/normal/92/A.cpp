#include <cstdio>

using namespace std;

int main() {
 int n,m;
 scanf("%d%d",&n,&m);
 m%=(n*n+n)/2;
 for (int i=1;i<=n;i++)
  if (m>=i) m-=i; else break;
 printf("%d",m);
 return 0;
 }