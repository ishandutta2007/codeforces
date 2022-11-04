#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=100005;
const int N=105;

int p[N];
int ans[N];

struct node
{
    int sum,last,id;
    node(){}
    node(int sum_,int last_,int id_)
    {
        sum=sum_;
        last=last_;
        id=id_;
    }
    bool operator <(const node t)const
    {
        return sum==t.sum ? last<t.last : sum>t.sum;
    }
}vote[N];

int main()
{
    int n,k,m,a;
    scanf("%d%d%d%d",&n,&k,&m,&a);
    for(int i=0;i<a;i++) scanf("%d",&p[i]),p[i]--;

    for(int now=0;now<n;now++)
    {
        for(int i=0;i<n;i++) vote[i].sum=0,vote[i].id=i;
        for(int i=a;i<m;i++) p[i]=now;
        for(int i=0;i<m;i++) vote[p[i]].sum++,vote[p[i]].last=i;
        sort(vote,vote+n);
        bool f=0;
        for(int i=0;i<k;i++)
        {
            //cout<<vote[i].sum<<" "<<vote[i].id<<endl;
            if(vote[i].sum<=0) break;
            if(vote[i].id==now)
            {
                f=1;
                break;
            }
        }
        if(!f) ans[now]=3;
    }

    for(int now=0;now<n;now++)
    {
        if(ans[now]==3) continue;
        for(int i=0;i<n;i++) vote[i].sum=0,vote[i].id=i;
        for(int i=0;i<a;i++) vote[p[i]].sum++,vote[p[i]].last=i;
        sort(vote,vote+n);

        int rk;
        for(int i=0;i<n;i++)
        {
            if(vote[i].id==now)
            {
                rk=i;
                break;
            }
        }
        bool f=0;
        int left=m-a;
        if(rk<k && vote[rk].sum>0)
        {
            if(n==k) f=1;
            else
            {
                for(int i=rk+1;i<=k;i++)
                {
                    left-=vote[rk].sum+1-vote[i].sum;
                    if(left<0)
                    {
                        f=1;
                        break;
                    }
                }
            }
        }

        if(f) ans[now]=1;
        else ans[now]=2;
    }
    for(int i=0;i<n;i++) printf("%d%c",ans[i],i+1==n?'\n':' ');
    return 0;
}