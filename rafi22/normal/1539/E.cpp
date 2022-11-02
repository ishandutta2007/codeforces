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

int DP[200007][2];
int k[200007];

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
        int n,m;
        cin>>n>>m;
        set<pair<int,int>>L,R;
        L.insert({0,0});
        R.insert({0,0});
        for(int i=1;i<=n;i++)
        {
            int l1,l2,r1,r2;
            cin>>k[i]>>l1>>r1>>l2>>r2;
            if(sz(R)>0) L.insert({k[i-1],i-1});
            if(sz(L)-(sz(R)>0)>0) R.insert({k[i-1],i-1});
            while(sz(L)>0)
            {
                pair<int,int>p=*L.begin();
                if(p.st>=l1) break;
                L.erase(p);
            }
            while(sz(L)>0)
            {
                pair<int,int>p=*--L.end();
                if(p.st<=r1) break;
                L.erase(p);
            }
            while(sz(R)>0)
            {
                pair<int,int>p=*R.begin();
                if(p.st>=l2) break;
                R.erase(p);
            }
            while(sz(R)>0)
            {
                pair<int,int>p=*--R.end();
                if(p.st<=r2) break;
                R.erase(p);
            }
            if(!(l1<=k[i]&&r1>=k[i])) R.clear();
            if(!(l2<=k[i]&&r2>=k[i])) L.clear();
            DP[i][0]=-1;
            DP[i][1]=-1;
            if(sz(L)>0)
            {
                pair<int,int>p=*L.begin();
                DP[i][1]=p.nd;
            }
            if(sz(R)>0)
            {
                pair<int,int>p=*R.begin();
                DP[i][0]=p.nd;
            }
        }
        int p=n,s=-1;
        if(DP[n][0]!=-1) s=0;
        if(DP[n][1]!=-1) s=1;
        if(s==-1) cout<<"No";
        else
        {
            cout<<"Yes"<<endl;
            vector<int>ans;
            while(p>0)
            {
                for(int i=p;i>DP[p][s];i--) ans.pb(s);
                p=DP[p][s];
                s=1-s;
            }
            reverse(ans.begin(),ans.end());
            for(auto x:ans) cout<<x<<" ";
        }
    }

    return 0;
}