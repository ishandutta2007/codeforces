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

int DP[15][2][2];
int ile[20];

int c(int x)
{
    if(x==-1) return 0;
    return ile[x];
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for(int i=0;i<10;i++) for(int j=0;j<10;j++) ile[i+j]++;
    int tt;
    if(multi)
        cin>>tt;
    else tt=1;
    while(tt--)
    {
        memset(DP,0,sizeof DP);
        int n;
        cin>>n;
        int i=0;
        DP[0][0][0]=1;
        while(n)
        {
            int k=n%10;
            n/=10;
            i++;
            DP[i][0][0]=c(k)*DP[i-1][0][0]+c(k-1)*DP[i-1][0][1];
            DP[i][0][1]=c(k)*DP[i-1][1][0]+c(k-1)*DP[i-1][1][1];
            DP[i][1][0]=c(k+10)*DP[i-1][0][0]+c(k+9)*DP[i-1][0][1];
            DP[i][1][1]=c(k+10)*DP[i-1][1][0]+c(k+9)*DP[i-1][1][1];
        }
        cout<<DP[i][0][0]-2<<endl;
    }

    return 0;
}