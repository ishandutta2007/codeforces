#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
int n,m,p[1000005],F[1005][1005],kt[1005],a[1000000],top,bot,check[100000];
char c[1005][1005];
void turbo()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}
void inputt()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            cin>>c[i][j];
        }
 
    cin>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>p[i];
    }
}
void push(int x)
{
    top++;
    a[top]=x;
}
void BFS(int u)
{
    for(int i=1;i<=n;i++)
    {
        kt[i]=0;
        F[u][i]=1e9;
    }
    top=0; bot=1;
    push(u);
    F[u][u]=0;
    while(bot<=top)
    {
        for(int i=1;i<=n;i++)
        {
            if(c[a[bot]][i]=='1' && F[u][i]>F[u][a[bot]]+1)
            {
                F[u][i]=F[u][a[bot]]+1;
                push(i);
            }
        }
        bot++;
    }
}
void solve()
{
    for(int i=1;i<=n;i++)
    {
        BFS(i);
    }
    int j=m;
    while(0==0)
    {
        if(j==2) break;
        int t3=p[j-2],t2=p[j-1],t1=p[j];
        if(F[t3][t2]+F[t2][t1]>F[t3][t1])
        {
            j--;
        }
        else
        {
            p[j-1]=p[j];
            p[j]=-1;
            j--;
        }
    }
    int res=0;
    for(int i=1;i<=m;i++) if(p[i]!=-1) res++;
    cout<<res<<endl;
    for(int i=1;i<=m;i++) if(p[i]!=-1) cout<<p[i]<<" ";
}
int main()
{
    turbo();
    inputt();
    solve();
}