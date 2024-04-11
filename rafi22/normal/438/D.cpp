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

pair<int,int> mx[4*100007];
int sum[4*100007];
int a[100007];
int pot=1<<17;

void upd(int v,int x)
{
    a[v]=x;
    v+=pot-1;
    mx[v].st=x;
    sum[v]=x;
    while(v>1)
    {
        v/=2;
        sum[v]=sum[2*v]+sum[2*v+1];
        mx[v]=max(mx[2*v],mx[2*v+1]);
    }
}
int get_sum(int v,int a,int b,int l,int r)
{
    if(r<a||l>b) return 0;
    if(a<=l&&r<=b) return sum[v];
    return get_sum(2*v,a,b,l,(l+r)/2)+get_sum(2*v+1,a,b,(l+r)/2+1,r);
}
pair<int,int> get_max(int v,int a,int b,int l,int r)
{
    if(r<a||l>b) return {-inf,0};
    if(a<=l&&r<=b) return mx[v];
    return max(get_max(2*v,a,b,l,(l+r)/2),get_max(2*v+1,a,b,(l+r)/2+1,r));
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
        int n,m,x;
        cin>>n>>m;
        for(int i=1;i<=n;i++)
        {
            mx[i+pot-1].nd=i;
            cin>>x;
            upd(i,x);
        }
        while(m--)
        {
            int t,l,r,x;
            cin>>t;
            if(t==1)
            {
                cin>>l>>r;
                cout<<get_sum(1,l,r,1,pot)<<endl;
            }
            if(t==2)
            {
                cin>>l>>r>>x;
                while(true)
                {
                    pair<int,int>p=get_max(1,l,r,1,pot);
                    //cout<<p.st<<" "<<p.nd<<endl;
                    if(p.st<x) break;
                    upd(p.nd,a[p.nd]%x);
                }
            }
            if(t==3)
            {
                cin>>l>>x;
                upd(l,x);
            }
        }
    }

    return 0;
}