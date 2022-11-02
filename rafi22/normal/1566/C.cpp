#include <bits/stdc++.h>

#define int long long
#define ll long long
#define ld long double
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

int a[100007];

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
        string s,t;
        cin>>s>>t;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='1'&&t[i]=='0') a[i]=2;
            if(s[i]=='0'&&t[i]=='1') a[i]=2;
            if(s[i]=='0'&&t[i]=='0') a[i]=1;
            if(s[i]=='1'&&t[i]=='1') a[i]=0;
        }
        a[n]=2;
        bool is[2]={0,0};
        for(int i=0;i<n;i++)
        {
            //cout<<a[i]<<" ";
            if(a[i]==2)
            {
                is[0]=0;
                is[1]=0;
                ans+=2;
            }
            if(a[i]==0)
            {
                is[1]=1;
                if(is[0])
                {
                    ans+=2;
                    is[0]=0;
                    is[1]=0;
                }
            }
            if(a[i]==1)
            {
                is[0]=1;
                if(is[1])
                {
                    ans+=2;
                    is[0]=0;
                    is[1]=0;
                }
                else if(a[i+1]!=0)
                {
                    ans++;
                    is[0]=0;
                    is[1]=0;
                }
            }
        }
       // cout<<endl;
        cout<<ans<<endl;
    }

    return 0;
}