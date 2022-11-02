#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<map>
#include<cassert>
#include<string>
using namespace std;
#define pb push_back
#define mp make_pair
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
const int N=15010;
int c[4][N],a[N],fl[2][N],fr[2][N],n;
void modify(int c[],int x,int y){for(;x<=n;x+=x&(-x))c[x]=max(c[x],y);}
int get(int c[],int x){int res=-n-1;for(;x;x-=x&(-x))res=max(res,c[x]);return res;}
void updatemax(int&x,int y){x=max(x,y);}
void updatemin(int&x,int y){x=min(x,y);}
int work(int k)
{
    for(;;k++)
    {
        for(int j=0;j<4;j++)rep(i,n)c[j][i]=-n-1;
        rep(i,n)fl[!(k&1)][i]=n+1,fr[!(k&1)][i]=0;
        for(int i=n;i;i--)
        {
            if(i+1<=n)modify(c[0],n-a[i+1]+1,-fl[k&1][i+1]),modify(c[2],a[i+1],fr[k&1][i+1]);
            if(i+k<=n)modify(c[1],fl[k&1][i+k],a[i+k]),modify(c[3],n-fr[k&1][i+k]+1,-a[i+k]);
            updatemin(fl[!(k&1)][i],-get(c[0],n-a[i]));
            updatemax(fr[!(k&1)][i],get(c[1],a[i]-1));
            updatemax(fr[!(k&1)][i],get(c[2],a[i]-1));
            updatemin(fl[!(k&1)][i],-get(c[3],n-a[i]));
        }
        bool flag=1;
        rep(i,n)if(fl[!(k&1)][i]<=n||fr[!(k&1)][i]>=1){flag=0;break;}
        if(flag)return k;
    }
}
int main()
{
    int T;
    for(scanf("%d",&T);T--;)
    {
        scanf("%d",&n);
        rep(i,n)scanf("%d",&a[i]);
        rep(i,n-1)fl[1][i]=n+1,fr[1][i]=0;
        fl[1][n]=fr[1][n]=a[n];
        int ans=work(1);
        rep(i,n)fl[0][i]=fr[0][i]=a[i];
        printf("%d\n",max(ans,work(2)-1));
    }
    return 0;
}