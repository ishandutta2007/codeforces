#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int t,x,s;
int main()
{
    scanf("%d%d%d",&t,&s,&x);
    if ((x>=t)&&(x!=t+1)&&(((x-t)%s==1)||((x-t)%s==0))) printf("YES");
    else printf("NO");
    return 0;
}