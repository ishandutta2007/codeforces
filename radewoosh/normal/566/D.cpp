#include <cstdio>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;

int oj1[1000007];
int oj2[1000007];

int co;
int p1, p2;

int find1(int x)
{
    if (oj1[x]!=x)
    oj1[x]=find1(oj1[x]);
    return oj1[x];
}

int find2(int x)
{
    if (oj2[x]!=x)
    oj2[x]=find2(oj2[x]);
    return oj2[x];
}

void uni1(int v, int u)
{
    if (find1(v)!=find1(u))
    {
        oj1[find1(v)]=find1(u);
    }
}

void uni2(int v, int u)
{
    if (find2(v)!=find2(u))
    {
        oj2[find2(v)]=find2(u);
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i=1; i<=n; i++)
    {
        oj1[i]=i;
        oj2[i]=i;
    }
    while(m--)
    {
        scanf("%d%d%d", &co, &p1, &p2);
        if (co==1)
        {
            uni1(p1, p2);
        }
        if (co==2)
        {
            for (int i=p1; i<=p2; i=i)
            {
                i=find2(i);
                if (i<p2)
                {
                    uni2(i, i+1);
                    uni1(i, i+1);
                }
                else
                break;
            }
        }
        if (co==3)
        {
            if (find1(p1)==find1(p2))
            printf("YES\n");
            else
            printf("NO\n");
        }
    }
    return 0;
}