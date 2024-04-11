#include <bits/stdc++.h>
using namespace std;

int a,b,a1,a2,a3,a4,b1,b2,b3,b4,n,m,t,m1,m2,m3,m4,ans,mm,tmp;

int main()
{
    //freopen("input.txt","r",stdin);
    ios::sync_with_stdio(0);
    cin>>n>>m>>t;
    m1=m2=m3=m4=2000000002;
    while (t--)
    {
        cin>>a>>b;
        if(a+b<m1)
        {
            m1=a+b;
            a1=a;
            b1=b;
        }
        if(a+m-b<m2)
        {
            m2=a+m-b;
            a2=a;
            b2=b;
        }
        if(n-a+b<m3)
        {
            m3=n-a+b;
            a3=a;
            b3=b;
        }
        if(n-a+m-b<m4)
        {
            m4=n-a+m-b;
            a4=a;
            b4=b;
        }
    }
    //cout<<a1<<' '<<b1<<' '<<a2<<' '<<b2<<' '<<a3<<' '<<b3<<' '<<a4<<' '<<b4<<endl;
    cin>>t;
    ans=0;
    mm=2000000002;
    for(int i=1;i<=t;i++)
    {
        cin>>a>>b;
        tmp=max(max(abs(a-a1)+abs(b-b1),abs(a-a2)+abs(b-b2)),max(abs(a-a3)+abs(b-b3),abs(a-a4)+abs(b-b4)));
        if (tmp<mm)
        {
            mm=tmp;
            ans=i;
        }
    }
    cout<<mm<<endl<<ans;
    return 0;
}