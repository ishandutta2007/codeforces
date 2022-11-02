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

vector<int>ans[3000007];

void gg()
{
    cout<<-1;
    exit(0);
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
        int n,tot=0,cnt=0,k;
        cin>>n>>k;
        string s;
        cin>>s;
        s='#'+s;
        for(int i=n;i>0;i--)
        {
            if(s[i]=='R')
            {
            	cnt++;
            	tot+=sz(s)-cnt-i;
            }
        }
        if(tot<k) gg();
        int it=-1;
        for(int i=1;i<=k;i++)
        {
            if(tot==k-i+1)
            {
                it=i;
                break;
            }
            for(int j=1;j<n;j++)
            {
                if(s[j]=='R'&&s[j+1]!=s[j])
                {
                    if(tot-1>=k-i)
                    {
                        ans[i].pb(j);
                        swap(s[j],s[j+1]);
                        j++;
                        tot--;
                    }
                }
            }
        }
        if(it!=-1)
        {
            for(int i=n-1;i>0;i--)
            {
                int j=i;
                while(j<n&&s[j]=='R'&&s[j+1]!=s[j])
                {
                    if(it>k) gg();
                    ans[it++].pb(j);
                    swap(s[j],s[j+1]);
                    j++;
                }
            }
        }
        else if(tot) gg();
        for(int i=1;i<=k;i++)
        {
            cout<<sz(ans[i])<<" ";
            for(auto x:ans[i]) cout<<x<<" ";
            cout<<endl;
        }
    }

    return 0;
}