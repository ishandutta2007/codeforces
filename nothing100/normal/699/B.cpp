#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<string>
#define mo 1000000007
using namespace std;
struct point
{
    int x,y;
}po[1000010];
int n,m,bo,num,ansl[2],ansh[2],anum;
char ch;
int cl(int &x,int &y,int xx,int yy)
{
    if (x==0)
    {
        if ((y==yy)||(yy==0))
        {
            x=xx;
            return 1;
        }
        return 0;
    }
    else if (y==0)
    {
        if ((x==xx)||(xx==0))
        {
            y=yy;
            return 1;
        }
        return 0;
    }
    else
    {
        if (xx==0)
        {
            if (y==yy) return 1;
            else return 0;
        }
        else if (yy==0)
        {
            if (x==xx) return 1;
            else return 0;
        }
        else
        {
            if (x!=xx) return 0;
            if (y!=yy) return 0;
            return 1;
        }
    }
}
int main()
{
    scanf("%d%d\n",&n,&m);
    bo=1;
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=m;j++)
        {
            ch=getchar();
            if (ch=='*')
            {
                po[num].x=i;
                po[num++].y=j;
            }
        }
        scanf("\n");
    }
    if (num>=n+m) printf("NO");
    else if (num==0)
    {
        printf("YES\n");
        printf("1 1");
    }
    else if (num==1)
    {
        printf("YES\n");
        printf("%d %d",po[0].x,po[0].y);
    }
    else if (num==2)
    {
        printf("YES\n");
        printf("%d %d",po[0].x,po[1].y);
    }
    else
    {
        for (int i=0;i<num;i++)
        for (int j=i+1;j<num;j++)
        {
            if ((po[i].x!=po[j].x)&&(po[i].y!=po[j].y))
            {
                if (anum==0)
                {
                    anum=2;
                    ansl[0]=po[i].x;
                    ansh[0]=po[j].y;
                    ansl[1]=po[j].x;
                    ansh[1]=po[i].y;
                }
                else if (anum==1)
                {
                    if ((!cl(ansl[0],ansh[0],po[i].x,po[j].y))&&(!cl(ansl[0],ansh[0],po[j].x,po[i].y))) bo=0;
                }
                else if (anum==2)
                {
                    if ((!cl(ansl[0],ansh[0],po[i].x,po[j].y))&&(!cl(ansl[0],ansh[0],po[j].x,po[i].y)))
                    {
                        anum--;
                        ansl[0]=ansl[1];
                        ansh[0]=ansh[1];
                    }
                    else anum--;
                    if ((!cl(ansl[0],ansh[0],po[i].x,po[j].y))&&(!cl(ansl[0],ansh[0],po[j].x,po[i].y))) bo=0;
                }
            }
            else if (po[i].x!=po[j].x)
            {
                if (anum==0)
                {
                    anum=1;
                    ansl[0]=0;
                    ansh[0]=po[i].y;
                }
                else if (anum==1)
                {
                    if ((!cl(ansl[0],ansh[0],0,po[j].y))&&(!cl(ansl[0],ansh[0],0,po[i].y))) bo=0;
                }
                else if (anum==2)
                {
                    if ((!cl(ansl[0],ansh[0],0,po[j].y))&&(!cl(ansl[0],ansh[0],0,po[i].y)))
                    {
                        anum--;
                        ansl[0]=ansl[1];
                        ansh[0]=ansh[1];
                    }
                    else anum--;
                    if ((!cl(ansl[0],ansh[0],0,po[j].y))&&(!cl(ansl[0],ansh[0],0,po[i].y))) bo=0;
                }
            }
            else if (po[i].y!=po[j].y)
            {
                if (anum==0)
                {
                    anum=1;
                    ansl[0]=po[i].x;
                    ansh[0]=0;
                }
                else if (anum==1)
                {
                    if ((!cl(ansl[0],ansh[0],po[i].x,0))&&(!cl(ansl[0],ansh[0],po[i].x,0))) bo=0;
                }
                else if (anum==2)
                {
                    if ((!cl(ansl[0],ansh[0],po[i].x,0))&&(!cl(ansl[0],ansh[0],po[i].x,0)))
                    {
                        anum--;
                        ansl[0]=ansl[1];
                        ansh[0]=ansh[1];
                    }
                    else anum--;
                    if ((!cl(ansl[0],ansh[0],po[i].x,0))&&(!cl(ansl[0],ansh[0],po[i].x,0))) bo=0;
                }
            }
        }
        if (bo)
        {
            printf("YES\n");
            if (ansl[0]==0) printf("1 %d",ansh[0]);
            else if (ansh[0]==0) printf("%d 1",ansl[0]);
            else printf("%d %d",ansl[0],ansh[0]);
        }
        else printf("NO");
    }
    return 0;
}