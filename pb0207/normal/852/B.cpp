#include<cstdio>
#include<cstring>
#include<algorithm>
#include<algorithm>
using namespace std;

typedef long long ll;

const int N=1e6+1e3+7,P=1e9+7,M=2e2+1;

int n,l,m;

int s[N],t[N],d[N],tong[M];

ll a[M],b[M],f[M];

int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();};
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();};
	return x*f;
}

void prod(ll *a,ll *b)
{
	ll c[M];
	memset(c,0,sizeof(c));
	for(int i=0;i<m;i++)
		for(int j=0;j<m;j++)
			c[i+j]=(c[i+j]+a[i]*b[j]%P)%P;
	for(int i=m;i<m*2;i++)
		c[i%m]+=c[i],c[i]=0;
	for(int i=0;i<m;i++)
		a[i]=c[i];
}

int main()
{
	scanf("%d%d%d",&n,&l,&m);
	for(int i=1;i<=n;i++)
		s[i]=read(),s[i]%=m,a[s[i]]++;
	for(int i=1;i<=n;i++)
		d[i]=read(),d[i]%=m,tong[d[i]]++;
	for(int i=1;i<=n;i++)
		t[i]=read(),t[i]%=m;
	for(int i=0;i<m;i++)
		b[i]+=tong[i];
	int k=l-2;
	while(k)
	{
		if(k&1)
			prod(a,b);
		k>>=1;
		prod(b,b);
	}
	for(int i=1;i<=n;i++)
		for(int j=0;j<m;j++)
			f[j]=(f[j]+a[((j-t[i]-d[i])%m+m)%m])%P;
	printf("%lld",f[0]);
}