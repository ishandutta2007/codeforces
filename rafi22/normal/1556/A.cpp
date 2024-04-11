#include <bits/stdc++.h>

#define int long long
#define ll long long
#define ld long double
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
        int c,d;
        cin>>c>>d;
        if(c%2!=d%2) cout<<-1<<endl;
        else
        {
            if(c==0&&d==0) cout<<0<<endl;
            else if(c==d) cout<<1<<endl;
            else cout<<2<<endl;
        }
    }

    return 0;
}