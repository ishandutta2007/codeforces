#include <bits/stdc++.h>

#define int long long
#define double long double
#define endl '\n'
#define st first
#define nd second
#define pb push_back
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
        int m,d,w;
        cin>>m>>d>>w;
        int x=w/__gcd(d-1,w),mini=min(m,d);
        int ile=mini/x;
        cout<<(2*(mini-x)-x*(ile-1))*ile/2<<endl;

    }

    return 0;
}