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

char ans[57][57];

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
        for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) ans[i][j]='.';
        if(k>n/2+n%2)
        {
            cout<<-1<<endl;
            continue;
        }
        for(int i=1;i<=k;i++) ans[2*i-1][2*i-1]='R';
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++) cout<<ans[i][j];
            cout<<endl;
        }
    }

    return 0;
}