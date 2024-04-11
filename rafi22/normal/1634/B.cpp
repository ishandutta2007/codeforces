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
        int n,x,y,c;
        cin>>n>>x>>y;
        bool a=x%2,b=(x+3)%2;
        for(int i=1;i<=n;i++)
        {
            cin>>c;
            if(c%2==1)
            {
                a^=1;
                b^=1;
            }
        }
        if(a==(y%2)) cout<<"Alice"<<endl;
        else cout<<"Bob"<<endl;
    }

    return 0;
}