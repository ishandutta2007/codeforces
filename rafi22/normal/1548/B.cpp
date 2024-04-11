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

const bool multi=1;

int a[200007];
int seg[4*200007],pot=1;

int que(int v,int a,int b,int l,int r)
{
    if(r<a||l>b) return 0;
    if(a<=l&&b>=r) return seg[v];
    int X=que(2*v,a,b,l,(l+r)/2),Y=que(2*v+1,a,b,(l+r)/2+1,r);
    if(X==0) return Y;
    if(Y==0) return X;
    return __gcd(X,Y);
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
        int n,ans=0;
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i];
        while(pot<n) pot*=2;
        for(int i=1;i<n;i++) seg[i+pot-1]=abs(a[i+1]-a[i]);
        for(int i=n;i<=pot;i++) seg[i+pot-1]=0;
        for(int i=pot-1;i>0;i--)
        {
            if(seg[2*i+1]==0) seg[i]=seg[2*i];
            else if(seg[2*i]==0) seg[i]=seg[2*i+1];
            else seg[i]=__gcd(seg[2*i],seg[2*i+1]);
        }
        int kon=0;
        for(int i=1;i<n;i++)
        {
            kon=max(kon,i-1);
            while(kon<n-1&&que(1,i,kon+1,1,pot)>1) kon++;
           // cout<<i<<" "<<kon<<endl;
            ans=max(ans,kon-i+1);
        }
        cout<<ans+1<<endl;
    }

    return 0;
}