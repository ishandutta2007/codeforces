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

int DP[200007][2];
bool tab[200007];

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
        vector <int> vec;
        int n;
        cin>>n;
        for(int i=1;i<=n;i++) cin>>tab[i];
        for(int i=0;i<=n;i++)
        {
            DP[i][0]=inf;
            DP[i][1]=inf;
        }
        DP[1][1]=tab[1];
        DP[2][1]=tab[1]+tab[2];
        for(int i=1;i<=n;i++)
        {
            DP[i+2][1]=min(DP[i+2][1],DP[i][0]+tab[i+1]+tab[i+2]);
            DP[i+1][1]=min(DP[i+1][1],DP[i][0]+tab[i+1]);
            DP[i+1][0]=min(DP[i+1][0],DP[i][1]);
            DP[i+2][0]=min(DP[i+2][0],DP[i][1]);
        }
        cout<<min(DP[n][0],DP[n][1])<<endl;
    }

    return 0;
}