#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,i,j,k,t,t1,u,v,a,b;
ll arr[1000001];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for (i=0;i<(1<<n);i++)
    {
        cin>>arr[i];
        u+=arr[i];
    }
    cout<<fixed<<setprecision(9)<<(double)u/(1<<n)<<endl;
    for (i=0;i<m;i++)
    {
        cin>>a>>b;
        u-=arr[a];
        arr[a]=b;
        u+=arr[a];
        cout<<fixed<<setprecision(9)<<(double)u/(1<<n)<<endl;
    }
}