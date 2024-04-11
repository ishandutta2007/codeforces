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
#define MAXN 1000011
char s[MAXN];
int main()
{
    scanf("%s",s+1);
    int n=strlen(s+1);
    printf("3\n");
    printf("R %d\n",n-1);
    printf("L %d\n",n);
    printf("L 2\n");
    return 0;
}