#include <bits/stdc++.h>

//#define int long long
#define double long double
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define sz(x) (int)(x).size()
using namespace std;
double PI=3.14159265359;
int inf=1100000007;
int mod=1000000007;
int mod1=998244353;

const bool multi=0;

int a[35007];
int DP[35007][107];
int last[35007];
int seg[65536*2+7][100],lazy[65536*2+7][100],pot=1;

void push(int v,int t)
{
    seg[2*v][t]+=lazy[v][t];
    seg[2*v+1][t]+=lazy[v][t];
    lazy[2*v][t]+=lazy[v][t];
    lazy[2*v+1][t]+=lazy[v][t];
    lazy[v][t]=0;
}
void ins(int v,int t,int a,int b,int l,int r,int x)
{
    if(r<a||l>b) return;
    if(a<=l&&b>=r)
    {
        seg[v][t]+=x;
        lazy[v][t]+=x;
        return ;
    }
    push(v,t);
    ins(2*v,t,a,b,l,(l+r)/2,x);
    ins(2*v+1,t,a,b,(l+r)/2+1,r,x);
    seg[v][t]=min(seg[2*v][t],seg[2*v+1][t]);
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tt;
    if(multi)
        cin>>tt;
    else tt=1;
    while(tt--)
    {
        int n,k;
        cin>>n>>k;
        for(int i=1;i<=n;i++) cin>>a[i];
        while(pot<n+1) pot*=2;
        for(int j=0;j<k;j++)
        {
            for(int i=0;i<=2*pot;i++) seg[i][j]=inf;
        }
        ins(1,0,1,1,1,pot,-inf);
        for(int i=1;i<=n;i++)
        {
            if(last[a[i]])
            {
                for(int j=0;j<k;j++) ins(1,j,1,last[a[i]],1,pot,i-last[a[i]]);
            }
            last[a[i]]=i;
            for(int j=1;j<=k;j++)
            {
                DP[i][j]=seg[1][j-1];
                if(j!=k) ins(1,j,i+1,i+1,1,pot,-inf+DP[i][j]);
            }
        }
        cout<<DP[n][k];
    }

    return 0;
}