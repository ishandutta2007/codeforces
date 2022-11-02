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

const bool multi=1;


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
        int n;
        cin>>n;
        string s1,s2,s3,a1,a2;
        cin>>s1>>s2>>s3;
        int c1=0,c2=0,c3=0,d1,d2;
        for(auto x:s1) if(x=='1') c1++;
        for(auto x:s2) if(x=='1') c2++;
        for(auto x:s3) if(x=='1') c3++;
        bool x1=(c1>=n),x2=(c2>=n),x3=(c3>=n);
        if(x1==x2)
        {
            a1=s1;
            a2=s2;
            d1=c1;
            d2=c2;
        }
        if(x1==x3)
        {
            a1=s1;
            a2=s3;
            d1=c1;
            d2=c3;
        }
        if(x2==x3)
        {
            a1=s2;
            a2=s3;
            d1=c2;
            d2=c3;
        }
        string ans="";
        if(d1>=n)
        {
            if(d1<d2) swap(a1,a2);
            int it=0;
            for(int i=0; i<2*n; i++)
            {
                if(a2[i]=='0') ans+='0';
                else
                {
                    while(true)
                    {
                        ans+=a1[it++];
                        if(a1[it-1]=='1') break;
                    }
                }
            }
            while(it<2*n) ans+=a1[it++];
        }
        else
        {
            if(d1>d2) swap(a1,a2);
            int it=0;
            for(int i=0; i<2*n; i++)
            {
                if(a2[i]=='1') ans+='1';
                else
                {
                    while(true)
                    {
                        ans+=a1[it++];
                        if(a1[it-1]=='0') break;
                    }
                }
            }
            while(it<2*n) ans+=a1[it++];
        }
        while(sz(ans)<3*n) ans+='1';
        cout<<ans<<endl;
    }

    return 0;
}