#include <bits/stdc++.h>

#define int long long
#define ll long long
#define ld long double
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
using namespace std;
double PI=3.14159265359;
int inf=1000000000000000007;
int mod=1000000007;
int mod1=998244353;

const bool multi=1;

const int N=200007;
int pot;

int x[N],p[N];
int a[6*N];
int d[6*N];
map<int,int>M;
int L[6*N],cL[6*N];
int R[6*N],cR[6*N];

int seg[(1<<22)+7][2];

int que(int v,int a,int b,int l,int r,int s)
{
    if(a<=l&&b>=r) return seg[v][s];
    if(r<a||l>b) return -inf;
    return max(que(2*v,a,b,l,(l+r)/2,s),que(2*v+1,a,b,(l+r)/2+1,r,s));
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
        int n,m;
        cin>>n>>m;
        set<int>S;
        for(int i=1;i<=n;i++)
        {
            cin>>x[i]>>p[i];
            S.insert(x[i]);
            S.insert(x[i]-1);
            S.insert(x[i]-p[i]+1);
            S.insert(x[i]-p[i]);
            S.insert(x[i]+p[i]-1);
            S.insert(x[i]+p[i]);
        }
        int it=0;
        M.clear();
        for(auto x:S)
        {
            it++;
            d[it]=x;
            M[x]=it;
        }
        for(int i=1;i<=n;i++)
        {
            L[M[x[i]-1]]+=p[i]-1-(x[i]-1);
            cL[M[x[i]-1]]++;
            L[M[x[i]-p[i]]]-=p[i]-1-(x[i]-1);
            cL[M[x[i]-p[i]]]--;
            R[M[x[i]]]+=p[i]+x[i];
            cR[M[x[i]]]++;
            R[M[x[i]+p[i]]]-=p[i]+x[i];
            cR[M[x[i]+p[i]]]--;
        }
        int sum=0,ile=0;
        for(int i=it;i>0;i--)
        {
            sum+=L[i];
            ile+=cL[i];
            a[i]+=ile*d[i]+sum;
        }
        sum=0,ile=0;
        for(int i=1;i<=it;i++)
        {
            sum+=R[i];
            ile+=cR[i];
            a[i]+=sum-ile*d[i];
        }
        int l=inf,r=-inf;
        for(int i=1;i<=it;i++)
        {
            if(a[i]>m)
            {
                if(l==inf) l=i;
                r=i;
            }
        }
        pot=1;
        while(pot<it) pot*=2;
        for(int i=1;i<=2*pot;i++)
        {
            for(int j=0;j<2;j++) seg[i][j]=-inf;
        }
        for(int i=1;i<=it;i++)
        {
            seg[i+pot-1][0]=a[i]+d[i];
            seg[i+pot-1][1]=a[i]-d[i];
        }
        for(int i=pot-1;i>0;i--)
        {
            for(int j=0;j<2;j++) seg[i][j]=max(seg[2*i][j],seg[2*i+1][j]);
        }
        for(int i=1;i<=n;i++)
        {
            bool ok=1;
            if(l<M[x[i]-p[i]+1]) ok=0;
            if(r>M[x[i]+p[i]-1]) ok=0;
            if(que(1,M[x[i]-p[i]+1],M[x[i]-1],1,pot,1)-(p[i]-1)+x[i]-1>m) ok=0;
            if(que(1,M[x[i]],M[x[i]+p[i]-1],1,pot,0)-p[i]-x[i]>m) ok=0;
            if(ok) cout<<1;
            else cout<<0;
        }
        cout<<endl;
        for(int i=1;i<=it;i++)
        {
            a[i]=0;
            L[i]=0;
            cL[i]=0;
            R[i]=0;
            cR[i]=0;
            d[i]=0;
        }
    }

    return 0;
}