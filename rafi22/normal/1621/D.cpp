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

int c[507][507];

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
        for(int i=1;i<=2*n;i++) for(int j=1;j<=2*n;j++) cin>>c[i][j];
        int sum=0,s1=0,s2=0,s3=0,s4=0;
        for(int i=n+1;i<=2*n;i++) for(int j=n+1;j<=2*n;j++) sum+=c[i][j];
        cout<<sum+min({c[n+1][n],c[n][n+1],c[n][2*n],c[2*n][n],c[1][n+1],c[n+1][1],c[2*n][1],c[1][2*n]})<<endl;
    }

    return 0;
}