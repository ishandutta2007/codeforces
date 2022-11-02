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

int p[100007];
int cnt[100007];
int res[100007];

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
        string s;
        cin>>s;
        s='#'+s;
        p[0]=-1;
        int c=-1;
        for(int i=1;i<sz(s);i++)
        {
            while(c>=0&&s[c+1]!=s[i]) c=p[c];
            p[i]=++c;
        }
        for(int i=1;i<sz(s);i++) cnt[i]=1;
        for(int i=sz(s)-2;i>0;i--)
        {
            res[p[i]]+=cnt[i];
            cnt[p[i]]+=cnt[i];
        }
        vector<pair<int,int>>ans;
        ans.pb({sz(s)-1,1});
        c=sz(s)-1;
        while(c>0)
        {
            if(p[c]>0) ans.pb({p[c],2+res[p[c]]});
            c=p[c];
        }
        reverse(ans.begin(),ans.end());
        cout<<sz(ans)<<endl;
        for(auto x:ans) cout<<x.st<<" "<<x.nd<<endl;
    }

    return 0;
}