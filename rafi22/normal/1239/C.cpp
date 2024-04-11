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

int t[100007];
int ans[100007];
bool is;
pair<int,int> seg[4*100007];
int lazy[4*100007],pot=1;

void push(int v)
{
    lazy[2*v]+=lazy[v];
    lazy[2*v+1]+=lazy[v];
    seg[2*v].st+=lazy[v];
    seg[2*v+1].st+=lazy[v];
    lazy[v]=0;
}

void ins(int v,int a,int b,int l,int r,int x)
{
    if(r<a||l>b) return ;
    if(a<=l&&b>=r)
    {
        seg[v].st+=x;
        lazy[v]+=x;
        return ;
    }
    push(v);
    ins(2*v,a,b,l,(l+r)/2,x);
    ins(2*v+1,a,b,(l+r)/2+1,r,x);
    seg[v]=min(seg[2*v],seg[2*v+1]);
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
        int n,r;
        cin>>n>>r;
        set<pair<int,int>>Q;
        deque<int>q;
        while(pot<n) pot*=2;
        for(int i=1;i<=n;i++)
        {
            //t[i]=rand()%1000000000;
            //cout<<t[i]<<" ";
            cin>>t[i];
            Q.insert({t[i],i});
        }
        for(int i=pot;i<2*pot;i++) seg[i]={inf,i-pot+1};
        for(int i=pot-1;i>0;i--) seg[i]=seg[2*i];
        int ne=-1;
        while(sz(Q)>0)
        {
            pair<int,int>p=*Q.begin(),p1;
           // cout<<"XD "<<p.st<<" "<<p.nd<<endl;
            Q.erase(p);
            if(p.nd>0) ins(1,p.nd,p.nd,1,pot,-inf);
            else
            {
                is=0;
                ins(1,-p.nd+1,n,1,pot,-1);
            }
           // cout<<seg[1].st<<endl;
            bool tak=0;
            if(sz(Q)==0) tak=1;
            else
            {
                p1=*Q.begin();
                if(p1.st!=p.st) tak=1;
            }
            if(tak)
            {
                if(seg[1].st==0)
                {
                    ne=seg[1].nd;
                    ins(1,seg[1].nd,seg[1].nd,1,pot,inf);
                    ins(1,ne+1,n,1,pot,1);
                    q.pb(ne);
                }
               // cout<<p.st<<" "<<is<<" "<<sz(q)<<endl;
                if(!is&&sz(q))
                {
                    is=1;
                    int v=q[0];
                    ans[v]=p.st+r;
                   // cout<<"XYZ "<<p.st<<" "<<v<<endl;
                    Q.insert({p.st+r,-v});
                    q.pop_front();
                }
            }
        }
        for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
    }

    return 0;
}