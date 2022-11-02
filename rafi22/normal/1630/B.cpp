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

int a[200007];
int ile[200007];

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
        int n,k;
        cin>>n>>k;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            ile[i]=0;
        }
        for(int i=1;i<=n;i++) ile[a[i]]++;
        int j=0,cnt=0,l,r,ans=inf;
        for(int i=1;i<=n;i++)
        {
            while(j<n&&2*cnt-n<k)
            {
                j++;
                cnt+=ile[j];
            }
            if(2*cnt-n>=k)
            {
                if(j-i<ans)
                {
                    l=i;
                    r=j;
                    ans=j-i;
                }
            }
            cnt-=ile[i];
        }
        vector<pair<int,int>>res;
        cnt=0;
        int last=0;
        for(int i=1;i<=n;i++)
        {
            if(l<=a[i]&&r>=a[i]) cnt++;
            else cnt--;
            if(cnt==1)
            {
                res.pb({last+1,i});
                last=i;
                cnt=0;
            }
        }
        if(last!=n)
        {
            while(cnt<=0)
            {
                last=res.back().st;
                res.pop_back();
                cnt++;
            }
            res.pb({last,n});
        }
        if(sz(res)>k)
        {
            while(sz(res)>=k)
            {
                last=res.back().st;
                res.pop_back();
            }
            res.pb({last,n});
        }
        cout<<l<<" "<<r<<endl;
        for(auto x:res) cout<<x.st<<" "<<x.nd<<endl;
        //cout<<endl;
    }

    return 0;
}