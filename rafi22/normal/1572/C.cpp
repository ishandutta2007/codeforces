#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define ll long long
ll mod=1000000007;
int inf=1000000007;
ll infl=1000000000000000007;

const int N=3007;

int DP[N][N];
int a[N];
int p[N];
vector<int>V[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=1; i<=n; i++)
        {
            cin>>a[i];
            p[i]=sz(V[a[i]]);
            V[a[i]].pb(i);
        }
        for(int k=1; k<n; k++)
        {
            for(int l=1; l<n; l++)
            {
                int r=l+k;
                if(r>n) break;
                DP[l][r]=max(DP[l+1][r],DP[l][r-1]);
                if(a[l]==a[r]) DP[l][r]=max(DP[l][r],DP[l+1][r-1]+1);
                for(int i=p[l]+1; i<sz(V[a[l]]); i++)
                {
                    int j=V[a[l]][i];
                    if(j>=r) break;
                    DP[l][r]=max(DP[l][r],(a[l]==a[r])+DP[l][j]+DP[j+1][r]);
                }
              /*  for(int i=p[r]-1; i>=0; i--)
                {
                    int j=V[a[r]][i];
                    if(j<=l) break;
                    DP[l][r]=max(DP[l][r],(a[l]==a[r])+DP[l][j]+DP[j+1][r]);
                }*/
            }
        }
        cout<<n-1-DP[1][n]<<endl;
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=n;j++) DP[i][j]=0;
            V[i].clear();
        }
    }

    return 0;
}