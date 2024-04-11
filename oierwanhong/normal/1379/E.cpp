#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#include<set>
typedef long long ll;
typedef std::vector<int> P;
typedef std::pair<int,int> pii;
int read(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9')x=x*10+(c-'0'),c=getchar();return f*x;}
int max(int a,int b){return a>b?a:b;}
int min(int a,int b){return a<b?a:b;}
template <typename T> bool umax(T& a,T t){if(t>a)return a=t,1;return 0;}
template <typename T> bool umin(T& a,T t){if(t<a)return a=t,1;return 0;}
/**********/
const int MAXN = 200011;
int seq[MAXN],a[MAXN],fa[MAXN];
bool is_pow2(int n){return !(n&(n-1));}
int main()
{
	int n=read(),k=read();
	if(n%2==0||k>max((n-3)/2,0)||(is_pow2(n+1)&&k==1)||(n==9&&k==2)){puts("NO");return 0;}
	fa[1]=0;
	if(k==0)
	{
		if(is_pow2(n+1))
		{
			puts("YES");
			for(int i=1;i<=n;++i)printf("%d ",i>>1);
			puts("");
		}
		else puts("NO");
		return 0;
	}
	for(int i=2;i<k+k-1;i+=2)fa[i]=fa[i+1]=i-1;
	seq[1]=k+k-1;
	for(int w=1,cur=k+k-1;cur<n;w<<=1)
	{
		for(int t=1;t<=w&&cur<n;++t)
			a[t*2-1]=++cur,fa[cur]=seq[t],a[t*2]=++cur,fa[cur]=seq[t];
		if(cur==n&&a[w<<1]&&k>0)
		{
			fa[a[w*2-1]]=fa[a[w*2]]=2;
		}
		for(int t=1;t<=(w<<1);++t)seq[t]=a[t],a[t]=0;
	}
	puts("YES");
	for(int i=1;i<=n;++i)printf("%d ",fa[i]);
	puts("");
	return 0;
}