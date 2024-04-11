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

int a[200007];
int seg[1000007],pot=1;
int ans[200007];
vector<pair<int,int>>Q[200007];
int del[200007];

int kth(int v,int k)
{
    if(v>=pot) return v-pot+1;
    if(seg[2*v]>=k) return kth(2*v,k);
    else return kth(2*v+1,k-seg[2*v]);
}

void ins(int v)
{
    v+=pot-1;
    seg[v]=0;
    while(v>1)
    {
        v/=2;
        seg[v]=seg[2*v]+seg[2*v+1];
    }
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
        int n,m;
        cin>>n;
        vector<pair<int,int>>vec;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            vec.pb({-a[i],i});
        }
        sort(vec.begin(),vec.end());
        for(int i=0;i<sz(vec);i++) del[i+1]=vec[i].nd;
        cin>>m;
        for(int i=1;i<=m;i++)
        {
            int k,p;
            cin>>k>>p;
            Q[k].pb({p,i});
        }
        while(pot<n) pot*=2;
        for(int i=1;i<=n;i++) seg[i+pot-1]=1;
        for(int i=pot-1;i>0;i--) seg[i]=seg[2*i]+seg[2*i+1];
        for(int i=n;i>0;i--)
        {
            for(auto x:Q[i]) ans[x.nd]=kth(1,x.st);
            ins(del[i]);
        }
        for(int i=1;i<=m;i++) cout<<a[ans[i]]<<endl;
    }

    return 0;
}