#include<bits/stdc++.h>
using namespace std;
char str[55][55];
int main()
{
    int c[4];
    for(int i=0;i<4;i++)
        scanf("%d",&c[i]),c[i]--;
    for(int i=0;i<50;i++)
        for(int j=0;j<50;j++)
            str[i][j]='A'+(i/25)*2+(j/25);
    for(int _=0;_<4;_++)
        for(int i=1+25*(1-_/2),x=0;x<10;i+=2,x++)
            for(int j=1+25*(1-_%2),y=0;y<10;j+=2,y++)
                if(c[_]>0)c[_]--,str[i][j]='A'+_;
    printf("%d %d\n",50,50);
    for(int i=0;i<50;i++)
        printf("%s\n",str[i]);
    return 0;
}