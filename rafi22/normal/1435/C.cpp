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

const bool multi=0;

int val[7];
int tab[100007];
vector<int> all;
vector<pair<int,int> > change;

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
        for(int i=1;i<=6;i++) cin>>val[i];
        sort(val+1,val+7,greater<int>());
        int n;
        cin>>n;
        for(int i=1;i<=n;i++) cin>>tab[i];
        int gr=inf;
        for(int i=1;i<=n;i++)
        {
            int last=1,mx=0;
            for(int j=1;j<=6;j++)
            {
                change.pb({last,tab[i]-val[j]});
                mx=max(mx,tab[i]-val[j]);
                all.pb(tab[i]-val[j]);
                last=tab[i]-val[j]+1;
            }
            gr=min(gr,mx);
        }
        sort(all.begin(),all.end());
        sort(change.begin(),change.end());
        int maxi=0,ans=inf,it=0;
        for(int i=0;i<all.size();i++)
        {
            if(all[i]>gr) break;
            while(it<change.size()&&change[it].st<=all[i])
            {
                maxi=max(maxi,change[it].nd);
                it++;
            }
            ans=min(ans,maxi-all[i]);
        }
        cout<<ans;
    }

    return 0;
}