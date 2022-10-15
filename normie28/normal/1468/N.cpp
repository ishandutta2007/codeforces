#include <bits/stdc++.h>
using namespace std;
long long c1,c2,c3,a1,a2,a3,a4,a5,t,t1;
int main()
{
    cin>>t;
    for (t1=0;t1<t;t1++)
    {
        cin>>c1>>c2>>c3>>a1>>a2>>a3>>a4>>a5;
        c1-=a1;
        c2-=a2;
        c3-=a3;
        if ((c1<0)or(c2<0)or(c3<0)) 
        {
            cout<<"No\n";
            continue;
        }
        a4-=min(a4,c1);
        a5-=min(a5,c2);
        c3-=a4;
        c3-=a5;
        if (c3<0)
        cout<<"No\n";
        else cout<<"Yes\n";
    }
}