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

int a[200007];
int b[200007];
map<int,bool>is;

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
        is.clear();
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<=m;i++) cin>>b[i];
        vector<int>a1,a2;
        vector<int>b1,b2;
        for(int i=1;i<=n;i++)
        {
            if(a[i]<0) a2.pb(-a[i]);
            else a1.pb(a[i]);
        }
        set<pair<int,int>> pos;
        int cnt=1;
        for(int i=1;i<=m;i++)
        {
            if(b[i]<0) b2.pb(-b[i]);
            else b1.pb(b[i]);
            is[b[i]]=1;
            if(b[i]>0)
            {
                pos.insert({b[i],cnt++});
            }
        }
        pos.insert({inf,cnt});
        pos.insert({-inf,0});
        int xd=0;
         for(auto x:a1) if(is[x]) xd++;
        int ans=xd;
        int it=0,act=0;
        for(int i=0;i<sz(b1);i++)
        {
            while(it<sz(a1)&&a1[it]<=b1[i]+act-1)
            {
                act++;
                if(is[a1[it]]) xd--;
                it++;
            }
           // cout<<b1[i]<<" "<<b1[i]+act-1<<endl;
            pair<int,int>p1=*--(pos.lower_bound({b1[i],0}));
            pair<int,int>p2=*--(pos.lower_bound({b1[i]+act,0}));
           // cout<<p1.nd<<" "<<p2.nd<<endl;
            ans=max(ans,xd+p2.nd-p1.nd);
        }
        is.clear();
        pos.clear();
        cnt=1;
        for(int i=m;i>0;i--)
        {
            if(b[i]<0) pos.insert({-b[i],cnt++});
            is[-b[i]]=1;
        }
        pos.insert({inf,cnt});
        pos.insert({-inf,0});
        reverse(a2.begin(),a2.end());
        reverse(b2.begin(),b2.end());
        xd=0;
        for(auto x:a2) if(is[x]) xd++;
        int ans1=xd;
        it=0,act=0;
        for(int i=0;i<sz(b2);i++)
        {
           // cout<<a2[it]<<endl;
            while(it<sz(a2)&&a2[it]<=b2[i]+act-1)
            {
                act++;
                if(is[a2[it]]) xd--;
                it++;
               //cout<<a2[it]<<endl;
            }
           // cout<<xd<<endl;
            //cout<<b2[i]<<" "<<b2[i]+act<<endl;
            pair<int,int>p1=*--(pos.lower_bound({b2[i],0}));
            pair<int,int>p2=*--(pos.lower_bound({b2[i]+act,0}));
           // cout<<p1.nd<<" "<<p2.nd<<endl;
            ans1=max(ans1,xd+p2.nd-p1.nd);
        }
        cout<<ans1+ans<<endl;

    }

    return 0;
}