#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll arr[1001],n,m,i,j,k,t,t1,u,v,a,b,fail;
int main()
{
    cin>>t;
    for (t1=0;t1<t;t1++)
    {
    cin>>n;
    a=0;
    fail=0;
    b=0;
    for (i=1;i<=n;i++)
    {
        a+=i-1;
        cin>>u;
        b+=u;
        if ((b<a)and(!fail))
        {
            cout<<"NO";
            fail=1;
        }
    }
    if (!fail)
    cout<<"YES";
    cout<<endl;
    }
}