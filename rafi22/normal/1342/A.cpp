#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        long long x,y,a,b;
        cin>>x>>y>>a>>b;
        cout<<min((x+y)*a,(max(x,y)-min(x,y))*a+min(x,y)*b)<<endl;
    }
   /* int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        long long a,b,q;
        cin>>a>>b>>q;
        for(int j=0;j<q;j++)
        {
            long long r,l;
            cin>>l>>r;
            cout<<max((long long)0,r-max(a,b)+1)-max((long long)0,l-max(a,b)+1)<<" ";
        }
        cout<<endl;
    }*/
    return 0;
}