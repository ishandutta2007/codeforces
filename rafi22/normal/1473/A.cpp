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

int a[100007];

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
        bool b=1;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            if(a[i]>k) b=0;
        }
        sort(a+1,a+n+1);
        if(b||a[1]+a[2]<=k) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }

    return 0;
}