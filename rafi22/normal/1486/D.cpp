#include <bits/stdc++.h>

#define int long long
#define double long double
//#define endl '\n'
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

int a[200007];
int seg[1200007],pot=1;

void ins(int u,int v)
{
    u+=pot-1;
    seg[u]=min(seg[u],v);
    while(u>1)
    {
        u/=2;
        seg[u]=min(seg[2*u],seg[2*u+1]);
    }
}
int que(int v,int a,int b,int l,int r)
{
    if(a<=l&&b>=r) return seg[v];
    if(b<l||a>r) return inf;
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
        int n,k;
        cin>>n>>k;
        for(int i=1;i<=n;i++) cin>>a[i];
        while(pot<2*n+1) pot*=2;
        int l=1,r=n,sr,ans;
        while(l<=r)
        {
            for(int i=1;i<2*pot;i++) seg[i]=inf;
            sr=(l+r)/2;
            int balance=0;
            bool ok=0;
            ins(n+1,0);
            for(int i=1;i<=n;i++)
            {
                if(a[i]>=sr) balance++;
                else balance--;
               // cout<<sr<<" "<<balance<<endl;
                if(i-que(1,1,balance+n,1,pot)>=k)
                {
                    ok=1;
                    break;
                }
                ins(balance+n+1,i);
            }
            if(ok)
            {
                ans=sr;
                l=sr+1;
            }
            else r=sr-1;
        }
        cout<<ans<<endl;
    }
    return 0;
}