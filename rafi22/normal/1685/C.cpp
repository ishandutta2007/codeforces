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

const bool multi=1;

int b[200007];

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
        string s;
        cin>>s;
        s='#'+s;
        n*=2;
        int mx=-inf,p=0;
        int l=inf,r=-inf;
        for(int i=1;i<=n;i++)
        {
            b[i]=b[i-1];
            if(s[i]=='(') b[i]++;
            else b[i]--;
            if(b[i]<0)
            {
                if(l==inf) l=i;
                r=i;
            }
            if(b[i]>mx)
            {
                mx=b[i];
                p=i;
            }
        }
        if(l==inf)
        {
            cout<<0<<endl;
            continue;
        }
        int mxl=-inf,L,mxr=-inf,R;
        for(int i=0;i<l;i++)
        {
            if(b[i]>mxl)
            {
                mxl=b[i];
                L=i+1;
            }
        }
        for(int i=r+1;i<=n;i++)
        {
            if(b[i]>mxr)
            {
                mxr=b[i];
                R=i;
            }
        }
        if(mxl+mxr>=mx)
        {
            cout<<1<<endl;
            cout<<L<<" "<<R<<endl;
        }
        else
        {
            cout<<2<<endl;
            cout<<1<<" "<<p<<endl;
            cout<<p+1<<" "<<n<<endl;
        }
    }

    return 0;
}