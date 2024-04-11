#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<list>
using namespace std;
const int MAXN=300005;
#define ft first
#define sd second
list<pair<int,int> >lt;
int cnt[MAXN],la[MAXN];
int main()
{
    int n,q,tot=0,sum=0;
    scanf("%d%d",&n,&q);
    for(int i=1;i<=q;i++)
    {
        int ty,x;
        scanf("%d%d",&ty,&x);
        if(ty==1)
        {
            lt.push_back(make_pair(++tot,x));
            cnt[x]++;
            sum++;
        }
        else if(ty==2)
        {
            sum-=cnt[x];
            cnt[x]=0;
            la[x]=tot;
        }
        else
        {
            for(auto itr=lt.begin();itr!=lt.end();)
            {
                if(itr->ft > x)break;
                if(itr->ft > la[itr->sd])
                {
                    sum--;
                    cnt[itr->sd]--;
                }
                lt.erase(itr++);
            }
        }
        printf("%d\n",sum);
    }
    return 0;
}