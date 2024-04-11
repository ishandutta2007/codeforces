#include <bits/stdc++.h>

#define int long long
#define ll long long
#define ld long double
//#define endl '\n'
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
vector<pair<pair<int,int>,int>>ans;
vector<int>V[1007];

void rek(int l,int r)
{
   // cout<<l<<" "<<r<<endl;
    if(l>r) return ;
    int x;
    if(sz(V[l])>0)
    {
        x=V[l].back()+1;
        V[l].pop_back();
        if(x+1<=r) V[x+1].pop_back();
    }
    else
    {
        x=l;
        V[l+1].pop_back();
    }
    ans.pb({{l,r},x});
    rek(l,x-1);
    rek(x+1,r);
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
        int n,l,r;
        cin>>n;
        for(int i=1;i<=n;i++) V[i].clear();
        for(int i=1;i<=n;i++)
        {
            cin>>l>>r;
            V[l].pb(r);
        }
        for(int i=1;i<=n;i++) sort(all(V[i]));
        ans.clear();
        V[1].pop_back();
        rek(1,n);
        for(int i=0;i<n;i++) cout<<ans[i].st.st<<" "<<ans[i].st.nd<<" "<<ans[i].nd<<endl;
        cout<<endl;
    }

    return 0;
}