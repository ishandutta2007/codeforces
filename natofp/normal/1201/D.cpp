#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int n,m,k,q;
const int nax=2e5+5;
vector<bool> czyok(nax,false);
vector<int> skarby[nax];
int pre[nax];
int nex[nax];
int up[nax];

long long int KAPPA(long long int a)
{
    if(a>=0) return a;
    return -1LL*a;
}

unordered_map<long long int,long long int> a;

long long int zamien(long long int r,long long int c)
{
    long long int inf=1e9+5;
    long long int res=inf*r+c;
    return res;
}

long long int solve(long long int r,long long int c)
{
    if(r<1 || r>n || c<1 || c>m) return 2e15;
    long long int akt=zamien(r,c);
    if(a[akt]!=0) return a[akt];
    if(up[r]==-1)
    {
        int f,l;
        f=skarby[r][0];
        l=skarby[r].back();
        int res=0;
        int res2=0;
        res+=abs(c-f);
        res+=(abs(l-f));
        res2+=abs(c-l);
        res2+=abs(l-f);
        a[akt]=min(res,res2);
        return a[akt];
    }
    // 1 opcja ZACZYNAMY OD LEWEGO
    long long int res=0;
    long long int f,l;
    f=skarby[r][0];
    l=skarby[r].back();
    res=abs(c-f);
    res+=abs(l-f);
    res+=up[r]-r;
    long long int w1,w2;
    w1=solve(up[r],nex[l]);
    w2=solve(up[r],pre[l]);
    res+=min(w1+abs(nex[l]-l),w2+abs(pre[l]-l));
    a[akt]=res;
    // 2 opcja YACYZNAMZ OD PRAWEJ
    res=abs(c-l);
    res+=abs(l-f);
    res+=up[r]-r;
    w1=solve(up[r],nex[f]);
    w2=solve(up[r],pre[f]);
    res+=min(w1+abs(nex[f]-f),w2+abs(pre[f]-f));
    a[akt]=min(a[akt],res);
    return a[akt];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m>>k>>q;
    for(int i=0;i<k;i++)
    {
        int r,c; cin>>r>>c;
        skarby[r].push_back(c);
    }
    for(int i=0;i<nax;i++) sort(skarby[i].begin(),skarby[i].end());
    while(q--)
    {
        int x; cin>>x;
        czyok[x]=true;
    }
    pre[0]=0;
    pre[1]=0;
    for(int i=1;i<=m;i++)
    {
        if(czyok[i]==true)
        {
            pre[i]=i;
            nex[i]=i;
        }
        else
        {
            pre[i]=pre[i-1];
        }
    }
    nex[m]=0;
    nex[m+1]=0;
    for(int i=m;i>=1;i--)
    {
        if(czyok[i]==true)
        {
            pre[i]=i;
            nex[i]=i;
        }
        else
        {
            nex[i]=nex[i+1];
        }
    }
    int last=-1;
    for(int i=n;i>=1;i--)
    {
        up[i]=last;
        if(skarby[i].size()>0) last=i;
    }
    if(skarby[1].size()>0)
    {
        cout<<solve(1,1);
    }
    else
    {
        int xd=nex[1];
        long long int ile=xd-1;
        ile+=up[1]-1;
        cout<<ile+solve(up[1],xd);
    }
    return 0;
}