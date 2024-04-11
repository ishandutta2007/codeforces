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

int ile[500007];
bool DP[500007];

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
        int n,k,d;
        cin>>n>>k>>d;
        vector<int>a(n+1);
        for(int i=0;i<n;i++) cin>>a[i];
        a[n]=inf;
        sort(all(a));
        DP[0]=1;
        int act=0;
        for(int i=1;i<=n;i++)
        {
            if(DP[i-1])
            {
                int p=upper_bound(all(a),a[i-1]+d)-a.begin()+1;
                //cout<<p<<endl;
                if(p>=i+k-1)
                {
                    ile[i+k-1]++;
                    ile[p]--;
                    //cout<<i+k-1<<" "<<p-1<<endl;
                }
            }
            act+=ile[i];
            if(act) DP[i]=1;
        }
        if(DP[n]) cout<<"YES";
        else cout<<"NO";
    }

    return 0;
}