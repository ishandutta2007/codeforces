#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int n,m,q;
const int nax=5e5+5;
int a[nax];
long long int p[nax];
long long int k;
vector<pair<int,int> > xd;
int ans[nax];
const int roz=(1<<21);

int tree[roz];

long long int ile(int l,int r)
{
    if(l==0) return p[r];
    return p[r]-p[l-1];
}

void add(int pos,int val)
{
    pos+=roz/2;
    while(pos>=1)
    {
        tree[pos]++;
        pos/=2;
    }
}

bool czy(long long int x)
{
    //czy pefix[0....x] BEDZIE ROWNY;
    long long int naj=xd[x].first;
    naj*=(x+1);
    naj-=ile(0,x);
    if(naj>=k) return false;
    return true;
}

int kty(int z)
{
    int pos=1;
    while(1)
    {
        if(pos>=roz/2) return pos-roz/2;
        if(tree[pos*2]<z)
        {
            z-=tree[pos*2];
            pos=pos*2+1;
        }
        else
        {
            pos*=2;
        }

    }
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    memset(tree,0,sizeof tree);
    cin>>n>>m>>q;
    memset(a,0,sizeof a);
    memset(p,0,sizeof p);
    for(int i=1;i<=n;i++)
    {
        int x; cin>>x;
        a[x]++;
    }
    for(int i=1;i<=m;i++)
    {
        xd.push_back({a[i],i});
    }
    sort(xd.begin(),xd.end());
    p[0]=xd[0].first;
    for(int i=1;i<m;i++)
    {
        p[i]=p[i-1]+xd[i].first;
    }
    vector<pair<long long int,int> > zap;
    for(int i=0;i<q;i++)
    {
        long long int x; cin>>x;
        zap.push_back({x,i});
    }
    sort(zap.begin(),zap.end());
    int wsk=-1;
    for(int i=0;i<q;i++)
    {
        k=zap[i].first;
        k-=n;
        long long int lo,hi;
        lo=0;
        hi=m-1;
        while(lo+1<hi)
        {
            long long int mid=(lo+hi)/2;
            if(czy(mid)) lo=mid;
            else hi=mid;
        }
        long long int res;
        if(czy(hi)) res=hi;
        else res=lo;
        //cout<<res<<endl;
        // prefix[0...res] jest ROWNY;
        long long kappa=xd[res].first;
        kappa*=(res+1);
        kappa-=ile(0,res);
        k-=kappa;
        long long int idx=(k%(res+1));
        if(idx==0) idx+=res+1;
        while(wsk+1<=res)
        {
            wsk++;
            add(xd[wsk].second,1);
        }
        ans[zap[i].second]=kty(idx);
    }
    for(int i=0;i<q;i++) cout<<ans[i]<<"\n";
    return 0;
}