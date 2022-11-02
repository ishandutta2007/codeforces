#include <bits/stdc++.h>

#define int long long
#define double long double
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define sz(x) (int)(x).size()
using namespace std;
double PI=3.14159265359;
int inf=1000000000000000007;
int mod=1000000007;
int mod1=998244353;

const bool multi=0;

int ile[56];

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
        int n,t;
        cin>>n>>t>>s;
        t-=(1LL<<(s[n-1]-'a'));
        t+=(1LL<<(s[n-2]-'a'));
        int sum=0;
        for(int i=0;i<n-2;i++)
        {
            ile[s[i]-'a'+1]++;
            sum+=(1LL<<(s[i]-'a'));
        }
        if(sum<t) cout<<"No";
        else
        {
            sum-=t;
            bool ok=1;
            for(int i=0;i<55;i++)
            {
                if((sum&(1LL<<i))) ile[i]--;
                if(ile[i]<0) ok=0;
                ile[i+1]+=ile[i]/2;
            }
            if(ok) cout<<"Yes";
            else cout<<"No";
        }
    }

    return 0;
}