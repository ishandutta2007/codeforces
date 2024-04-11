#include<bits/stdc++.h>
using namespace std;

const int N=3e5+1e3+7,M=32,P=1e9+7;

int n,q;

map<int,vector<long long> >mp;

struct BIT{
    long long c[N];

    void add(int x,long long v)
    {
        while(x<=n)
        {
            c[x]+=v;
            x+=x&-x;
        }
    }

    long long qry(int x)
    {
        long long ret=0;
        while(x)
        {
            ret+=c[x];
            x-=x&-x;
        }
        return ret;
    }
}T[M];

int a[N];

mt19937 rng(1313);

void add(int x,int v,int m)
{
    if(!mp.count(v))
    {
        mp[v]={};
        mp[v].resize(M);
        for(int i=0;i<M;i++)
            mp[v][i]=rng();
    }
    auto d=mp[v];
    for(int i=0;i<M;i++)
        T[i].add(x,m*d[i]);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++)
        cin>>a[i],add(i,a[i],1);
    while(q--)
    {
        int op;
        cin>>op;
        if(op==1)
        {
            int x,y;
            cin>>x>>y;
            add(x,a[x],-1);
            a[x]=y;
            add(x,a[x],1);
        }
        else
        {
            int l,r,k;
            cin>>l>>r>>k;
            bool ans=1;
            for(int i=0;i<M;i++)
                ans&=((T[i].qry(r)-T[i].qry(l-1))%k==0);
            cout<<(ans?"YES":"NO")<<"\n";
        }
    }
}