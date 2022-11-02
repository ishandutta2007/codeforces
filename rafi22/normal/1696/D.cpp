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

const int  N=250007;

int seg[4*N][2];
int pot;

void ins(int v,int x,int s)
{
    v+=pot-1;
    seg[v][s]=x;
    while(v>1)
    {
        v/=2;
        seg[v][s]=min(seg[2*v][s],seg[2*v+1][s]);
    }
}
int que(int v,int a,int b,int l,int r,int s)
{
    if(a<=l&&b>=r) return seg[v][s];
    if(r<a||l>b) return inf;
    return min(que(2*v,a,b,l,(l+r)/2,s),que(2*v+1,a,b,(l+r)/2+1,r,s));
}

int a[N],d[N];

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
        int n;
        cin>>n;
        pot=1;
        while(pot<n) pot*=2;
        for(int i=1;i<=2*pot;i++)
        {
            seg[i][0]=inf;
            seg[i][1]=inf;
        }
        vector<pair<int,int>>Qmn;
        vector<pair<int,int>>Qmx;
        Qmn.pb({0,0});
        Qmx.pb({inf,0});
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            d[i]=inf;
            if(i==1) d[i]=0;
            int x,y;
            while(Qmn.back().st>a[i])
            {
                ins(Qmn.back().nd,inf,0);
                Qmn.pop_back();
            }
            x=Qmn.back().nd+1;
            Qmn.pb({a[i],i});
            while(Qmx.back().st<a[i])
            {
                ins(Qmx.back().nd,inf,1);
                Qmx.pop_back();
            }
            y=Qmx.back().nd+1;
            Qmx.pb({a[i],i});
            d[i]=min(d[i],que(1,y,i-1,1,pot,0)+1);
            d[i]=min(d[i],que(1,x,i-1,1,pot,1)+1);
            ins(i,d[i],0);
            ins(i,d[i],1);
        }
        cout<<d[n]<<endl;
    }

    return 0;
}