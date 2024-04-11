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

const bool multi=0;

int DP[57][57][57*107];
struct S {int a,b;};
bool cmp(S L,S R)
{
    if(L.a==R.a) return L.b<R.b;
    else return L.a>R.a;
}
S x[57];


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
        for(int i=1;i<=n;i++) cin>>x[i].a;
        for(int i=1;i<=n;i++) cin>>x[i].b;
        sort(x+1,x+n+1,cmp);
        for(int i=0;i<=n;i++) for(int j=0;j<=n;j++) for(int l=0;l<=5000;l++) DP[i][j][l]=inf;
        DP[0][0][0]=0;
        for(int i=0;i<n;i++)
        {
            int c=i;
            for(;;c++)
            {
                for(int j=0;j<=n;j++)
                {
                    for(int l=0;l<=5000;l++)
                    {
                        //DP[i+1][j+1][l+x[i+1].b]=min(DP[i+1][j+1][l+x[i+1].b],DP[i][j][l]+x[i+1].a);
                        if(j>0) DP[c+1][j-1][l]=min(DP[c+1][j-1][l],DP[c][j][l]);
                    }
                }
                if(x[c+2].a!=x[c+1].a) break;
            }
            int d=i;
            for(;;d++)
            {
                for(int j=0;j<=n;j++)
                {
                    for(int l=0;l<=5000;l++)
                    {
                        DP[d+1][j+1][l+x[d+1].b]=min(DP[d+1][j+1][l+x[d+1].b],DP[d][j][l]+x[d+1].a);
                        //if(j>0) DP[c+1][j-1][l]=min(DP[c+1][j-1][l],DP[c][j][l]);
                    }
                }
                if(x[d+2].a!=x[d+1].a) break;
            }
            i=c;
        }
        int ans=inf;
        for(int j=0;j<=n;j++)
        {
            for(int l=1;l<=5000;l++)
            {
                if(DP[n][j][l]==inf) continue;
              //  cout<<DP[n][j][l]<<" "<<l<<endl;
                ans=min(ans,DP[n][j][l]*1000/l+min(1LL,DP[n][j][l]*1000%l));
            }
        }
        cout<<ans;
    }

    return 0;
}