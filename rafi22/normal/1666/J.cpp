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

const int N=207;

ll DP[N][N];
int zkad[N][N];
ll c[N][N];
int ans[N];

void rek(int l,int r,int p)
{
    if(r<l) return ;
    ans[zkad[l][r]]=p;
    rek(l,zkad[l][r]-1,zkad[l][r]);
    rek(zkad[l][r]+1,r,zkad[l][r]);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>c[i][j];
            c[i][j]+=c[i-1][j]+c[i][j-1]-c[i-1][j-1];
        }
    }
    for(int d=1;d<=n;d++)
    {
        for(int l=1;l+d-1<=n;l++)
        {
            int r=l+d-1;
            DP[l][r]=infl;
            for(int k=l;k<=r;k++)
            {
                ll act=DP[l][k-1]+DP[k+1][r];
                if(act<DP[l][r])
                {
                    DP[l][r]=act;
                    zkad[l][r]=k;
                }
            }
            DP[l][r]+=c[r][n]-c[l-1][n]-c[r][r]+c[l-1][r]+c[r][l-1]-c[l-1][l-1];
        }
    }
    rek(1,n,0);
    for(int i=1;i<=n;i++) cout<<ans[i]<<" ";



    return 0;
}