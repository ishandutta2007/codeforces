#include <bits/stdc++.h>

#define int long long
#define ll long long
#define ld long double
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
using namespace std;
double PI=3.14159265359;
int inf=1000000000000000007;
int mod=1000000007;
int mod1=998244353;

const bool multi=1;

const int N=200007;

int a[N];
int mx[N];
int R[N];
int ile[N],ileO[N];

struct Btree
{
    int BIT[200007];
    Btree()
    {
        memset(BIT,0,sizeof BIT);
    }
    int QUE(int x)
    {
        int s=0;
        for (; x; x-=x&-x) s+=BIT[x];
        return s;
    }
    int que(int l,int r)
    {
        return (QUE(r)%mod-QUE(l-1)%mod+mod)%mod;
    }
    void ins(int x,int s)
    {
        for (; x<=200000; x+=x&-x) BIT[x]=(BIT[x]+s)%mod;
    }
};

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
        cin>>n;
        vector<pair<int,int>>V;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            V.pb({a[i],i});
        }
        sort(all(V));
        int it=1;
        a[V[0].nd]=it;
        for(int i=1;i<n;i++)
        {
            if(V[i].st!=V[i-1].st) it++;
            a[V[i].nd]=it;
        }
        mx[n+1]=0;
        for(int i=n;i>0;i--) mx[i]=max(mx[i+1],a[i]);
        for(int i=1;i<=it;i++)
        {
            int l=1,r=n,sr;
            while(l<=r)
            {
                sr=(l+r)/2;
                if(mx[sr]>i)
                {
                    R[i]=sr;
                    l=sr+1;
                }
                else r=sr-1;
            }
        }
        Btree T1,T2;
        for(int i=n;i>0;i--)
        {
            int l=a[i]+1,r=it,sr,k=a[i];
            while(l<=r)
            {
                sr=(l+r)/2;
                if(R[sr]==R[a[i]])
                {
                    k=sr;
                    l=sr+1;
                }
                else r=sr-1;
            }
            ile[i]=(1+T1.que(a[i]+1,it)+T2.que(k+1,it)-ile[R[a[i]]]+mod)%mod;
            ileO[i]=(T2.que(a[i]+1,k)+ile[R[a[i]]])%mod;
            T1.ins(a[i],ile[i]);
            T2.ins(a[i],ileO[i]);
        }
        memset(T1.BIT,0,sizeof T1.BIT);
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            int x=(T1.que(1,a[i]-1)+1)%mod;
            T1.ins(a[i],x);
            if(R[a[i]]>i) ans=(ans+x*ile[i])%mod;
        }
        cout<<ans<<endl;
        for(int i=1;i<=n;i++)
        {
            ile[i]=0;
            ileO[i]=0;
            mx[i]=0;
            R[i]=0;
            a[i]=0;
        }
    }

    return 0;
}