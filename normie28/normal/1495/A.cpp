#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
vector<ll> tx,ty;
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
        tx.clear();
        ty.clear();
        for (i=0;i<2*n;i++)
        {
            cin>>u>>v;
            if (u==0) ty.push_back(abs(v));
            else tx.push_back(abs(u));
        }
        sort(tx.begin(),tx.end());
        sort(ty.begin(),ty.end());
        ld res=0;
        for (i=0;i<n;i++)
        {
            res+=sqrt(tx[i]*tx[i]+ty[i]*ty[i]);
        }
        cout<<fixed<<setprecision(10)<<res<<endl;
    }
}