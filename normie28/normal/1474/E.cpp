#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
ll n,m,i,j,k,t,t1,u,v,a,b;
vector<ll> lis;
vector<pair<ll,ll>> br;
ll res[100001];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    for (t1=0;t1<t;t1++)
    {
        cin>>n;
        lis.clear();
        br.clear();
        lis.push_back(n);
        for (i=0;i<(n-2)/2;i++)
        {
            br.push_back({n,i+2});
            lis.push_back(i+2);
        }
        lis.push_back(1);
        for (i=0;i<(n-2)-(n-2)/2;i++)
        {
            br.push_back({1,n-i-1});
            lis.push_back(n-i-1);
        }
        br.push_back({1,n});
        for (i=0;i<n;i++) res[lis[i]]=lis[(i+1)%n];
        a=0;
        for (auto g : br) a+=(g.se-g.fi)*(g.se-g.fi);
        cout<<a<<endl;
        for (i=1;i<=n;i++) cout<<res[i]<<' ';
        cout<<endl<<n-1<<endl;
        for (auto g : br) 
        {
            cout<<g.se<<' '<<g.fi<<endl;
        }
    }
}