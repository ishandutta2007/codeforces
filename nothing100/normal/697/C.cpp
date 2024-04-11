#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
struct que
{
    long long x,y;
}qu[200000];
int n,len[1000],m;
long long ques[1000][4],point[1000][200],num[200000],ans;
int cmp(que x,que y)
{
    return x.x<y.x;
}
int length(long long x)
{
    int o=0;
    while (x>>o) o++;
    return o;
}
void lca(long long x,long long y,int z)
{
    if (x>y) swap(x,y);
    int o=length(x);
    int p=length(y);
    while (p!=o)
    {
        point[z][len[z]++]=y;
        y=y>>1;
        p--;
    }
    while (x!=y)
    {
        point[z][len[z]++]=y;
        point[z][len[z]++]=x;
        x=x>>1;
        y=y>>1;
    }
    return;
}
int main()
{
    scanf("%d",&n);
    for (int i=0;i<n;i++)
    {
        scanf("%I64d",&ques[i][0]);
        if (ques[i][0]==1) scanf("%I64d%I64d%I64d",&ques[i][1],&ques[i][2],&ques[i][3]);
        else scanf("%I64d%I64d",&ques[i][1],&ques[i][2]);
        lca(ques[i][1],ques[i][2],i);
    }
    for (int i=0;i<n;i++)
    for (int j=0;j<len[i];j++)
    {
        qu[m].x=point[i][j];
        qu[m].y=i*200+j;
        m++;
    }
    sort(qu,qu+m,cmp);
    int o=0;
    point[qu[0].y/200][qu[0].y%200]=o;
    for (int i=1;i<m;i++)
    {
        if (qu[i].x!=qu[i-1].x) o++;
        point[qu[i].y/200][qu[i].y%200]=o;
    }
    for (int i=0;i<n;i++)
    {
        if (ques[i][0]==1)
        {
            for (int j=0;j<len[i];j++) num[point[i][j]]=num[point[i][j]]+ques[i][3];
        }
        else
        {
            ans=0;
            for (int j=0;j<len[i];j++) ans=ans+num[point[i][j]];
            printf("%I64d\n",ans);
        }
    }
    return 0;
}