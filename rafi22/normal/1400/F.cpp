#include <bits/stdc++.h>
#pragma GCC target ("avx2,fma")
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")

//#define int long long
#define ll long long
#define ld long double
//#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
using namespace std;
double PI=3.14159265359;
int inf=1000000007;
int mod=1000000007;
int mod1=998244353;

const bool multi=0;

int trie[100007][10];
int kon[100007];
int it,it1;
vector<int>X[10007];

int DP[1007][10007];

int id(vector<int>V)
{
    if(sz(V)==0) return 0;
    int p=0;
    for(int i=0;i<sz(V);i++)
    {
        if(trie[p][V[i]]==0) trie[p][V[i]]=++it;
        p=trie[p][V[i]];
    }
    if(kon[p]==0) kon[p]=++it1;
    X[kon[p]]=V;
    return kon[p];
}

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
        string s;
        int k;
        cin>>s>>k;
        int n=sz(s);
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<10000;j++)
            {
                DP[i][j]=inf;
            }
        }
        DP[0][0]=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<=it;j++)
            {
                DP[i+1][j]=min(DP[i+1][j],DP[i][j]+1);
                vector<int>V=X[j];
                V.pb(s[i]-'0');
                bool ok=1;
                int s=0;
                int t=-1;
                for(int j=sz(V)-1;j>=0;j--)
                {
                    s+=V[j];
                    if(s!=k&&k%s==0)
                    {
                        t=j;
                        break;
                    }
                    if(s==k) ok=0;
                }
                if(ok)
                {
                    vector<int>V1;
                    s=0;
                    for(int j=sz(V)-1; j>=max(0,t+1); j--)
                    {
                        s+=V[j];
                        if(s>=k||V[j]==1) break;
                        V1.pb(V[j]);
                    }
                    reverse(all(V1));
                    int c=id(V1);
                    DP[i+1][c]=min(DP[i+1][c],DP[i][j]);
                }
            }
        }
        int ans=inf;
        for(int j=0;j<=it;j++) ans=min(ans,DP[n][j]);
        cout<<ans;
    }

    return 0;
}