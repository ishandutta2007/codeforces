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
typedef std::pair<ll,ll> pll;
typedef std::pair<double,double> pd;
ll read(){ll x=0,f=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}return f*x;}
ll max(ll a,ll b){return a>b?a:b;}
ll min(ll a,ll b){return a<b?a:b;}
void umax(ll& a,ll t){if(t>a)a=t;}
bool umin(int& a,int t){if(t<=a)return a=t,1;return 0;}
#define MAXN 200011
char a[MAXN];
int main()
{
    int task=read();
    while(task--)
    {
        int n=read();
        scanf("%s",a+1);
        int it=2;
        while(it<=n&&a[it]==a[1])++it;
        if(it>n)
        {
            int ans=n/3;
            if(n%3+2>=3)++ans;
            printf("%d\n",ans);continue;
        }
        int ed=n;
        while(a[ed]==a[1])--ed;
        int ans=(it-1+(n-ed))/3;
        for(int i=it,j;i<=ed;i=j)
        {
            j=i+1;
            while(a[j]==a[i])++j;
            ans+=(j-i)/3;
        }
        printf("%d\n",ans);
    }
    return 0;
}