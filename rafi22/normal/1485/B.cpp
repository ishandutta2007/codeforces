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

int a[100007];
int pref[100007];

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
        int n,q,k;
        cin>>n>>q>>k;
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=2;i<=n;i++) pref[i]=pref[i-1]+a[i]-a[i-1]-1;
        while(q--)
        {
            int l,r;
            cin>>l>>r;
            cout<<2*(pref[r]-pref[l])+k-a[r]+a[l]-1<<endl;
        }
    }

    return 0;
}