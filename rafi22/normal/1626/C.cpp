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

int h[107];
int k[107];
int DP[107];

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
        for(int i=1;i<=n;i++) DP[i]=inf;
        for(int i=1;i<=n;i++) cin>>k[i];
        for(int i=1;i<=n;i++) cin>>h[i];
        for(int i=1;i<=n;i++)
        {
            for(int j=i-1;j>=0;j--)
            {
                int start=k[j+1];
                for(int l=j+1;l<=i;l++) start=min(start,k[l]-h[l]+1);
                if(start>k[j]) DP[i]=min(DP[i],DP[j]+(k[i]-start+1)*(k[i]-start+2)/2);
            }
           // cout<<DP[i]<<" ";
        }
       // cout<<endl;
       cout<<DP[n]<<endl;
    }

    return 0;
}