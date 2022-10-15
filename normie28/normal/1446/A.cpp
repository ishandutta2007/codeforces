#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pii pair<ll,ll>
#define fi first
#define se second
vector<pii> lis;
ll n,m,i,j,k,t,u,v,a,b;
vector<ll> res;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll aa,bb;
    cin>>aa;
    for (bb=1;bb<=aa;bb++)
    {
 //       cout<<bb<<' '<<aa<<endl;
        res.clear();
        lis.clear();
        v=0;
        u=0;
    cin>>n>>t;
 //       cout<<n<<' '<<t<<endl;
    for (i=1;i<=n;i++)
    {
        cin>>u;
        if (u<=t) {lis.push_back({i,u}); v+=u;}
    }
    sort(lis.begin(),lis.end(),[](pii a, pii b){
        return (a.se<b.se);
    });
//    cout<<v<<endl;
    if (v<(t+1)/2) cout<<-1<<endl;
    else
    {
        v=0;
        for (i=lis.size()-1;i>=0;i--)
        {
            res.push_back(lis[i].fi);
            v+=lis[i].se;
            if (v>=(t+1)/2) break;
        }
        cout<<res.size()<<endl;
        for (int g : res) cout<<g<<' ';
    }
    }
}