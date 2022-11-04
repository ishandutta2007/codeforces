#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int MAXN=100005;
struct node
{
    int t,p,id;
    node(int _t=0,int _p=0,int _id=0):t(_t),p(_p),id(_id){}
    bool operator < (const node &r)const
    {
        return p*r.t==r.p*t ? t<r.t : p*r.t>r.p*t;
    }
}a[MAXN];
vector<int>sol[3];
int main()
{
    int n,v;
    scanf("%d%d",&n,&v);
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&a[i].t,&a[i].p);
        a[i].id=i+1;
    }
    sort(a,a+n);
    int now=0,sum=0,tmp=0;
    while(now<n && sum+a[now].t<=v)
    {
        sol[2].push_back(a[now].id);
        sum+=a[now].t;
        tmp+=a[now].p;
        now++;
    }
    if(sum==v)
    {
        printf("%d\n",tmp);
        for(int i=0;i<(int)sol[2].size();i++)
            printf("%d ",sol[2][i]);
        return 0;
    }
    int res[2]={tmp,tmp};
    sol[0]=sol[1]=sol[2];
    for(int i=now;i<n;i++)
        if(a[i].t==1)
        {
            res[0]+=a[i].p;
            sol[0].push_back(a[i].id);
            break;
        }
    bool flag=0;
    for(int i=now-1;i>=0;i--)
        if(a[i].t==1)
        {
            flag=1;
            res[1]-=a[i].p;
            sol[1].erase(find(sol[1].begin(),sol[1].end(),a[i].id));
            break;
        }
    if(flag)for(int i=now;i<n;i++)
        if(a[i].t==2)
        {
            res[1]+=a[i].p;
            sol[1].push_back(a[i].id);
            break;
        }
    int out=0;
    if(res[0]<res[1])out=1;
    printf("%d\n",res[out]);
    for(int i=0;i<(int)sol[out].size();i++)
        printf("%d ",sol[out][i]);
    return 0;
}