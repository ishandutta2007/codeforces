#include <bits/stdc++.h>

#define int long long
#define double long double
//#define endl '\n'
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

int d[2007];
set<pair<int,int>>ans;

int n;

void ask(int v)
{
    cout<<"? "<<v<<endl;
    for(int i=1;i<=n;i++) cin>>d[i];
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
        cin>>n;
        ask(1);
        int c[2]={0,0};
        for(int i=1;i<=n;i++)
        {
            if(d[i]==1) ans.insert({1,i});
            if(d[i]>0) c[d[i]%2]++;
        }
        vector<int>V;
        if(c[0]<=c[1])
        {
            for(int i=1;i<=n;i++)
            {
                if(d[i]>0&&d[i]%2==0) V.pb(i);
            }
        }
        else
        {
            for(int i=1;i<=n;i++)
            {
                if(d[i]>0&&d[i]%2==1) V.pb(i);
            }
        }
        for(auto v:V)
        {
            ask(v);
            for(int i=1;i<=n;i++) if(d[i]==1) ans.insert({min(v,i),max(v,i)});
        }
        cout<<"!"<<endl;
        for(auto x:ans) cout<<x.st<<" "<<x.nd<<endl;
    }

    return 0;
}