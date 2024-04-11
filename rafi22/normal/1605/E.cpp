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

const bool multi=0;

const int N=200007;

int k[N],l[N];
int a[N];
int b[N];
vector<int>V[2000007];
vector<int>V1[2000007];
int ak[2000007];
int al[2000007];

int bs(int k,int l)
{
    int L=-1000000,R=1000000,sr,ans=1000001;
    while(L<=R)
    {
        sr=(L+R)/2;
        if(k+sr*l>=0)
        {
            ans=sr;
            R=sr-1;
        }
        else L=sr+1;
    }
    return ans;
}

int bs1(int k,int l)
{
    int L=-1000000,R=1000000,sr,ans=-1000001;
    while(L<=R)
    {
        sr=(L+R)/2;
        if(k+sr*l>=0)
        {
            ans=sr;
            L=sr+1;
        }
        else R=sr-1;
    }
    return ans;
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
        int n;
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<=n;i++) cin>>b[i];
        l[1]=1;
        int sum=0,tk=0,tl=0,tk1=0,tl1=0;
        for(int i=2;i<=n;i++)
        {
            k[i]=b[i]-a[i];
            for(int j=1;j*j<=i;j++)
            {
                if(i%j!=0) continue;
                k[i]-=k[j];
                l[i]-=l[j];
                if(i/j!=j&&i/j!=i)
                {
                    k[i]-=k[i/j];
                    l[i]-=l[i/j];
                }
            }
            if(l[i]>0)
            {
                V[bs(k[i],l[i])+1000001].pb(i);
                tk+=k[i];
                tl+=l[i];
            }
            if(l[i]==0) sum+=abs(k[i]);
            if(l[i]<0)
            {
                V1[bs1(k[i],l[i])+1000001].pb(i);
                tk1+=k[i];
                tl1+=l[i];
            }
        }
        for(int i=2000002;i>0;i--)
        {
            ak[i]+=tk;
            al[i]+=tl;
            for(auto x:V[i])
            {
                tk-=2*k[x];
                tl-=2*l[x];
            }
        }
        for(int i=0;i<=2000001;i++)
        {
            ak[i]+=tk1;
            al[i]+=tl1;
            for(auto x:V1[i])
            {
                tk1-=2*k[x];
                tl1-=2*l[x];
            }
        }
       // cout<<sum<<endl;
        int q;
        cin>>q;
        while(q--)
        {
            int x;
            cin>>x;
            x-=a[1];
            cout<<sum+ak[x+1000001]+x*al[x+1000001]+abs(x)<<endl;
        }
    }

    return 0;
}