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

int seg[800007],pot=1;
int x[200007];

void ins(int v,int d)
{
    v+=pot-1;
    while(v>0)
    {
        seg[v]+=d;
        v/=2;
    }
}
int que(int v,int a,int b,int l,int r)
{
    if(a<=l&&b>=r) return seg[v];
    if(l>b||r<a) return 0;
    return que(2*v,a,b,l,(l+r)/2)+que(2*v+1,a,b,(l+r)/2+1,r);
}
int kth(int v,int k)
{
    if(v>=pot) return v-pot+1;
    if(seg[2*v]>=k) return kth(2*v,k);
    else return kth(2*v+1,k-seg[2*v]);
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
        int n,a;
        cin>>n;
        while(pot<n) pot*=2;
        for(int i=1;i<=n;i++)
        {
            cin>>a;
            a++;
            x[i]+=a-1-que(1,1,a-1,1,pot);
            ins(a,1);
        }
        for(int i=1;i<2*pot;i++) seg[i]=0;
        for(int i=1;i<=n;i++)
        {
            cin>>a;
            a++;
            x[i]+=a-1-que(1,1,a-1,1,pot);
            ins(a,1);
        }
        for(int i=n-1;i>0;i--)
        {
            x[i-1]+=x[i]/(n-i+1);
            x[i]%=(n-i+1);
        }
        x[n]=0;
        for(int i=pot;i<pot+n;i++) seg[i]=1;
        for(int i=pot-1;i>0;i--) seg[i]=seg[2*i]+seg[2*i+1];
        for(int i=1;i<=n;i++)
        {
            a=kth(1,x[i]+1);
            cout<<a-1<<" ";
            ins(a,-1);
        }
    }

    return 0;
}