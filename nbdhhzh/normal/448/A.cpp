#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int x,y,z,a,b,c;
int main()
{
    scanf("%d%d%d",&x,&y,&z);a=x+y+z;
    scanf("%d%d%d",&x,&y,&z);b=x+y+z;
    scanf("%d",&c);
    if ((a+4)/5+(b+9)/10<=c)printf("YES");
    else printf("NO");
}