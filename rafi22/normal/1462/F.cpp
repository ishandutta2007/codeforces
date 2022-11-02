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

const bool multi=1;

pair<int,int>seg[200007];
int ls[200007];
int rs[200007];

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
        int n,ans=inf;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            int l,r;
            cin>>l>>r;
            seg[i]={l,r};
            ls[i]=l;
            rs[i]=r;
        }
        sort(ls+1,ls+n+1);
        sort(rs+1,rs+n+1);
        for(int i=1;i<=n;i++)
        {
            pair<int,int> s=seg[i];
            int l=1,r=n,sr,ile=0;
            while(l<=r)
            {
                sr=(l+r)/2;
                if(ls[sr]>s.nd)
                {
                    ile=n-sr+1;
                    r=sr-1;
                }
                else l=sr+1;
            }
            int L=1,R=n,SR,ILE=0;
            while(L<=R)
            {
                SR=(L+R)/2;
                if(rs[SR]<s.st)
                {
                    ILE=SR;
                    L=SR+1;
                }
                else R=SR-1;
            }
            ans=min(ans,ile+ILE);
        }
        cout<<ans<<endl;
    }
    return 0;
}