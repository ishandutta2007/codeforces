#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
struct rec
{
    int a,b;
}r[5],tr[5];
char s[505][505];
int main()
{
    for(int i=0;i<3;i++)
        scanf("%d%d",&r[i].a,&r[i].b);
    int squ=0;
    for(int i=0;i<3;i++)
        squ+=r[i].a*r[i].b;
    bool flag=0;
    int edge;
    for(int i=1;i*i<=squ;i++)
    {
        if(i*i==squ)
        {
            flag=1;
            edge=i;
        }
    }
    if(flag)
    {
        bool isok=0;
        for(int mask=0;mask<(1<<3);mask++)
        {
            for(int i=0;i<3;i++)
            {
                tr[i]=r[i];
                if(mask&(1<<i))swap(tr[i].a,tr[i].b);
            }
            int type=0;
            for(int i=1;i<=3;i++)
            {
                if(tr[0].a==edge)
                {
                    if(tr[1].a==edge && tr[2].a==edge && tr[0].b+tr[1].b+tr[2].b==edge)
                    {
                        type=i;
                        for(int lin=1;lin<=tr[0].b;lin++)
                        {
                            for(int col=1;col<=edge;col++)
                                s[lin][col]='A'+(type-1)%3;
                        }
                        for(int lin=tr[0].b+1;lin<=tr[0].b+tr[1].b;lin++)
                        {
                            for(int col=1;col<=edge;col++)
                                s[lin][col]='A'+type%3;
                        }
                        for(int lin=tr[0].b+tr[1].b+1;lin<=edge;lin++)
                        {
                            for(int col=1;col<=edge;col++)
                                s[lin][col]='A'+(type+1)%3;
                        }
                        break;
                    }
                    if(tr[1].a+tr[2].a==edge && tr[1].b+tr[0].b==edge && tr[2].b+tr[0].b==edge)
                    {
                        type=i;
                        for(int lin=1;lin<=tr[0].b;lin++)
                        {
                            for(int col=1;col<=edge;col++)
                                s[lin][col]='A'+(type-1)%3;
                        }
                        for(int lin=tr[0].b+1;lin<=edge;lin++)
                        {
                            for(int col=1;col<=tr[1].a;col++)
                                s[lin][col]='A'+type%3;
                            for(int col=tr[1].a+1;col<=edge;col++)
                                s[lin][col]='A'+(type+1)%3;
                        }
                        break;
                    }
                }
                swap(tr[0],tr[1]);
                swap(tr[1],tr[2]);
            }
            if(type)
            {
                isok=1;
                break;
            }
        }
        if(isok)
        {
            printf("%d\n",edge);
            for(int i=1;i<=edge;i++)
                printf("%s\n",s[i]+1);
        }
        else printf("-1\n");
    }
    else printf("-1\n");
    return 0;
}