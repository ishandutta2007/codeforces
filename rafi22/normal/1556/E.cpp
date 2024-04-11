#include <bits/stdc++.h>

#define int long long
#define ll long long
#define ld long double
//#define endl '\n'
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

struct S
{
    int maxP=0;
    int maxS=0;
    int sum=0;
    int mx=0;
};

S Merge(S L,S R)
{
    return {max(L.maxP,L.sum+R.maxP),max(R.maxS,R.sum+L.maxS),L.sum+R.sum,max(max(L.mx,R.mx),L.maxS+R.maxP)};
}

S seg[4*200007];
int pot=1;

S que(int v,int a,int b,int l,int r)
{
    if(a<=l&&b>=r) return seg[v];
    if(r<a||l>b) return {0,0,0,0};
    return Merge(que(2*v,a,b,l,(l+r)/2),que(2*v+1,a,b,(l+r)/2+1,r));
}

int a[200007];

int seg1[4*200007];
int P[200007];

int que1(int v,int a,int b,int l,int r)
{
    if(a<=l&&b>=r) return seg1[v];
    if(r<a||l>b) return -inf;
    return max(que1(2*v,a,b,l,(l+r)/2),que1(2*v+1,a,b,(l+r)/2+1,r));
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
        int n,q;
        cin>>n>>q;
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<=n;i++)
        {
            int b;
            cin>>b;
            a[i]-=b;
            //cout<<a[i]<<" ";
            P[i]=P[i-1]+a[i];
        }
       // cout<<endl;
        while(pot<n) pot*=2;
        for(int i=1;i<=pot;i++)
        {
            seg1[i+pot-1]=P[i];
            seg[i+pot-1]={max(0LL,a[i]),max(0LL,a[i]),a[i],max(0LL,a[i])};
        }

        for(int i=pot-1;i>0;i--)
        {
            seg[i]=Merge(seg[2*i],seg[2*i+1]);
            seg1[i]=max(seg1[2*i],seg1[2*i+1]);
        }
        while(q--)
        {
            int l,r;
            cin>>l>>r;
            int y=que1(1,l,r,1,pot);
            if(y-P[l-1]>0||(P[r]-P[l-1])!=0) cout<<-1<<endl;
            else
            {
                S x=que(1,l,r,1,pot);
                cout<<x.mx<<endl;
            }
        }
    }

    return 0;
}