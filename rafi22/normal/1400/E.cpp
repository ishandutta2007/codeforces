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
int a[5007];
int licz(int l,int r,int v)
{
    if(r<l) return 0;
    //cout<<l<<" "<<r<<endl;
    int mn=inf,p,cnt=0;
    for(int i=l;i<=r;i++)
    {
        if(a[i]<mn)
        {
            p=i;
            mn=a[i];
        }
        if(a[i]-v>0) cnt++;
    }
    return min(cnt,mn-v+licz(l,p-1,mn)+licz(p+1,r,mn));
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
        int n;
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i];
        cout<<licz(1,n,0)<<endl;
    }
    return 0;
}