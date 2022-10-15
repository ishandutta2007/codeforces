#include <bits/stdc++.h>
using namespace std;
long long a,b,c,p,u,v,w;
int t,t1,n,m,i,j,k;
int main()
{
    cin>>t;
    for (t1=0;t1<t;t1++)
    {
        u=9e18;
        cin>>p>>a>>b>>c;
        if (p%a==0) u=0; else if (u>a-p%a) u=a-p%a;
        if (p%b==0) u=0; else if (u>b-p%b) u=b-p%b;
        if (p%c==0) u=0; else if (u>c-p%c) u=c-p%c;
        cout<<u<<endl;
    }
}