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

int tab[10007];

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
        int n,sum=0;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>tab[i];
            sum+=tab[i];
        }
        if(sum%n!=0)
        {
            cout<<-1<<endl;
            continue;
        }
        vector<pair<pair<int,int>,int> > ans;
        for(int i=2;i<=n;i++)
        {
            if(tab[i]%i!=0)
            {
                if(tab[1]<i-tab[i]%i) return 2137;
                ans.pb({{1,i},i-tab[i]%i});
                tab[1]-=i-tab[i]%i;
                tab[i]+=i-tab[i]%i;
            }
            ans.pb({{i,1},tab[i]/i});
            tab[1]+=tab[i];
            tab[i]=0;
        }
        for(int i=2;i<=n;i++) ans.pb({{1,i},sum/n});
        cout<<ans.size()<<endl;
        for(int i=0;i<ans.size();i++)
        {
            cout<<ans[i].st.st<<" "<<ans[i].st.nd<<" "<<ans[i].nd<<endl;
        }
    }
    return 0;
}