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

const int N=500007;
int pot;

int P[N];
int seg[2*(1<<20)+7];
int id[N];
int DP[N];

int que(int v,int a,int b,int l,int r)
{
    if(a<=l&&b>=r) return seg[v];
    if(r<a||l>b) return -inf;
    return max(que(2*v,a,b,l,(l+r)/2),que(2*v+1,a,b,(l+r)/2+1,r));
}
void ins(int v,int x)
{
    v+=pot-1;
    seg[v]=x;
    while(v>1)
    {
        v/=2;
        seg[v]=max(seg[2*v],seg[2*v+1]);
    }
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
        int n,x;
        cin>>n;
        pot=1;
        while(pot<n+1) pot*=2;
        vector<pair<int,int>>V;
        V.pb({0,0});
        for(int i=1;i<=n;i++)
        {
            cin>>x;
            P[i]=P[i-1]+x;
            V.pb({P[i],i});
        }
        sort(all(V));
        for(int i=0;i<n+1;i++) id[V[i].nd]=i+1;
        for(int i=1;i<=2*pot;i++) seg[i]=-inf;
        for(int i=1;i<=n;i++)
        {
            ins(id[i-1],DP[i-1]-i+1);
            DP[i]=DP[i-1]-(P[i-1]>P[i]);
            int l=1,r=n+1,sr,x=0;
            while(l<=r)
            {
                sr=(l+r)/2;
                if(V[sr-1].st<P[i])
                {
                    x=sr;
                    l=sr+1;
                }
                else r=sr-1;
            }
            DP[i]=max(DP[i],que(1,1,x,1,pot)+i);
        }
        cout<<DP[n]<<endl;
    }

    return 0;
}