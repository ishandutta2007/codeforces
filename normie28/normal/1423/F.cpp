
#include <bits/stdc++.h>
using namespace std;
long long n,m,i,j,k,t,t1,u,v,a,b;
int main()
{
    cin>>n>>k;
    for (i=0;i<k;i++)
    {
        cin>>u>>v;
        u--;
        a+=v;
        b+=u*v;
        b%=n;
    }
    if (a<n) cout<<1;
    else if (a>n) cout<<-1;
    else if (b==n*(n-1)/2%n) cout<<1;
    else cout<<-1;
}