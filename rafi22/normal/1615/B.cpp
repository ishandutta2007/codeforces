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

int P[20][200007];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for(int j=0;j<18;j++)
    {
        for(int i=1;i<=200000;i++) P[j][i]=P[j][i-1]+!((i&(1<<j))>0);
    }
    int tt;
    if(multi)
        cin>>tt;
    else tt=1;
    while(tt--)
    {
        int l,r;
        cin>>l>>r;
        int ans=inf;
        for(int j=0;j<18;j++) ans=min(ans,P[j][r]-P[j][l-1]);
        cout<<ans<<endl;
    }

    return 0;
}