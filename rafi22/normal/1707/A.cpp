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
        int n,q;
        cin>>n>>q;
        for(int i=1;i<=n;i++) cin>>a[i];
        int l=1,r=n,sr,res=n+1;
        while(l<=r)
        {
            sr=(l+r)/2;
            int Q=q;
            bool ok=1;
            for(int i=sr;i<=n;i++)
            {
                if(Q==0) ok=0;
                if(a[i]>Q) Q--;
            }
            if(ok)
            {
                res=sr;
                r=sr-1;
            }
            else l=sr+1;
        }
        for(int i=1;i<=res-1;i++)
        {
            if(a[i]<=q) cout<<1;
            else cout<<0;
        }
        for(int i=res;i<=n;i++) cout<<1;
        cout<<endl;
    }

    return 0;
}