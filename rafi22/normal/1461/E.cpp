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

void gg()
{
    cout<<"Yes";
    exit(0);
}
void bg()
{
    cout<<"No";
    exit(0);
}
int mul(int a,int b)
{
    int res=0;
    while(b>0)
    {
        if(b&1) res=min(res+a,inf);
        a=min(a+a,inf);
        b/=2;
    }
    return res;
}
map<int,int>mapa;
bool was[1000007];

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
        int k,l,r,t,x,y;
        cin>>k>>l>>r>>t>>x>>y;
        if(x>=y)
        {
            if(k+y<=r) k+=y;
            k-=x;
            if(k<l||k-mul(t-1,x-y)<l) bg();
            gg();
        }
        while(t)
        {
            if(was[k%x]) gg();
            was[k%x]=1;
            int xd=min(t,(k-l)/x);
            k-=xd*x;
            t-=xd;
            if(t==0) gg();
            t--;
            if(k+y<=r) k+=y;
            k-=x;
            if(k<l) bg();
        }
        gg();


       // cout<<R<<endl;
    }

    return 0;
}