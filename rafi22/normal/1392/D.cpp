#include <bits/stdc++.h>

#define int long long
#define double long double
#define endl '\n'
#define st first
#define nd second
#define pb push_back
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
        int n,ans=0;
        cin>>n;
        string str;
        cin>>str;
        str=str+str;
        bool one=1,b=0;
        char last=str[0];
        int act=1;
        for(int i=1;i<2*n;i++)
        {
            if(str[i]!=last)
            {
                //cout<<i<<endl;
                one=0;
                if(b)
                    ans+=act/3;
                b=1;
                act=1;
                last=str[i];
                if(i>n) break;
            }
            else act++;
        }
        if(one) ans=n/3+min((int)1,n%3);
        else ans+=act/3;
        cout<<ans<<endl;
    }

    return 0;
}