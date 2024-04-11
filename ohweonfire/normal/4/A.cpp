#include <cstdio>
using namespace std;
int a;
int main()
{
scanf("%d",&a);
if(a&1||a==2)printf("NO");
else printf("YES");
return 0;
}