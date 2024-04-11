#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+5;

int read()
{
	int s=0;
	char c=getchar(),lc='+';
	while (c<'0'||'9'<c) lc=c,c=getchar();
	while ('0'<=c&&c<='9') s=s*10+c-'0',c=getchar();
	return lc=='-'?-s:s;
}
void write(int x)
{
	if (x<0) putchar('-'),x=-x;
	if (x<10) putchar(x+'0');
	else write(x/10),putchar(x%10+'0');
}
void print(int x,char c='\n')
{
	write(x);
	putchar(c);
}
int a[N],c[N],mu[N],sf[N],sg[N];
void Multi_test_no_horses()
{
	int n=read();
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=1;i<=n;i++) a[i]-=read();
	a[1]--;
	for (int i=1;i<=n;i++) c[i]=a[i];
	mu[1]=1;
	for (int i=1;i<=n;i++)
	for (int j=i+i;j<=n;j+=i)
	c[j]-=c[i],mu[j]-=mu[i];
	int sum=0,sumf=0,sumg=0;
	vector<int>f,g;
	for (int i=1;i<=n;i++)
	if (mu[i]==0) sum+=abs(c[i]);
	else if (mu[i]>0) sumf+=c[i],f.push_back(c[i]);
	else sumg+=c[i],g.push_back(c[i]);
	sort(f.begin(),f.end());
	sort(g.begin(),g.end());
	for (int i=0;i<(int)f.size();i++) sf[i]=(i?sf[i-1]:0)+f[i];
	for (int i=0;i<(int)g.size();i++) sg[i]=(i?sg[i-1]:0)+g[i];
	int Q=read(),F=f.size(),G=g.size();
	while (Q--)
	{
		int x=-read();
		int pos=lower_bound(f.begin(),f.end(),-x)-f.begin()-1;
		int ans=sum+abs(pos>=0?sf[pos]+x*(pos+1):0)+abs(sumf-(pos>=0?sf[pos]:0)+x*(F-pos-1));
		pos=lower_bound(g.begin(),g.end(),x)-g.begin()-1;
		ans+=abs(pos>=0?sg[pos]-x*(pos+1):0)+abs(sumg-(pos>=0?sg[pos]:0)-x*(G-pos-1));
		print(ans);
	}
}

signed main(signed Hello,char *CodeForces[])
{
	(void)Hello,(void)CodeForces;
	int T=1;
//	int T=read();
	while (T--) Multi_test_no_horses();
	
	return 0;
}