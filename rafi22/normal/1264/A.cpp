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

int a[500007];

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
        int n,g=inf,s=inf,b=inf;
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=2;i<=n;i++)
        {
            if(a[i]!=a[i-1])
            {
                g=i-1;
                break;
            }
        }
        for(int i=g+2;i<=n;i++)
        {
            if(a[i]!=a[i-1]&&i-1-g>g)
            {
                s=i-1;
                break;
            }
        }
        for(int i=n/2+1;i>s+1;i--)
        {
            if(a[i]!=a[i-1]&&i-1-s>g)
            {
                b=i-1;
                break;
            }
        }
       // cout<<g<<" "<<s<<endl;
        s-=g;
        b-=s+g;
        if(g+s+b>n/2) cout<<0<<" "<<0<<" "<<0<<endl;
        else cout<<g<<" "<<s<<" "<<b<<endl;
    }

    return 0;
}