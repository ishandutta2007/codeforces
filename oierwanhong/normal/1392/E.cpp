#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
typedef long long ll;
typedef unsigned un;
typedef unsigned long long ull;
//typedef std::string str;
typedef std::pair<int,int> pii;
typedef std::pair<double,double> pd;
ll read(){ll x=0,f=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}return f*x;}
ll max(ll a,ll b){return a>b?a:b;}
ll min(ll a,ll b){return a<b?a:b;}
void umax(ll& a,ll t){if(t>a)a=t;}
bool umin(int& a,int t){if(t<=a)return a=t,1;return 0;}
#define MAXN 51
ll a[MAXN][MAXN];
int main()
{
    int n;std::cin>>n;
    for(ll j=n,r=1ll<<52;j>0;j-=2,r>>=2)//!
        for(ll i=n,now=r;i;--i,now>>=1)
            a[i][j]=now;
    // puts("pass 26");return 0;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)std::cout<<a[i][j]<<(j==n?'\n':' ');
    std::cout.flush();
    int q;std::cin>>q;
    while(q--)
    {
        ll k=read()-a[n][n];
        std::vector<pii>res;
        res.push_back(pii(n,n));
        int x=n,y=n;
        while(x>1&&y>1)
        {
            if(a[x-1][y])
                if(k>=a[x-1][y])k-=a[x-1][y],--x;
                else --y;
            else
            {
                if(k>=a[x][y-1])k-=a[x][y-1],--y;
                else --x;
            }
            res.push_back(pii(x,y));
        }
        while(x>1)--x,res.push_back(pii(x,y));
        while(y>1)--y,res.push_back(pii(x,y));
        std::reverse(res.begin(),res.end());
        for(auto x:res)std::cout<<x.first<<" "<<x.second<<'\n';
        std::cout.flush();
    }
    return 0;
}