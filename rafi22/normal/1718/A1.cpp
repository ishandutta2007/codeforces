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

const int N=100007;

int a[N];
int DP[N];
map<int,int>last;

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
        last.clear();
        last[0]=1;
        int p=0;
        for(int i=1;i<=n;i++)
        {
            DP[i]=DP[i-1]+1;
            p^=a[i];
            int x=last[p]-1;
            if(x>=0)
            {
                DP[i]=min(DP[i],DP[x]+i-x-1);
            }
            last[p]=i+1;
        }
        cout<<DP[n]<<endl;
    }

    return 0;
}