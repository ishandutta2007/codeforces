#include <bits/stdc++.h>

#define int long long
#define double long double
#define endl '\n'
#define st first
#define nd second
#define pb push_back
using namespace std;
double PI=3.14159265359;
int inf=1000000000000000007;
int mod=1000000007;
int mod1=998244353;

const bool multi=1;

int m,n;
int a[100007];
int b[100007];
int pref[100007];
int pos[100007];

int cnt(int i,int sr)
{
    if(sr>=m||sr>=n) return 0;
    int act=pref[sr];
    if(pos[i]<=sr) act+=pref[sr+1]-pref[sr];
    else act+=a[i];
    return act+(m-sr-1)*b[i];
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
        int ans=0;
        cin>>m>>n;
        for(int i=1;i<=n;i++) cin>>a[i]>>b[i];
        vector<pair<int,int>>temp;
        for(int i=1;i<=n;i++)
        {
            temp.pb({a[i],i});
        }
        sort(temp.begin(),temp.end(),greater<pair<int,int>>());
        for(int i=0;i<n;i++)
        {
            pref[i+1]=pref[i]+temp[i].st;
            pos[temp[i].nd]=i+1;
        }
        for(int i=1;i<=n;i++)
        {
            int l=0,p=min(m-1,n-1),sr;
            while(l<=p)
            {
                sr=(l+p)/2;
                if(cnt(i,sr)>cnt(i,sr+1))
                {
                    p=sr-1;
                    ans=max(ans,cnt(i,sr));
                }
                else
                {
                    l=sr+1;
                    ans=max(ans,cnt(i,sr+1));
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}