#include <bits/stdc++.h>

#define int long long
#define ll long long
#define ld long double
//#define endl '\n'
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

const int N=400007;

int x[N];
bool is[N];
bool was[N];

void gg()
{
    cout<<-1;
    exit(0);
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
        int n,a,b,mn=inf,mx=-inf;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a>>b;
            if(min(a,b)>mn) gg();
            if(max(a,b)<mx) gg();
            mn=min(mn,max(a,b));
            mx=max(mx,min(a,b));
            if(a<b)
            {
                x[a]=b;
                x[b]=a;
            }
            else
            {
                x[a]=b;
                x[b]=a;
                is[a]=1;
                is[b]=1;
            }
        }
        int ans=0;
        int i=0,j=2*n+1;
        int L=2*n+1,R=0;
        while(i<j)
        {
            int l0=0,r0=0,l1=0,r1=0;
            i++;
            if(was[i]) continue;
            if(is[i]) l1++;
            else l0++;
            was[i]=1;
            was[x[i]]=1;
            L=x[i];
            while(i+1<R||j-1>L)
            {
                if(i+1<R)
                {
                    i++;
                    if(was[i]) continue;
                  //  cout<<"L "<<i<<" "<<R<<endl;
                    if(is[i]) l1++;
                    else l0++;
                    was[i]=1;
                    was[x[i]]=1;
                    if(x[i]>L) gg();
                    L=x[i];
                }
                else
                {
                    j--;
                    if(was[j]) continue;
                    if(is[j]) r1++;
                    else r0++;
                    was[j]=1;
                    was[x[j]]=1;
                    if(x[j]<R) gg();
                    R=x[j];
                }
            }
           // cout<<l0<<" "<<l1<<" "<<r0<<" "<<r1<<endl;
            ans+=min(l0+r1,l1+r0);
        }
        cout<<ans;
    }

    return 0;
}