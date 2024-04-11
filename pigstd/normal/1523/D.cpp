#include<bits/stdc++.h>
#define int long long
#define rand rnd
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define WT int T=read();while(T--) 
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

const int M=2e5+10;
int n,m,p,a[M],b[M],bt[M],pp,maxn,ans;

struct poly
{
	int f[M];
	void clear(){memset(f,0,sizeof(f));}
}fwt;

void AND(poly &a,int x,int cnt)
{
	int n=1<<cnt;
	for (int o=2,k=1;o<=n;o<<=1,k<<=1)
		for (int i=0;i<n;i+=o)
			for (int j=0;j<k;j++)
				a.f[i+j]+=a.f[i+j+k]*x;
}

int get(int x)
{
	int res=0;
	for (int i=0;i<m;i++)
		if (x&(1ll<<i))res++;
	return res;
}

void work(int x)
{
	fwt.clear();int cnt=0;
	for (int i=0;i<m;i++)
		if (a[x]&(1ll<<i))bt[++cnt]=i+1;
	for (int i=1;i<=n;i++)
	{
		b[i]=0;
		for (int j=1;j<=cnt;j++)
			if (a[i]&(1ll<<(bt[j]-1)))b[i]+=1ll<<(j-1);
		fwt.f[b[i]]++;
	}
	AND(fwt,1,cnt);
	for (int i=0;i<(1<<cnt);i++)
		if (fwt.f[i]>=(n+1)/2&&get(i)>maxn)
			maxn=get(i),ans=i,pp=x;
}

std::mt19937 rnd(std::chrono::steady_clock::now().time_since_epoch().count());

signed main()
{
	srand(20061010);
	n=read(),m=read(),p=read();
	for (int i=1;i<=n;i++)
	{
		string s;cin>>s;
		for (int j=0;j<m;j++)
			a[i]+=(1ll<<j)*(s[j]-'0');
	}int T=50; work(n);
	while(T--)
	{
		int x=rand()%n+1;
		work(x);
	}int cnt=0;
	for (int i=0;i<m;i++)
		if (!(a[pp]&(1ll<<i)))cout<<"0";
		else
		{
			if (ans&(1ll<<cnt))cout<<"1";
			else cout<<"0";
			cnt++;
		}
	return 0;
}