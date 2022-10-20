#include<bits/stdc++.h>
#define ll unsigned long long
using namespace std;
const int N=100;

int T,n;
ll a[N][N],b[N],V;
struct answer
{
    ll S,a,b,c;
    void update()
    {
        S=2*(a*b+a*c+b*c);
    }
    void clean()
    {
        S=4e18,a=b=c=0;
    }
    void print()
    {
        printf("%lld %lld %lld %lld\n",S,a,b,c);
    }
}ans,now;
void dfs2(int i,ll A,ll B)
{
    if (B>sqrt(V/A)) return;
    if (i>n)
    {
        now.b=B;
        now.c=V/A/B;
        now.update();
        if (now.S<ans.S) ans=now;
        return;
    }
    for (int j=b[i];j>=0;j--)
    {
        b[i]-=j;
        dfs2(i+1,A,B*a[i][j]);
        b[i]+=j;
    }
}
void dfs1(int i,ll A)
{
    if (A>V/A/A) return;
    if (i>n)
    {
        now.a=A;
        if (2*(V/A+2*A*sqrt(V/A))<ans.S) dfs2(1,A,1);
        return;
    }
    for (int j=b[i];j>=0;j--)
    {
        b[i]-=j;
        dfs1(i+1,A*a[i][j]);
        b[i]+=j;
    }
}
void clean()
{
    ans.clean();
    V=1;
}

int main()
{
    scanf("%d",&T);
    while (T--)
    {
        clean();
        scanf("%d",&n);
        for (int i=1;i<=n;i++)
        {
            a[i][0]=1;
            scanf("%lld%lld",&a[i][1],&b[i]);
            for (int j=2;j<=b[i];j++) a[i][j]=a[i][j-1]*a[i][1];
            V*=a[i][b[i]];
        }
        dfs1(1,1);
        ans.print();
    }

    return 0;
}