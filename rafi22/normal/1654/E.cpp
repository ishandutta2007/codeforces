#include <bits/stdc++.h>
#pragma GCC target ("avx2,fma")
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")

//#define int long long
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

int a[100007];
int DP[507][200007];
vector<int>V[100007];
int ile[50000007];

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
        for(int i=1;i<=n;i++) cin>>a[i];
        if(n==1)
        {
            cout<<0;
            return 0;
        }
        int ans=2;
        for(int i=1;i<=n;i++)
        {
            if(i-507>0)
            {
                for(auto x:V[i-507]) DP[i%507][x+100000]=0;
            }
            for(int j=i-1;j>0;j--)
            {
                if((i-j)*200>100007) break;
                if((a[i]-a[j])%(i-j)!=0) continue;
                int x=(a[i]-a[j])/(i-j);
                V[i].pb(x);
                DP[i%507][x+100000]=max(DP[i%507][x+100000],DP[j%507][x+100000]+1);
                ans=max(ans,DP[i%507][x+100000]+1);
            }
        }
        for(int x=-200;x<=200;x++)
        {
            for(int i=1;i<=n;i++)
            {
                ile[a[i]-x*i+200*100002]++;
                ans=max(ans,ile[a[i]-x*i+200*100002]);
            }
            for(int i=1;i<=n;i++) ile[a[i]-x*i+200*100002]--;
        }
        cout<<n-ans;
    }

    return 0;
}