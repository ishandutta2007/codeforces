#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
const int p=998244353;

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
int power(int a,int b)
{
	int ret=1;
	while (b)
	{
		if (b&1) ret=1LL*ret*a%p;
		a=1LL*a*a%p;
		b/=2;
	}
	return ret;
}
int fact[N],inv[N];
void ysgs(int n)
{
	for (int i=fact[0]=1;i<=n;i++) fact[i]=1LL*fact[i-1]*i%p;
	inv[n]=power(fact[n],p-2);
	for (int i=n;i>=1;i--) inv[i-1]=1LL*inv[i]*i%p;
}
vector<int>f,g,h,rev;
int lim,l;
void NTT(vector<int>&a,int type)
{
	for (int i=0;i<lim;i++) if (i<rev[i]) swap(a[i],a[rev[i]]);
	for (int mid=1;mid<lim;mid*=2)
	{
		int Wn=power(type>0?3:power(3,p-2),(p-1)/mid/2);
		for (int len=mid*2,k=0;k<lim;k+=len)
		for (int i=k,w=1;i<k+mid;i++,w=1LL*w*Wn%p)
		{
			int x=a[i],y=1LL*w*a[i+mid]%p;
			a[i]=(x+y)%p;
			a[i+mid]=(x-y+p)%p;
		}
	}
	if (type<0)
	for (int inv=power(lim,p-2),i=0;i<lim;i++) a[i]=1LL*a[i]*inv%p;
}
vector<int>conv(vector<int>a,vector<int>b)
{
	lim=1,l=0;
	int n=a.size(),m=b.size();
	while (lim<=n+m) lim*=2,l++;
	rev.clear(),rev.push_back(0);
	for (int i=1;i<lim;i++) rev.push_back((rev[i>>1]>>1)|((i&1)<<(l-1)));
	a.resize(lim),b.resize(lim);
	NTT(a,1);
	NTT(b,1);
	for (int i=0;i<lim;i++) a[i]=1LL*a[i]*b[i]%p;
	NTT(a,-1);
	return a;
}

signed main(signed Goodbye,char *Wangang[])
{
	(void)Goodbye,(void)Wangang;
	ysgs(2e5);
	int n=read();
	f.push_back(1);
	while (n--)
	{
		int x=read(),y=read(),tmp=f.size();
		h.clear(),g=f;
		for (int i=-(tmp-1);i<tmp+x-y;i++) h.push_back(y+i<0||x-i<0?0:1LL*inv[y+i]*inv[x-i]%p);
		f=conv(g,h);
		for (int &i:f) i=1LL*i*fact[x+y]%p;
		for (int i=tmp-1;i<(int)f.size();i++) f[i-(tmp-1)]=f[i];
		f.resize(tmp+x-y);
	}
	int ans=0;
	for (int i:f) ans=(ans+i)%p;
	print(ans);
	
	return 0;
}