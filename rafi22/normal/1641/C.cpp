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

const int pot=1<<18;

int seg[2*pot+7];

void upd(int v,int x)
{
    v+=pot-1;
    seg[v]=min(seg[v],x);
    while(v>1)
    {
        v/=2;
        seg[v]=min(seg[2*v],seg[2*v+1]);
    }
}
int que(int v,int a,int b,int l,int r)
{
    if(r<a||l>b) return inf;
    if(a<=l&&b>=r) return seg[v];
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
        int n,q;
        cin>>n>>q;
        set<int>alive;
        for(int i=0;i<=n+1;i++) alive.insert(i);
        for(int i=1;i<=2*pot;i++) seg[i]=inf;
        while(q--)
        {
            int t,l,r,x;
            cin>>t;
            if(t==0)
            {
                cin>>l>>r>>x;
                if(x==0)
                {
                    while(true)
                    {
                        int p=*alive.lower_bound(l);
                        if(p>r) break;
                        alive.erase(p);
                    }
                }
                else upd(l,r);
            }
            else
            {
                cin>>x;
                if(!alive.count(x)) cout<<"NO"<<endl;
                else
                {
                    int p=(*--alive.lower_bound(x))+1;
                    int k=(*alive.upper_bound(x))-1;
                    if(que(1,p,k,1,pot)<=k) cout<<"YES"<<endl;
                    else cout<<"N/A"<<endl;
                }
            }
        }
    }

    return 0;
}