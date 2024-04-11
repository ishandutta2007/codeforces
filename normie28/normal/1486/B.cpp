#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
vector<ll> px,py;
ll n,m,i,j,k,t,t1,u,v,a,b;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    for (t1=0;t1<t;t1++)
    {
        cin>>n;
        px.clear();
        py.clear();
        for (i=1;i<=n;i++)
        {
            cin>>u>>v;
            px.push_back(u);
            py.push_back(v);
        }
        sort(px.begin(),px.end());
        sort(py.begin(),py.end());
        if (n%2) cout<<1;
        else cout<<(px[n/2]-px[n/2-1]+1)*(py[n/2]-py[n/2-1]+1);
        cout<<endl;
    }
}