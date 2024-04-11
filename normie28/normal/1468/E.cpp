#include <bits/stdc++.h>
using namespace std;
long long t,t1,a,b,c,d,res;
int main()
{
    cin>>t;
    for (t1=0;t1<t;t1++)
    {
        cin>>a>>b>>c>>d;
        res=0;
        res=max(res,min(a,b)*min(c,d));
        res=max(res,min(a,c)*min(b,d));
        res=max(res,min(a,d)*min(c,b));
        cout<<res<<endl;
    }
}