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

vector<int>P;

int DP[40007][500];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for(int i=1;i<=40000;i++)
    {
        int x=i;
        vector<int>V;
        while(x>0)
        {
            V.pb(x%10);
            x/=10;
        }
        vector<int>V1=V;
        reverse(all(V1));
        if(V==V1)
        {
            P.pb(i);
        }
    }
    for(int j=0;j<sz(P);j++) DP[0][j]=1;
    for(int i=1;i<=40000;i++)
    {
        for(int j=0;j<sz(P);j++)
        {
            if(j>0) DP[i][j]=DP[i][j-1];
            if(i>=P[j]) DP[i][j]=(DP[i][j]+DP[i-P[j]][j])%mod;
        }
    }
    int tt;
    if(multi)
        cin>>tt;
    else tt=1;
    while(tt--)
    {
        int n;
        cin>>n;
        cout<<DP[n][sz(P)-1]<<endl;
    }

    return 0;
}