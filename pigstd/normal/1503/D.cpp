#include<bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

const int M=2e5+10;
int c[M],n,f[M],a[M],b[M],pre[M],suf[M];
int st1[M],st2[M],ans;

int F(int l,int r)
{
	int top1=0,top2=0,s1=0,s2=0;
	for (int i=l;i<=r;i++)
	{
		if (top1==0||st1[top1]>=f[i])st1[++top1]=f[i],s1+=c[i];
		else if (top2==0||st2[top2]>=f[i])st2[++top2]=f[i],s2+=c[i];
		else return -1;
	}
	return min(s1-s2+top2,s2-s1+top1);
}

signed main()
{
	n=read();
	for (int i=1;i<=n;i++)
	{
		a[i]=read(),b[i]=read();
		if (a[i]>b[i])swap(a[i],b[i]),c[a[i]]=1;
		if (a[i]>n)return puts("-1"),0;
		f[a[i]]=b[i];
	}pre[0]=1e18;
	for (int i=1;i<=n;i++)
		pre[i]=min(pre[i-1],f[i]);
	for (int i=n;i>=1;i--)
		suf[i]=max(suf[i+1],f[i]);
	for (int i=1;i<=n;i++)
	{
		int p=i;while(pre[p]<=suf[p+1])p++;
		int x=F(i,p);if (x==-1)ans=-1e18;
		ans+=x;i=p;
	}
	if (ans<0)puts("-1");
	else cout<<ans<<endl;
	return 0;
}