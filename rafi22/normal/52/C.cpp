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
int seg[1200007],lazy[1200007],pot=1;

void push(int v)
{
    seg[2*v]+=lazy[v];
    lazy[2*v]+=lazy[v];
    seg[2*v+1]+=lazy[v];
    lazy[2*v+1]+=lazy[v];
    lazy[v]=0;
}

void ins(int v,int a,int b,int l,int r,int d)
{
    if(a<=l&&b>=r)
    {
        seg[v]+=d;
        lazy[v]+=d;
        return;
    }
    if(r<a||l>b) return;
    push(v);
    ins(2*v,a,b,l,(l+r)/2,d);
    ins(2*v+1,a,b,(l+r)/2+1,r,d);
    seg[v]=min(seg[2*v],seg[2*v+1]);
}
int que(int v,int a,int b,int l,int r)
{
    if(a<=l&&b>=r) return seg[v];
    if(r<a||l>b) return inf;
    push(v);
    seg[v]=min(seg[2*v],seg[2*v+1]);
    return min(que(2*v,a,b,l,(l+r)/2),que(2*v+1,a,b,(l+r)/2+1,r));
}

char buf[10000000];

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
        int n;
        gets(buf);
        sscanf(buf, "%lld", &n);
        gets(buf);
        stringstream bs(buf);
        while(2*n>pot) pot*=2;
        for(int i=0;i<=2*pot;i++) seg[i]=inf;
        for(int i=pot;i<2*pot;i++)
        {
            if(i<pot+n)
            {
                int x;
                bs >> x;
                seg[i]=x;
            }
            else seg[i]=seg[i-n];
        }
        for(int i=pot-1;i>0;i--) seg[i]=min(seg[2*i],seg[2*i+1]);
        int m;
        gets(buf);
        sscanf(buf, "%lld", &m);
        while(m--)
        {
            gets(buf);
            stringstream ss(buf);
            int x, y, z;
            ss>>x>>y;
            x++,y++;
            if(ss>>z)
            {
                if(x>y)
                {
                    ins(1,1,y,1,pot,z);
                    ins(1,x,y+n,1,pot,z);
                    ins(1,x+n,2*n,1,pot,z);
                }
                else
                {
                    ins(1,x,y,1,pot,z);
                    ins(1,x+n,y+n,1,pot,z);
                }
            }
            else
            {
                if(x>y) cout<<que(1,x,y+n,1,pot)<<endl;
                else cout<<que(1,x,y,1,pot)<<endl;
            }
        }
    }

    return 0;
}