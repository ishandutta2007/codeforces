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

const bool multi=0;

struct V
{
    int ile,p,k,maxP,maxS,s;
};

V seg[4*200007];
int pot=1;

V Merge(V L,V R)
{
    if(L.ile==0) return R;
    if(R.ile==0) return L;
    int x=L.maxP;
    if(L.maxP==L.s&&L.k<=R.p) x+=R.maxP;
    int y=R.maxS;
    if(R.maxS==R.s&&L.k<=R.p) y+=L.maxS;
    int ne=0;
    if(L.k<=R.p) ne=L.maxS*R.maxP;
    return {L.ile+R.ile+ne,L.p,R.k,x,y,L.s+R.s};
}

void upd(int v,int x)
{
    v+=pot-1;
    seg[v].p=x;
    seg[v].k=x;
    while(v>1)
    {
        v/=2;
        seg[v]=Merge(seg[2*v],seg[2*v+1]);
    }
}

V que(int v,int l,int r,int a,int b)
{
    if(r<a||l>b) return {0,inf,-inf,0,0,0};
    if(a<=l&&b>=r) return seg[v];
    return Merge(que(2*v,l,(l+r)/2,a,b),que(2*v+1,(l+r)/2+1,r,a,b));
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
        int n,q,a;
        cin>>n>>q;
        while(pot<n) pot*=2;
        for(int i=1;i<=n;i++)
        {
            cin>>a;
            seg[i+pot-1]={1,a,a,1,1,1};
        }
        for(int i=n+1;i<=pot;i++) seg[i+pot-1]={0,inf,-inf,0,0,0};
        for(int i=pot-1;i>0;i--)
        {
            seg[i]=Merge(seg[2*i],seg[2*i+1]);
           // cout<<seg[i].ile<<" "<<seg[i].maxP<<" "<<seg[i].maxS<<endl;
        }
        while(q--)
        {
            int t,l,r;
            cin>>t>>l>>r;
            if(t==1) upd(l,r);
            else cout<<que(1,1,pot,l,r).ile<<endl;
        }
    }

    return 0;
}