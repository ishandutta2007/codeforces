#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
char x[105],y[105];
int main()
{
    scanf("%s%s",x,y);
    for(int i=0;x[i];i++)
        if(x[i]<y[i])return 0*printf("-1\n");
    return 0*printf("%s\n",y);
}