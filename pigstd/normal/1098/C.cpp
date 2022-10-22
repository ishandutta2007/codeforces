//AFO countdown:???
#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define WT int TT=read();while(TT--) 
#define NO puts("NO");
#define YES puts("YES");
using namespace std;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

const int M=1e5+10;
int n,k,fa[M],f[M],Cnt;

bool check(int x)
{
	f[1]=1;
	for (int i=2;i<=n;i++)
	{
		f[i]=i;
		if (i-1<=x)
			f[i]=2*i-1;
		else
		{
			int k1=(i-1)/x,s1=(i-1)%x,k2=k1+1,s2=x-s1;
			swap(s1,s2);
			f[i]+=s1*f[k1]+s2*f[k2];
		}
	}
	return f[n]<=k;
}

void dfs(int u,int l,int r,int k,int p)
{
//	assert(u<=n);
	if (l>r)return;
	int s=r-l+1;k-=s+1;
//	if (k==s*(s+1)/2){fa[l]=u,dfs(l,l+1,r,k-s,p);return;}
	int k1=s/p,s1=s%p,k2=k1+1,s2=p-s1;
	swap(s1,s2);
	for (int i=1;i<=s1&&k1!=0;i++)
	{
//		Cnt++;
		if (f[k1]+(s-k1)*(s-k1+1)/2>=k)
			fa[l]=u,dfs(l,l+1,l+k1-1,f[k1],p),l+=k1,k-=f[k1],s-=k1;
		else
		{
//			Cnt+=114;
			for (int i=0;i<=s;i++)
				if (i*(i+1)/2+(s-i)*(s-i+1)/2>=k&&i*(i+1)/2+f[s-i]<=k)
				{
					fa[l]=fa[l+i]=u;
					dfs(l,l+1,l+i-1,i*(i+1)/2,p),
					dfs(l+i,l+i+1,r,k-i*(i+1)/2,p);
					return;
				}
		}
	}
	if (k==0)return;
	for (int i=1;i<=s2;i++)
	{
//		Cnt++;
		if (f[k2]+(s-k2)*(s-k2+1)/2>=k)
			fa[l]=u,dfs(l,l+1,l+k2-1,f[k2],p),l+=k2,k-=f[k2],s-=k2;
		else
		{
//			Cnt+=514;
			for (int i=0;i<=s;i++)
				if (i*(i+1)/2+(s-i)*(s-i+1)/2>=k&&i*(i+1)/2+f[s-i]<=k)
				{
					fa[l]=fa[l+i]=u;
					dfs(l,l+1,l+i-1,i*(i+1)/2,p),
					dfs(l+i,l+i+1,r,k-i*(i+1)/2,p);
					return;
				}
		}
	}//k=1;
	assert(k==0);
}

signed main()
{
	n=read(),k=read();
	if (k<n*2-1||k>n*(n+1)/2)return puts("No"),0;
	int tl=1,tr=n,p;
	while(tl<=tr)
	{
		int Mid=(tl+tr)>>1;
		if (check(Mid))tr=Mid-1,p=Mid;
		else tl=Mid+1;
	}puts("Yes");
	check(p);//cout<<p<<endl;
	dfs(1,2,n,k,p);
//	cout<<Cnt<<endl;
//	cout<<Cnt<<endl;
	for (int i=2;i<=n;i++)
		printf("%lld ",fa[i]);
	return 0;
}