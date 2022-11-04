#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    printf("YES\n");
    for(int i=1;i<=n;i++)
    {
        int x,y;
        scanf("%d%d%*d%*d",&x,&y);
        printf("%d\n",2*(x&1)+(y&1)+1);
    }
    return 0;
}