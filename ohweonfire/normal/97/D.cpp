#include <bits/stdc++.h>
using namespace std;
const int maxn=155,maxk=100005;
bitset<maxn*maxn> now,wall,pass,goal;
char opr[maxk],field[maxn][maxn];
int n,m,k;
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<n;i++)
    {
        scanf("%s",field[i]);
        for(int j=0;j<m;j++)
            if(field[i][j]!='#')
            {
                now.set(i*m+j);
                if(field[i][j]=='E')
                    goal.set(i*m+j);
            }
            else
                wall.set(i*m+j);
    }
    pass=now;
    scanf("%s",opr);
    if(now==goal)
    {
        puts("0");
        return 0;
    }
    for(int i=0;i<k;i++)
    {
        if(opr[i]=='U')
            now=((now>>m)&pass)|(now&(wall<<m));
        if(opr[i]=='D')
            now=((now<<m)&pass)|(now&(wall>>m));
        if(opr[i]=='L')
            now=((now>>1)&pass)|(now&(wall<<1));
        if(opr[i]=='R')
            now=((now<<1)&pass)|(now&(wall>>1));
        if(now==goal)
        {
            printf("%d\n",i+1);
            return 0;
        }
    }
    puts("-1");
    return 0;
}