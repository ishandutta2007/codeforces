#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,i,j,k,t,t1,u;
    int a=0;
    cin>>t;
    for (t1=0;t1<t;t1++)
    {
        cin>>n;
        a=0;
        for (i=1;i<=n;i++) {cin>>u; if (u!=2) a++;}
        cout<<a<<endl;
    }
}