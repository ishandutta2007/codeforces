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

int pot1[1000007];
int pot2[1000007];
int H1[1000007];
int H2[1000007];

inline bool cmp(int i,int j,int k,int l) { return ((H1[j]-H1[i-1]+mod)%mod*pot1[k-i]%mod==(H1[l]-H1[k-1]+mod)%mod)&&((H2[j]-H2[i-1]+mod)%mod*pot2[k-i]%mod==(H2[l]-H2[k-1]+mod)%mod); }

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
        string s,t;
        cin>>s>>t;
        t='#'+t;
        int c0=0,c1=0;
        for(auto x:s)
        {
            if(x=='1') c1++;
            else c0++;
        }
        if(c1>c0)
        {
            swap(c0,c1);
            for(int i=0;i<sz(s);i++)
            {
                if(s[i]=='1') s[i]='0';
                else s[i]='1';
            }
        }
        pot1[0]=1;
        pot2[0]=1;
        for(int i=1;i<sz(t);i++)
        {
            pot1[i]=pot1[i-1]*131%mod;
            pot2[i]=pot2[i-1]*137%mod;
            H1[i]=(H1[i-1]+t[i]*pot1[i])%mod;
            H2[i]=(H2[i-1]+t[i]*pot2[i])%mod;
        }
        int ans=0;
        for(int i=1;i<sz(t);i++)
        {
            if(i*c0>=sz(t)-1) break;
            if((sz(t)-1-i*c0)%c1==0)
            {
                int it=1,i0=-1,j0=-1,i1=-1,j1=-1;
                bool ok=1;
                for(int j=0;j<sz(s);j++)
                {
                    if(s[j]=='0')
                    {
                        if(i0==-1)
                        {
                            i0=it;
                            j0=it+i-1;
                        }
                        else ok&=cmp(i0,j0,it,it+i-1);
                        it+=i;
                    }
                    else
                    {
                        if(i1==-1)
                        {
                            i1=it;
                            j1=it+(sz(t)-1-i*c0)/c1-1;
                        }
                        else ok&=cmp(i1,j1,it,it+(sz(t)-1-i*c0)/c1-1);
                        it+=(sz(t)-1-i*c0)/c1;
                    }
                    if(i==(sz(t)-1-i*c0)/c1&&i0!=-1&&i1!=-1)
                    {
                        if(i0<i1) ok&=!cmp(i0,j0,i1,j1);
                        else ok&=!cmp(i1,j1,i0,j0);
                    }
                }
                ans+=ok;
            }
        }
        cout<<ans;
    }

    return 0;
}