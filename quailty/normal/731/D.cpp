#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=500005;
const int MAXC=1000005;
int st[MAXN],len[MAXN],w[MAXC],ok[MAXC];
void fail()
{
    exit(0*printf("-1"));
}
void solve(int l,int r,int d,int c)
{
    while(l<=r && len[l]<=d)l++;
    for(int i=l;i<=r;i++)
        if(len[i]<=d)fail();
    for(int i=l;i<r;i++)
    {
        int x=w[st[i]+d],y=w[st[i+1]+d];
        if(x<y)ok[c-y+1]++,ok[c-x+1]--;
        if(x>y)ok[0]++,ok[c-x+1]--,ok[c-y+1]++;
    }
    for(int i=l,j=l;i<=r;i=j)
    {
        while(j<=r && w[st[i]+d]==w[st[j]+d])j++;
        solve(i,j-1,d+1,c);
    }
}
int main()
{
    int n,c,tot=0;
    scanf("%d%d",&n,&c);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&len[i]);
        st[i]=tot;
        for(int j=0;j<len[i];j++)
            scanf("%d",&w[tot++]);
    }
    solve(1,n,0,c);
    for(int i=1;i<c;i++)
        ok[i]+=ok[i-1];
    int res=-1;
    for(int i=0;i<c;i++)
        if(!ok[i])res=i;
    return 0*printf("%d",res);
}