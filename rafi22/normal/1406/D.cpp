#include <bits/stdc++.h>

#define int long long
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

int seg[400007],pot=1;

void add(int v,int a,int b,int l,int r,int x)
{
    if(a<=l&&b>=r)
    {
        seg[v]+=x;
        return;
    }
    if(l>b||r<a) return ;
    add(2*v,a,b,l,(l+r)/2,x);
    add(2*v+1,a,b,(l+r)/2+1,r,x);
}
int get(int v)
{
    v+=pot-1;
    int val=0;
    while(v>0)
    {
        val+=seg[v];
        v/=2;
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
        int n,sum=0,ans;
        cin>>n;
        while(pot<n+1) pot*=2;
        for(int i=2;i<=n+1;i++) cin>>seg[i+pot-1];
        for(int i=2;i<=n+1;i++) sum+=max(0LL,seg[i+pot-1]-seg[i+pot-2]);
        ans=sum-max(0LL,-get(2));
        if(ans>0) cout<<ans/2+ans%2<<endl;
        else cout<<ans/2<<endl;
        int q;
        cin>>q;
        while(q--)
        {
            int l,r,x;
            cin>>l>>r>>x;
            l++,r++;
            sum-=max(0LL,get(l)-get(l-1));
            if(r!=n+1) sum-=max(0LL,get(r+1)-get(r));
            add(1,l,r,1,pot,x);
            sum+=max(0LL,get(l)-get(l-1));
            if(r!=n+1) sum+=max(0LL,get(r+1)-get(r));
            ans=sum-max(0LL,-get(2));
            if(ans>0) cout<<ans/2+ans%2<<endl;
            else cout<<ans/2<<endl;
        }
    }

    return 0;
}