#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
char s[15];
const int d[8][3]=
{
    {0,1,2},{3,4,5},{6,7,8},
    {0,3,6},{1,4,7},{2,5,8},
    {0,4,8},{2,4,6}
};
void turn(int p)
{
    if(!p)printf("first");
    else printf("second");
    exit(0);
}
void win(int p)
{
    if(!p)printf("the first player won");
    else printf("the second player won");
    exit(0);
}
void illegal()
{
    printf("illegal");
    exit(0);
}
int check()
{
    int res=0;
    for(int i=0;i<8;i++)
    {
        if(s[d[i][0]]=='.')continue;
        bool flag=1;
        for(int j=0;j<3;j++)
            if(s[d[i][j]]!=s[d[i][0]])flag=0;
        if(flag)res|=(s[d[i][0]]=='X' ? 1 : 2);
    }
    return res;
}
int main()
{
    for(int i=0;i<3;i++)
        scanf("%s",s+3*i);
    int cnt[2]={0,0};
    for(int i=0;i<9;i++)
    {
        if(s[i]=='X')cnt[0]++;
        if(s[i]=='0')cnt[1]++;
    }
    if(cnt[0]<cnt[1] || cnt[0]>cnt[1]+1)illegal();
    if(cnt[0]==cnt[1])
    {
        if(check())
        {
            if(check()!=2)illegal();
            else win(1);
        }
        else turn(0);
    }
    else
    {
        if(check())
        {
            if(check()!=1)illegal();
            else win(0);
        }
        else if(cnt[0]<5)turn(1);
        else return 0*printf("draw");
    }
}