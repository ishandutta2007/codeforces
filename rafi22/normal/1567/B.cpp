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

int x[300007];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for(int i=1;i<=300000;i++) x[i]=x[i-1]^i;
    int tt;
    if(multi)
        cin>>tt;
    else tt=1;
    while(tt--)
    {
        int a,b;
        cin>>a>>b;
        if(x[a-1]==b) cout<<a<<endl;
        else
        {
            if(a==(b^x[a-1])) cout<<a+2<<endl;
            else cout<<a+1<<endl;
        }
    }

    return 0;
}