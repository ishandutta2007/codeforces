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

const bool multi=0;

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
        int l=1,r=10*mod,sr,ans=0;
        while(l<=r)
        {
            sr=(l+r)/2;
            int k=sr,c=sr/2;
            k-=c/2+c%2;
            if(sr>=1) k--;
            if(sr>=4) k--;
           // cout<<sr<<" "<<k<<endl;
            if(k>=n)
            {
                ans=sr;
                r=sr-1;
            }
            else l=sr+1;
        }
        cout<<ans;
    }

    return 0;
}