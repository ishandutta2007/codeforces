//Wan Hong 3.1
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<vector>
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned un;
typedef std::pair<ll,ll> pll;
typedef std::string str;
// static char buf[10000000],*p1=buf,*p2=buf;
// #define getchar() p1==p2&&(p2=(p1=buf)+fread(buf,1,10000000,stdin),p1==p2)?EOF:*p1++
ll read(){ll f=1,x=0;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return f*x;}
ll max(ll a,ll b){return a>b?a:b;}
ll min(ll a,ll b){return a<b?a:b;}
bool umax(int& a,int b){if(b>a)return a=b,1;return 0;}
bool umax(ll& a,ll b){if(b>a)return a=b,1;return 0;}
bool umin(ll& a,ll b){if(b<a)return a=b,1;return 0;}
bool umin(int& a,int b){if(b<a)return a=b,1;return 0;}
int abs(int x){return x>0?x:-x;}
/**********/
#define MAXN 511
char a[MAXN][MAXN];
std::vector<pll>res;
void print()
{
    std::cout<<res.size()<<'\n';
    for(auto x:res)std::cout<<x.first<<" "<<x.second<<'\n';
    res.clear();
}
int main()
{
    int task=read();
    while(task--)
    {
        int n=read();
        for(int i=1;i<=n;++i)scanf("%s",a[i]+1);
        if(a[1][2]==a[2][1])
        {
            char p=a[1][2];
            if(a[n-1][n]==p)res.push_back(pll(n-1,n));
            if(a[n][n-1]==p)res.push_back(pll(n,n-1));
        }
        else if(a[n-1][n]==a[n][n-1])
        {
            char p=a[n-1][n];
            if(a[1][2]==p)res.push_back(pll(1,2));
            if(a[2][1]==p)res.push_back(pll(2,1));
        }
        else
        {
            if(a[1][2]=='1')res.push_back(pll(1,2));
            else res.push_back(pll(2,1));
            if(a[n-1][n]=='0')res.push_back(pll(n-1,n));
            else res.push_back(pll(n,n-1));
        }
        print();
    }
    return 0;
}