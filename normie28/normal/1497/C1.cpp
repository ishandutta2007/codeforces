#include <bits/stdc++.h>
using namespace std;
long long n,m,i,j,k,t,t1,u,v,a,b;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    for (t1=0;t1<t;t1++)
    {
        cin>>n>>k;
        k-=2;
        a=n/2;
        b=n%2;
        while(b+2<=k)
        {
            a--;
            b+=2;
        }
        for (i=1;i<=b;i++) cout<<1<<' ';
        if (b==k) cout<<a<<' '<<a<<' ';
        else if (a%2) cout<<a-1<<' '<<a-1<<' '<<2;
        else cout<<a<<' '<<a/2<<' '<<a/2;
        cout<<endl;
    }
}