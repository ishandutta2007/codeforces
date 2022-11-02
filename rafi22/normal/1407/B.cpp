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

int a[1007];
bool is[1007];


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
        sort(a+1,a+1+n);
        cout<<a[n]<<" ";
        for(int i=1;i<=n;i++) is[i]=0;
        int g=a[n];
        is[n]=1;
        for(int j=1;j<=n-1;j++)
        {
            int mx=0,nr=0;
            for(int i=1;i<=n;i++)
            {
                if(!is[i]&&__gcd(g,a[i])>mx)
                {
                    mx=__gcd(g,a[i]);
                    nr=i;
                }
            }
            cout<<a[nr]<<" ";
            is[nr]=1;
            g=__gcd(g,a[nr]);
        }
        cout<<endl;
    }

    return 0;
}