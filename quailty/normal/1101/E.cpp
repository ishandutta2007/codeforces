#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    int mx=0,my=0;
    for(int i=1;i<=n;i++)
    {
        char t[5];
        int x,y;
        scanf("%s%d%d",t,&x,&y);
        if(x>y)swap(x,y);
        if(*t=='+')
        {
            mx=max(mx,x);
            my=max(my,y);
        }
        else
        {
            if(mx<=x && my<=y)printf("YES\n");
            else printf("NO\n");
        }
    }
    return 0;
}