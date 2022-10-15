#include <bits/stdc++.h>
using namespace std;
int n,m,i,j,k,t,t1,u,v,a,b;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for (i=1;i<=n;i++) 
    {
    for (j=1;j<=m;j++) 
    {
        cin>>u;
        if ((i+j)%2) cout<<720720;
        else cout<<720720+u*u*u*u;
        cout<<' ';
    }
    cout<<endl;
    }
}