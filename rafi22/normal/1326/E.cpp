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

int pos[N];
int seg[2*pot+7];
int lzy[2*pot+7];

void push(int v)
{
    seg[2*v]+=lzy[v];
    seg[2*v+1]+=lzy[v];
    lzy[2*v]+=lzy[v];
    lzy[2*v+1]+=lzy[v];
    lzy[v]=0;
}

void ins(int v,int a,int b,int l,int r,int x)
{
    if(r<a||l>b) return ;
    if(a<=l&&b>=r)
    {
        seg[v]+=x;
        lzy[v]+=x;
        return ;
    }
    push(v);
    ins(2*v,a,b,l,(l+r)/2,x);
    ins(2*v+1,a,b,(l+r)/2+1,r,x);
    seg[v]=min(seg[2*v],seg[2*v+1]);
}
int que(int v,int a,int b,int l,int r)
{
    if(r<a||l>b) return inf;
    if(a<=l&&b>=r) return seg[v];
    push(v);
    return min(que(2*v,a,b,l,(l+r)/2),que(2*v+1,a,b,(l+r)/2+1,r));
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
        for(int i=1;i<=n;i++)
        {
            cin>>x;
            pos[x]=i;
        }
        int k=n;
        for(int i=1;i<=n;i++)
        {
            while(true)
            {
                ins(1,1,pos[k],1,pot,-1);
                if(seg[1]<0)
                {
                    ins(1,1,pos[k],1,pot,1);
                    break;
                }
                k--;
            }
            cout<<k<<" ";
            cin>>x;
            ins(1,1,x,1,pot,1);
        }
    }

    return 0;
}