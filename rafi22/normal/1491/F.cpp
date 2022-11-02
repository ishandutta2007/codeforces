#include <bits/stdc++.h>

#define int long long
#define double long double
//#define endl '\n'
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

int ask(vector<int>a,vector<int>b)
{
    cout<<"? "<<sz(a)<<" "<<sz(b)<<endl;
    for(auto x:a) cout<<x<<" ";
    cout<<endl;
    for(auto x:b) cout<<x<<" ";
    cout<<endl;
    int f;
    cin>>f;
    return f;
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
        int n;
        cin>>n;
        vector<int>ans;
        for(int i=2;i<=n;i++)
        {
            vector<int>a={i},b,cmp;
            for(int j=1;j<i;j++) b.pb(j);
            if(ask(a,b)!=0) cmp=a;
            if(sz(cmp)>0)
            {
                for(int j=i+1;j<=n;j++)
                {
                    b={j};
                    if(ask(cmp,b)==0) ans.pb(j);
                }
                int l=1,r=cmp[0]-1,sr;
                while(l<r)
                {
                    sr=(l+r+1)/2;
                    a.clear();
                    for(int j=sr;j<=cmp[0]-1;j++) a.pb(j);
                    if(ask(a,cmp)==0) r=sr-1;
                    else l=sr;
                }
                for(int j=1;j<=i-1;j++) if(j!=l) ans.pb(j);
                break;
            }
        }
        sort(ans.begin(),ans.end());
        cout<<"! "<<sz(ans)<<" ";
        for(auto x:ans) cout<<x<<" ";
        cout<<endl;
    }

    return 0;
}