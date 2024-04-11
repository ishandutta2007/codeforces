#include<bits/stdc++.h>
using namespace std;
const int MAXN=1000005;
int sum[1<<21],pmx[1<<21],pmi[1<<21];
void push_up(int n)
{
    sum[n]=sum[n<<1]+sum[n<<1|1];
    pmi[n]=min(pmi[n<<1],pmi[n<<1|1]+sum[n<<1]);
    pmx[n]=min(pmx[n<<1],pmx[n<<1|1]-sum[n<<1]);
}
void update(int p,int v,int l,int r,int n)
{
    if(l==r)
    {
        sum[n]=pmi[n]=v,pmx[n]=-v;
        return;
    }
    int m=(l+r)/2;
    if(p<=m)update(p,v,l,m,n<<1);
    else update(p,v,m+1,r,n<<1|1);
    push_up(n);
}
char str[MAXN];
int main()
{
    int n,cur=1;
    scanf("%d%s",&n,str);
    for(int i=0;i<n;i++)
    {
        if(str[i]=='L')cur=max(cur-1,1);
        else if(str[i]=='R')cur++;
        else if(str[i]=='(')update(cur,1,1,n,1);
        else if(str[i]==')')update(cur,-1,1,n,1);
        else update(cur,0,1,n,1);
        printf("%d%c",(sum[1]==0 && pmi[1]>=0 ? -pmx[1] : -1)," \n"[i==n-1]);
    }
    return 0;
}