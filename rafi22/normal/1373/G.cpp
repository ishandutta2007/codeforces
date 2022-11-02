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

const int pot=(1<<20);
int seg[2*pot+7];
int lazy[2*pot+7];

void push(int v)
{
    lazy[2*v]+=lazy[v];
    lazy[2*v+1]+=lazy[v];
    seg[2*v]+=lazy[v];
    seg[2*v+1]+=lazy[v];
    lazy[v]=0;
}

void ins(int v,int a,int b,int l,int r,int x)
{
    if(r<a||l>b) return;
    if(a<=l&&b>=r)
    {
        seg[v]+=x;
        lazy[v]+=x;
        return ;
    }
    push(v);
    ins(2*v,a,b,l,(l+r)/2,x);
    ins(2*v+1,a,b,(l+r)/2+1,r,x);
    seg[v]=min(seg[2*v],seg[2*v+1]);
}
int que(int v,int a,int b,int l,int r)
{
    if(r<a||l>b) return inf;
    if(a<=l&&b>=r) return seg[v];
    push(v);
    return min(que(2*v,a,b,l,(l+r)/2),que(2*v+1,a,b,(l+r)/2+1,r));
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
        int n,k,m,x,y;
        cin>>n>>k>>m;
        set<pair<int,int>>S;
        multiset<int>mx;
        for(int i=1;i<=600000;i++) seg[i+pot-1]=600000-i+1;
        for(int i=pot-1;i>0;i--) seg[i]=min(seg[2*i],seg[2*i+1]);
        while(m--)
        {
            cin>>x>>y;
            if(S.count({x,y}))
            {
                S.erase({x,y});
                mx.erase(mx.find(y+abs(k-x)));
                ins(1,1,y+abs(k-x),1,pot,1);
            }
            else
            {
                S.insert({x,y});
                mx.insert(y+abs(k-x));
                ins(1,1,y+abs(k-x),1,pot,-1);
            }
            if(sz(mx)==0) cout<<0<<endl;
            else
            {
                int mn=que(1,1,*(--mx.end()),1,pot);
                cout<<max(0LL,600000-mn-n)<<endl;
            }
        }
    }

    return 0;
}