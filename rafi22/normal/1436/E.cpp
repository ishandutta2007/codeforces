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

int seg[300007];
bool is[100007];
int n,pot=1;
int que(int v,int a,int b,int l,int p)
{
    if(a<=l&&b>=p) return seg[v];
    if(l>b||p<a) return inf;
    return min(que(2*v,a,b,l,(l+p)/2),que(2*v+1,a,b,(l+p)/2+1,p));
}
void ins(int a,int i)
{
    int y=a+pot-1;
    seg[y]=i;
    while(y>1)
    {
        y/=2;
        seg[y]=min(seg[2*y],seg[2*y+1]);
    }
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

        cin>>n;
        while(pot<n) pot*=2;
        int a;
        for(int i=1;i<=n;i++)
        {
            cin>>a;
            if(seg[a+pot-1]!=i-1&&que(1,1,a-1,1,pot)>seg[a+pot-1])
            {
                is[a]=1;
            }
            ins(a,i);
        }
        for(int i=1;i<=n;i++) if(seg[i+pot-1]!=n&&que(1,1,i-1,1,pot)>seg[i+pot-1]) is[i]=1;
        int ans=n+1;
        for(int i=n;i>0;i--) if(!is[i]) ans=i;
        if(ans==n+1)
        {
            if(que(1,1,n,1,pot)>0) ans++;
        }
        cout<<ans;
    }

    return 0;
}