#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;

inline void check_max(int &x,int y)
{
    if(x<y)x=y;
}

const int MAXD=35;
const int MAXN=200005;
int dp[MAXD][MAXN];
char s[MAXN],t[MAXN];
int t1[MAXN],t2[MAXN],c[MAXN];

bool cmp(int *r,int a,int b,int l)
{
    return r[a] == r[b] && r[a+l] == r[b+l];
}
void da(int str[],int sa[],int rk[],int h[],int n,int m)
{
    n++;
    int i, j, p, *x = t1, *y = t2;
    for(i = 0; i < m; i++)c[i] = 0;
    for(i = 0; i < n; i++)c[x[i] = str[i]]++;
    for(i = 1; i < m; i++)c[i] += c[i-1];
    for(i = n-1; i >= 0; i--)sa[--c[x[i]]] = i;
    for(j = 1; j <= n; j <<= 1)
    {
        p = 0;
        for(i = n-j; i < n; i++)y[p++] = i;
        for(i = 0; i < n; i++)if(sa[i] >= j)y[p++] = sa[i] - j;
        for(i = 0; i < m; i++)c[i] = 0;
        for(i = 0; i < n; i++)c[x[y[i]]]++;
        for(i = 1; i < m; i++)c[i] += c[i-1];
        for(i = n-1; i >= 0; i--)sa[--c[x[y[i]]]] = y[i];
        swap(x,y);
        p = 1;
        x[sa[0]] = 0;
        for(i = 1; i < n; i++)
            x[sa[i]] = cmp(y,sa[i-1],sa[i],j)?p-1:p++;
        if(p >= n)break;
        m = p;
    }
    int k = 0;
    n--;
    for(i = 0; i <= n; i++)rk[sa[i]] = i;
    for(i = 0; i < n; i++)
    {
        if(k)k--;
        j = sa[rk[i]-1];
        while(str[i+k] == str[j+k])k++;
        h[rk[i]] = k;
    }
}

int str[MAXN],sa[MAXN];
int rk[MAXN],h[MAXN],mm[MAXN];
int best[20][MAXN];
void initRMQ(int n)
{
    mm[0]=-1;
    for(int i=1; i<=n; i++)
        mm[i]=mm[i-1]+((i&(i-1))==0);
    for(int i=1; i<=n; i++)best[0][i]=i;
    for(int i=1; i<=mm[n]; i++)
        for(int j=1; j+(1<<i)-1<=n; j++)
        {
            int a=best[i-1][j];
            int b=best[i-1][j+(1<<(i-1))];
            if(h[a]<h[b])best[i][j]=a;
            else best[i][j]=b;
        }
}
int askRMQ(int a,int b)
{
    int t=mm[b-a+1];
    b-=(1<<t)-1;
    a=best[t][a];
    b=best[t][b];
    return (h[a]<h[b] ? a : b);
}
int lcp(int a,int b)
{
    a=rk[a];
    b=rk[b];
    if(a>b)swap(a,b);
    return h[askRMQ(a+1,b)];
}

int main()
{
    int n,m,x,mx=0;
    scanf("%d%s",&n,s);
    s[n]=1;
    scanf("%d%s%d",&m,s+n+1,&x);
    for(int i=0;i<=n+m+1;i++)
        str[i]=s[i];
    da(str,sa,rk,h,n+m+1,128);
    initRMQ(n+m+1);
    for(int d=0;d<=x;d++)
        for(int i=0;i<=n;i++)
        {
            check_max(dp[d][i+1],dp[d][i]);
            int t=lcp(i,dp[d][i]+n+1);
            check_max(dp[d+1][i+t],dp[d][i]+t);
            check_max(mx,dp[d][i]);
        }
    return 0*printf("%s\n",(mx==m ? "YES" : "NO"));
}