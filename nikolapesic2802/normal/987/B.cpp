#include <bits/stdc++.h>

using namespace std;
int odgovori(int a,int b)
{
    if(a==2&&b==3)
    {
        printf("<\n");
        return 1;
    }
    if(a==3&&b==2)
    {
        printf(">\n");
        return 2;
    }
    if(a==b||(a==4&&b==2)||(a==2&&b==4))
    {
        printf("=\n");
        return 0;
    }
    if(a==1)
    {
        printf("<\n");
        return 1;
    }
    if(b==1)
    {
        printf(">\n");
        return 2;
    }
    if(a<b)
    {
        printf(">\n");
        return 2;
    }
    printf("<\n");
    return 1;
}
int main()
{
    int x,y;
    scanf("%i %i",&x,&y);
    odgovori(x,y);
    return 0;
}