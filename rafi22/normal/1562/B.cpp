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

int cnt[10];

int num(string s)
{
    int xd=1,c=0;
    for(int i=sz(s)-1;i>=0;i--)
    {
        c+=(s[i]-'0')*xd;
        xd*=10;
    }
    return c;
}

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
        memset(cnt,0,sizeof cnt);
        int n;
        string s;
        cin>>n>>s;
        int ans=-1;
        for(auto x:s)
        {
            if(x!='2'&&x!='3'&&x!='5'&&x!='7') ans=x-'0';
            cnt[x-'0']++;
        }
        if(ans!=-1)
        {
            cout<<1<<endl<<ans<<endl;
            continue;
        }
        for(int i=1;i<10;i++) if(cnt[i]>1) ans=11*i;
        if(ans!=-1)
        {
            cout<<2<<endl<<ans<<endl;
            continue;
        }
        int aaa=inf;
        for(int m=1;m<1<<n;m++)
        {
            string xd="";
            for(int j=0;j<n;j++) if((m&(1<<j))) xd+=s[j];
            int k=num(xd);
            for(int i=2;i<=sqrt(k);i++)
            {
                if(k%i==0&&sz(xd)<aaa)
                {
                    aaa=sz(xd);
                    ans=k;
                }
            }
        }
        cout<<aaa<<endl<<ans<<endl;
    }

    return 0;
}