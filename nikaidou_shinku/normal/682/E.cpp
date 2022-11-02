#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=5005;
struct node
{
    ll x,y;
    node(){}
    node(ll _x,ll _y):x(_x),y(_y){}
    node operator + (const node &t)const
    {
        return node(x+t.x,y+t.y);
    }
    node operator - (const node &t)const
    {
        return node(x-t.x,y-t.y);
    }
} st[MAXN],num[MAXN];
int n,k,e;
ll dis(node p1,node p2)
{
    return (p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y);
}
ll multi(node p1,node p2,node p3)
{
    return (p1.x-p3.x)*(p2.y-p3.y)-(p2.x-p3.x)*(p1.y-p3.y);
}
bool cmp(node p1,node p2)
{
    if(multi(p1,p2,num[0])>0) return true;
    if(multi(p1,p2,num[0])==0&&dis(p1,num[0])<dis(p2,num[0]))return true;
    return false;
}
void Graham()
{
    e=2;
    sort(num+1,num+n,cmp);
    st[0]=num[0];
    st[1]=num[1];
    st[2]=num[2];
    for(int i=3; i<n; i++)
    {
        while(e>1&&multi(num[i],st[e],st[e-1])>=0)
            e--;
        st[++e]=num[i];
    }
}
int res[3];
void rotating_calipers()
{
    e++;
    int q=1;
    ll ans=0;
    st[e]=st[0];
    for(int i=0; i<e; i++)
    {
        q=1;
        for(int p=i+1; p<e; p++)
        {
            while(multi(st[i],st[q+1],st[p])>multi(st[i],st[q],st[p]))
                q=(q+1)%e;
            if(multi(st[i],st[q],st[p])>ans)
            {
                ans=multi(st[i],st[q],st[p]);
                res[0]=i,res[1]=p,res[2]=q;
            }
        }
    }
}
int main()
{
    scanf("%d%*d",&n);
    for(int i=0; i<n; i++)
    {
        scanf("%I64d%I64d",&num[i].x,&num[i].y);
        if(num[i].x<num[k].x||(num[i].x==num[k].x&&num[i].y<num[k].y)) k=i;
    }
    swap(num[0],num[k]);
    Graham();
    rotating_calipers();
    printf("%I64d %I64d\n",(st[res[0]]+st[res[2]]-st[res[1]]).x,(st[res[0]]+st[res[2]]-st[res[1]]).y);
    printf("%I64d %I64d\n",(st[res[1]]+st[res[0]]-st[res[2]]).x,(st[res[1]]+st[res[0]]-st[res[2]]).y);
    printf("%I64d %I64d\n",(st[res[2]]+st[res[1]]-st[res[0]]).x,(st[res[2]]+st[res[1]]-st[res[0]]).y);
    return 0;
}