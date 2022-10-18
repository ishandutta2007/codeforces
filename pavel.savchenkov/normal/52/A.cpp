#include <cstdio>
#include <vector>

using namespace std;

int main() {
 int n;
 scanf("%d",&n);
 vector <int> k(4,0);
 for (int i=1;i<=n;i++)
  {int a;scanf("%d",&a); k[a]++;}
 int max=1;
 for (int i=1;i<=3;i++)
  if (k[i]>k[max]) max=i;
 printf("%d",n-k[max]);
 return 0;
 }