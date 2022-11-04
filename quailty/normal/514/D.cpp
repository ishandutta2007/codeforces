#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=100005;
int m,a[MAXN][7];
struct node
{
    int l,r,m;
    int d[7];
}s[MAXN<<2];
void build(int left,int right,int num)
{
    int mid=(left+right)/2;
    s[num].l=left;
    s[num].r=right;
    s[num].m=mid;
    if(right-left==1)
    {
        for(int i=0;i<m;i++)
            s[num].d[i]=a[left][i];
    }
    else
    {
        build(left,mid,num<<1);
        build(mid,right,num<<1|1);
        for(int i=0;i<m;i++)
            s[num].d[i]=max(s[num<<1].d[i],s[num<<1|1].d[i]);
    }
}
int query(int left,int right,int num,int k)
{
    if(left==s[num].l && right==s[num].r)
        return s[num].d[k];
    else if(right<=s[num].m)
        return query(left,right,num<<1,k);
    else if(left>=s[num].m)
        return query(left,right,num<<1|1,k);
    else
        return max(query(left,s[num].m,num<<1,k),
                   query(s[num].m,right,num<<1|1,k));
}
int main()
{
    int n,k;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;i++)
        for(int j=0;j<m;j++)
            scanf("%d",&a[i][j]);
    build(1,n+1,1);
    int len=0,ans_l,ans_r;
    for(int i=n;i>=1;i--)
    {
        if(i<=len)break;
        int low=1,up=i,t;
        while(up!=low)
        {
            int bet=(up+low)/2;
            t=0;
            for(int j=0;j<m;j++)
                t+=query(bet,i+1,1,j);
            if(t>k)low=bet+1;
            else up=bet;
        }
        t=0;
        for(int j=0;j<m;j++)
            t+=query(low,i+1,1,j);
        if(t>k)continue;
        if(len<i-low+1)
        {
            len=i-low+1;
            ans_l=low;
            ans_r=i;
        }
    }
    int ans[7];
    for(int i=0;i<m;i++)
    {
        if(len>0)ans[i]=query(ans_l,ans_r+1,1,i);
        else ans[i]=0;
    }
    for(int i=0;i<m;i++)
    {
        if(i==0)printf("%d",ans[i]);
        else printf(" %d",ans[i]);
    }
    return 0;
}