#include <bits/stdc++.h>

#define int long long
#define double long double
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define sz(x) (int)(x).size()
using namespace std;
double PI=3.14159265359;
int inf=1000000000000000007;
int mod=1000000007;
int mod1=998244353;

const bool multi=0;


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tt;
    if(multi)
        cin>>tt;
    else tt=1;
    while(tt--)
    {
        int n1,n2,n3,s1=0,s2=0,s3=0,m1=inf,m2=inf,m3=inf,a,ans=-inf;
        cin>>n1>>n2>>n3;
        for(int i=1;i<=n1;i++)
        {
            cin>>a;
            s1+=a;
            m1=min(m1,a);
        }
        for(int i=1;i<=n2;i++)
        {
            cin>>a;
            s2+=a;
            m2=min(m2,a);
        }
        for(int i=1;i<=n3;i++)
        {
            cin>>a;
            s3+=a;
            m3=min(m3,a);
        }
        ans=max(ans,s1+s2-s3);
        ans=max(ans,s1-s2+s3);
        ans=max(ans,-s1+s2+s3);
        ans=max(ans,s1+s2+s3-2*m1-2*m2);
        ans=max(ans,s1+s2+s3-2*m1-2*m3);
        ans=max(ans,s1+s2+s3-2*m2-2*m3);
        cout<<ans<<endl;
    }

    return 0;
}