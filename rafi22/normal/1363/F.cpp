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

const int N=2007;

int DP[N][N];
int Ps[N][200];
int Pt[N][200];

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
        string s,t;
        cin>>n>>s>>t;
        reverse(all(s));
        reverse(all(t));
        s='#'+s;
        t='#'+t;
        for(int i=1;i<=n;i++)
        {
            for(int j='a';j<='z';j++)
            {
                Ps[i][j]=Ps[i-1][j];
                Pt[i][j]=Pt[i-1][j];
            }
            Ps[i][s[i]]++;
            Pt[i][t[i]]++;
        }
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=n;j++) DP[i][j]=inf;
        }
        DP[0][0]=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=n;j++)
            {
                DP[i][j]=DP[i-1][j]+1;
                if(j==0) continue;
                if(s[i]==t[j]) DP[i][j]=min(DP[i][j],DP[i-1][j-1]);
                if(Ps[i][t[j]]-Pt[j-1][t[j]]>0) DP[i][j]=min(DP[i][j],DP[i][j-1]);
            }
        }
        if(DP[n][n]>=inf) cout<<-1<<endl;
        else cout<<DP[n][n]<<endl;
    }

    return 0;
}