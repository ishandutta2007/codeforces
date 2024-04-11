#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#include<map>
typedef long long ll;
typedef std::pair<int,int> pii;
ll read(){ll x=0,f=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9')x=x*10+(c-'0'),c=getchar();return f*x;}
ll max(ll a,ll b){return a>b?a:b;}
int min(int a,int b){return a<b?a:b;}
void umax(int& a,int t){if(a<t)a=t;}
bool umin(ll& a,ll t){if(a>t)return a=t,1;return 0;}
/**********/
#define MAXN 1000011
char a[MAXN],b[MAXN];
int main()
{
	int n=read();
	scanf("%s%s",a+1,b+1);
	int ans=0;
	for(int i=1;i<n;++i)
		if(a[i]!=b[i])
		{
			if(a[i+1]!=b[i+1]&&a[i]!=a[i+1])std::swap(a[i],a[i+1]),++ans;
			else ++ans;
		}
	printf("%d\n",ans+(a[n]!=b[n]));
	return 0;
}