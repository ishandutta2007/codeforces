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

const bool multi=0;

const int N=300007,pot=1<<19;

pair<int,int> seg[2*pot+7];
void ins(int v,int x)
{
    v+=pot-1;
    seg[v].st=x;
    while(v>1)
    {
        v/=2;
        seg[v]=min(seg[2*v],seg[2*v+1]);
    }
}
pair<int,int>que(int v,int a,int b,int l,int r)
{
    if(r<a||l>b) return {inf,0};
    if(a<=l&&b>=r) return seg[v];
    return min(que(2*v,a,b,l,(l+r)/2),que(2*v+1,a,b,(l+r)/2+1,r));
}
vector<int>V[N];
int d[N];
int b[N];
int o[N];

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
        int n,a;
        cin>>n;
        for(int i=1;i<=pot;i++) seg[i+pot-1]={inf,i};
        for(int i=pot-1;i>0;i--) seg[i]=min(seg[2*i],seg[2*i+1]);
        for(int i=1;i<=n;i++)
        {
            cin>>a;
            ins(i,i-a);
        }
        for(int i=1;i<=n;i++)
        {
            cin>>b[i];
            V[i+b[i]].pb(i);
        }
        for(int i=1;i<=n;i++) d[i]=-1;
        deque<int>Q;
        while(seg[1].st<=0)
        {
            int v=seg[1].nd;
            d[v]=1;
            Q.pb(v);
            ins(v,inf);
        }
        while(!Q.empty())
        {
            int v=Q[0];
            Q.pop_front();
            for(auto x:V[v])
            {
                while(true)
                {
                    pair<int,int>P=que(1,x,n,1,pot);
                    if(P.st>x) break;
                    int u=P.nd;
                    o[u]=x;
                    d[u]=d[v]+1;
                    Q.pb(u);
                    ins(u,inf);
                }
            }
        }
        cout<<d[n]<<endl;
        if(d[n]!=-1)
        {
            int x=n;
            while(x)
            {
                x=o[x];
                cout<<x<<" ";
                x+=b[x];
            }
        }
    }

    return 0;
}