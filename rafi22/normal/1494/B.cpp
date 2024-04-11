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
        int n,u,r,d,l;
        cin>>n>>u>>r>>d>>l;
        int a=0,b=0;
        if(u==n)
        {
            a++;
            b++;
        }
        if(d==n)
        {
            a++;
            b++;
        }
        bool ok=1;
        if(a>r||b>l) ok=0;
        if(u==n-1)
        {
            if(a<r) a++;
            else if(b<l) b++;
            else ok=0;
        }
        if(d==n-1)
        {
            if(a<r) a++;
            else if(b<l) b++;
            else ok=0;
        }
        a=0,b=0;
        if(r==n)
        {
            a++;
            b++;
        }
        if(l==n)
        {
            a++;
            b++;
        }
        if(a>u||b>d) ok=0;
        if(r==n-1)
        {
            if(a<u) a++;
            else if(b<d) b++;
            else ok=0;
        }
        if(l==n-1)
        {
            if(a<u) a++;
            else if(b<d) b++;
            else ok=0;
        }
        if(ok) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }

    return 0;
}