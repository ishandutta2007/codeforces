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
int inf=1000000000000000007;
int mod=1000000007;
int mod1=998244353;

const bool multi=0;


int seg[530007][10][10];
int lazy[530007][10][10];
int pos[10];
char seg1[600007];
int t[600007];
int pot=1;
int n,m,k;

void push(int i,int j,int v,int sz)
{
    if(lazy[v][i][j]!=-1)
    {
        seg[2*v][i][j]=lazy[v][i][j]*sz/2;
        lazy[2*v][i][j]=lazy[v][i][j];
        seg[2*v+1][i][j]=lazy[v][i][j]*sz/2;
        lazy[2*v+1][i][j]=lazy[v][i][j];
    }
    lazy[v][i][j]=-1;
}

void insS(int u,int a,int b,int l,int r,int v)
{
    if(a<=l&&b>=r)
    {
        for(int i=0;i<k;i++)
        {
            for(int j=0;j<k;j++)
            {
                lazy[u][i][j]=v;
                seg[u][i][j]=(r-l+1)*v;
            }
        }
        return ;
    }
    if(l>b||r<a) return;
    for(int i=0;i<k;i++)
    {
        for(int j=0;j<k;j++)
        {
            push(i,j,u,r-l+1);
        }
    }
    insS(2*u,a,b,l,(l+r)/2,v);
    insS(2*u+1,a,b,(l+r)/2+1,r,v);
    for(int i=0;i<k;i++)
    {
        for(int j=0;j<k;j++)
        {
            seg[u][i][j]=seg[2*u][i][j]+seg[2*u+1][i][j];
        }
    }
}
void insP(int i,int j,int u,int a,int b,int l,int r,int v)
{
    if(a<=l&&b>=r)
    {
        lazy[u][i][j]=v;
        seg[u][i][j]=(r-l+1)*v;
        return ;
    }
    if(l>b||r<a) return;
    push(i,j,u,r-l+1);
    insP(i,j,2*u,a,b,l,(l+r)/2,v);
    insP(i,j,2*u+1,a,b,(l+r)/2+1,r,v);
    seg[u][i][j]=seg[2*u][i][j]+seg[2*u+1][i][j];
}
void init(int i,int j,int a)
{
    a+=pot-1;
    seg[a][i][j]=1;
    while(a>1)
    {
        a/=2;
        seg[a][i][j]=seg[2*a][i][j]+seg[2*a+1][i][j];
    }
}

void change(int v,int a,int b,int l,int r,char a1,int a2)
{
    if(a<=l&&b>=r)
    {
        t[v]=a2;
        seg1[v]=a1;
        return ;
    }
    if(l>b||r<a) return;
    change(2*v,a,b,l,(l+r)/2,a1,a2);
    change(2*v+1,a,b,(l+r)/2+1,r,a1,a2);
}
char getL(int p)
{
    p+=pot-1;
    int mx=0;
    char val='x';
    while(p>0)
    {
        if(t[p]>mx)
        {
            mx=t[p];
            val=seg1[p];
        }
        p/=2;
    }
    return val;
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

        cin>>n>>m>>k;
        string s;
        cin>>s;
        while(pot<n) pot*=2;
        for(int i=1;i<=n;i++)
        {
            seg1[i+pot-1]=s[i-1];
            t[i+pot-1]=1;
        }
        memset(lazy,-1,sizeof lazy);
        for(int i=1; i<n; i++) init(s[i-1]-'a',s[i]-'a',i);
        for(int ii=2;ii<=m+1;ii++)
        {
            int x;
            cin>>x;
            if(x==1)
            {
                int l,r;
                char c;
                cin>>l>>r>>c;
                if(l!=1) insP(getL(l-1)-'a',getL(l)-'a',1,l-1,l-1,1,pot,0);
                if(r!=n) insP(getL(r)-'a',getL(r+1)-'a',1,r,r,1,pot,0);
                change(1,l,r,1,pot,c,ii);
                if(l!=1) insP(getL(l-1)-'a',getL(l)-'a',1,l-1,l-1,1,pot,1);
                if(r!=n) insP(getL(r)-'a',getL(r+1)-'a',1,r,r,1,pot,1);
                insS(1,l,r-1,1,pot,0);
                insP(c-'a',c-'a',1,l,r-1,1,pot,1);
            }
            else
            {
                string w;
                cin>>w;
                for(int i=0;i<k;i++) pos[w[i]-'a']=i;
                int ans=0;
                for(int i=0; i<k; i++)
                {
                    for(int j=0; j<k; j++)
                    {
                        if(pos[j]<=pos[i]) ans+=seg[1][i][j];
                    }
                }
                cout<<++ans<<endl;
            }
        }


    }

    return 0;
}