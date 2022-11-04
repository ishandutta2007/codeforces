#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<bitset>
using namespace std;
const int MAXN=1000;
const int MAXM=200000;
vector<int>e[MAXN];
int v[MAXM],u[MAXM];
struct query
{
    int l,r,id;
    query(){}
    query(int _l,int _r,int _id):l(_l),r(_r),id(_id){}
};
int res[MAXM];
bitset<MAXN>dpl[MAXM],dpr[MAXM];
void solve(vector<query>&que,int l,int r)
{
    if(que.empty())return;
    if(l==r)
    {
        for(int i=0;i<(int)que.size();i++)res[que[i].id]=1;
        return;
    }
    int m=(l+r)/2;
    for(int i=m;i>=l;i--)dpl[i].reset();
    for(int i=m;i>=l;i--)
    {
        dpl[i][u[i]]=dpl[i][v[i]]=1;
        int tmp=*upper_bound(e[u[i]].begin(),e[u[i]].end(),i);
        if(tmp<=m)dpl[i]|=dpl[tmp];
        tmp=*upper_bound(e[v[i]].begin(),e[v[i]].end(),i);
        if(tmp<=m)dpl[i]|=dpl[tmp];
    }
    for(int i=m+1;i<=r;i++)dpr[i].reset();
    for(int i=m+1;i<=r;i++)
    {
        dpr[i][u[i]]=dpr[i][v[i]]=1;
        int tmp=*--lower_bound(e[u[i]].begin(),e[u[i]].end(),i);
        if(tmp>=m+1)dpr[i]|=dpr[tmp];
        tmp=*--lower_bound(e[v[i]].begin(),e[v[i]].end(),i);
        if(tmp>=m+1)dpr[i]|=dpr[tmp];
    }
    vector<query>lef,rig;
    for(int i=0;i<(int)que.size();i++)
    {
        if(que[i].r<=m)lef.push_back(que[i]);
        else if(que[i].l>=m+1)rig.push_back(que[i]);
        else res[que[i].id]=(dpl[que[i].l]&dpr[que[i].r]).any();
    }
    que.clear();
    solve(lef,l,m);
    solve(rig,m+1,r);
}
int main()
{
    int n,m,q;
    scanf("%d%d%d",&n,&m,&q);
    for(int i=0;i<n;i++)
    {
        e[i].push_back(-1);
        e[i].push_back(m);
    }
    for(int i=0;i<m;i++)
    {
        scanf("%d%d",&v[i],&u[i]);
        e[--v[i]].push_back(i);
        e[--u[i]].push_back(i);
    }
    for(int i=0;i<n;i++)
        sort(e[i].begin(),e[i].end());
    vector<query>que;
    for(int i=0;i<q;i++)
    {
        int l,r,s,t;
        scanf("%d%d%d%d",&l,&r,&s,&t);
        l--,r--,s--,t--;
        l=*lower_bound(e[s].begin(),e[s].end(),l);
        r=*--upper_bound(e[t].begin(),e[t].end(),r);
        if(l<=r)que.push_back(query(l,r,i));
    }
    solve(que,0,m-1);
    for(int i=0;i<q;i++)
        printf("%s\n",(res[i] ? "Yes" : "No"));
    return 0;
}