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
        int N=n;
        vector<int>d;
        int s=sqrt(n);
        for(int i=2;i<=s;i++)
        {
            if(n%i!=0) continue;
            d.pb(i);
            while(n%i==0) n/=i;
        }
        if(n>1) d.pb(n);
        if(sz(d)>1||N==1) cout<<1;
        else cout<<d[0];
    }

    return 0;
}