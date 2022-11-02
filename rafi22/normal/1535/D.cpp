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

int seg[(1<<19)+7];
int pos[(1<<19)+7];

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
        int k,q;
        string s1,s="";
        cin>>k>>s1>>q;
        s1="#"+s1;
        for(int j=0;j<k;j++)
        {
            string x="";
            for(int i=0;i<(1<<j);i++)
            {
                pos[sz(s1)-1]=sz(s)+(1<<j)-sz(x);
                x.pb(s1.back());
                s1.pop_back();
            }
            reverse(x.begin(),x.end());
            s=s+x;
        }
        s='#'+s;
        for(int i=1;i<=(1<<k);i++) seg[i+(1<<k)-1]=1;
        for(int i=(1<<k)-1;i>0;i--)
        {
            if(s[i]=='0') seg[i]=seg[2*i];
            if(s[i]=='1') seg[i]=seg[2*i+1];
            if(s[i]=='?') seg[i]=seg[2*i]+seg[2*i+1];
        }
        while(q--)
        {
            int p;
            char c;
            cin>>p>>c;
            int np=pos[p];
            s[np]=c;
            int i=np;
            while(i>0)
            {
                if(s[i]=='0') seg[i]=seg[2*i];
                if(s[i]=='1') seg[i]=seg[2*i+1];
                if(s[i]=='?') seg[i]=seg[2*i]+seg[2*i+1];
                i/=2;
            }
            cout<<seg[1]<<endl;
        }
    }

    return 0;
}