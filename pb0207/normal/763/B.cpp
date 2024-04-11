#include<cstdio>
#include<iostream>
using namespace std;

int n;

int main()
{
    scanf("%d", &n);
        printf("YES\n");
        for(int i=1;i<=n;i++)
		{
            int x1,y1,x2,y2;
            scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
            if(x2&1)
                printf(y2&1 ?"3\n":"1\n");
            else
                printf(y2&1 ?"4\n":"2\n");
        }
}