#include <cstdio>

using namespace std;

int main() {
 int t; scanf("%d",&t);
 for (int i=1;i<=t;i++)
  {int n;scanf("%d",&n);if (n>=2) printf("%d\n",n-2); else printf("0\n");}
 return 0;
}