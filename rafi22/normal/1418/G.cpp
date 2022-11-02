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

int a[500007];
int L[500007];
vector<int>pos[500007];
pair<int,int> seg[2000007];
int lazy[2000007],pot=1;

void push(int v)
{
    seg[2*v].st+=lazy[v];
    seg[2*v+1].st+=lazy[v];
    lazy[2*v]+=lazy[v];
    lazy[2*v+1]+=lazy[v];
    lazy[v]=0;
}

void ins(int v,int a,int b,int l,int r,int x)
{
    if(a<=l&&b>=r)
    {
        seg[v].st+=x;
        lazy[v]+=x;
        return ;
    }
    if(r<a||l>b) return;
    push(v);
    ins(2*v,a,b,l,(l+r)/2,x);
    ins(2*v+1,a,b,(l+r)/2+1,r,x);
    if(seg[2*v].st<seg[2*v+1].st) seg[v]=seg[2*v];
    else if(seg[2*v].st==seg[2*v+1].st) seg[v]={seg[2*v].st,seg[2*v].nd+seg[2*v+1].nd};
    else seg[v]=seg[2*v+1];
}


pair<int,int> que(int v,int a,int b,int l,int r)
{
    if(r<a||l>b) return {inf,0};
    if(a<=l&&b>=r) return seg[v];
    push(v);
    pair<int,int>p1=que(2*v,a,b,l,(l+r)/2),p2=que(2*v+1,a,b,(l+r)/2+1,r);
    if(p1.st<p2.st) return p1;
    else if(p1.st==p2.st) return {p1.st,p1.nd+p2.nd};
    else return p2;
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
        int n,ans=0,kon=0;
        cin>>n;
        while(pot<n) pot*=2;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            seg[i+pot-1].nd=1;
        }
        for(int i=pot-1;i>0;i--) seg[i].nd=seg[2*i].nd+seg[2*i+1].nd;
        for(int i=1;i<=n;i++)
        {
            if(sz(pos[a[i]])>=3) kon=max(kon,pos[a[i]][sz(pos[a[i]])-3]);
            if(sz(pos[a[i]])>=2) L[i]=pos[a[i]][sz(pos[a[i]])-2];
            if(sz(pos[a[i]])>0) ins(1,L[pos[a[i]].back()]+1,pos[a[i]].back(),1,pot,-1);
            pos[a[i]].pb(i);
            ins(1,L[pos[a[i]].back()]+1,pos[a[i]].back(),1,pot,1);
            pair<int,int>p=que(1,kon+1,i,1,pot);
            if(p.st==0) ans+=p.nd;
        }
        cout<<ans;
    }

    return 0;
}