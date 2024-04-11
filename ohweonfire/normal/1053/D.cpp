// This amazing code is by Eric Sunli Chen.
#include<bits/stdc++.h>
using namespace std;
template<typename T> bool get_int(T &x)
{
	char t=getchar();
	bool neg=false;
	x=0;
	for(; (t>'9'||t<'0')&&t!='-'&&t!=EOF; t=getchar());
	if(t=='-')neg=true,t=getchar();if(t==EOF)return false;
	for(; t<='9'&&t>='0'; t=getchar())x=x*10+t-'0';
	if(neg)x=-x;return true;
}
template<typename T> void print_int(T x)
{
	if(x<0)putchar('-'),x=-x;
	short a[20]= {},sz=0;
	while(x>0)a[sz++]=x%10,x/=10;
	if(sz==0)putchar('0');
	for(int i=sz-1; i>=0; i--)putchar('0'+a[i]);
}
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define get1(a) get_int(a)
#define get2(a,b) (get1(a)&&get1(b))
#define get3(a,b,c) (get1(a)&&get2(b,c))
#define printendl(a) print_int(a),puts("")
typedef long long LL;
typedef unsigned long long uLL;
typedef pair<int,int> pii;
const int inf=0x3f3f3f3f;
const LL Linf=1ll<<61;
const double pi=acos(-1.0);

const int mod=1e9+7;
const int maxn=2000111;

int mn[maxn],cnt[maxn],nxt[maxn];
void prework()
{
	for(int i=2;i<maxn;i++)if(mn[i]==0)
		for(int j=i;j<maxn;j+=i)if(!mn[j])mn[j]=i;
	for(int i=2;i<maxn;i++)
	{
		if(mn[i]!=mn[i/mn[i]])
		{
			cnt[i]=1;
			nxt[i]=i/mn[i];
		}
		else
		{
			cnt[i]=cnt[i/mn[i]]+1;
			nxt[i]=nxt[i/mn[i]];
		}
	}
}

int n,a[200111],b[200111],mx[maxn],mxc[maxn];
int main()
{
	prework();
	get1(n);
	
	for(int i=1;i<=n;i++)get1(a[i]);
	sort(a+1,a+n+1);reverse(a+1,a+n+1);
	
	for(int i=1;i<=n;i++)
	{
		if(!mx[a[i]])
		{
			mx[a[i]]=1;mxc[a[i]]=1;
			b[i]=a[i];
		}
		else
		{
			int t=a[i]-1;
			while(t!=1)
			{
				if(mx[mn[t]]<cnt[t])
				{
					mx[mn[t]]=cnt[t];
					mxc[mn[t]]=1;
				}
				else if(mx[mn[t]]==cnt[t])mxc[mn[t]]++;
				t=nxt[t];
			}
			b[i]=a[i]-1;
		}
	}
	
	bool add=0;
	for(int i=1;i<=n;i++)
	{
		int t=b[i];
		bool ok=0;
		while(t!=1)
		{
			if(mx[mn[t]]==cnt[t]&&mxc[mn[t]]==1)ok=1;
			t=nxt[t];
		}
		if(!ok)add=1;
	}
	
	int ans=1;
	for(int i=1;i<maxn;i++)
	{
		for(int j=1;j<=mx[i];j++)
			ans=(LL)ans*i%mod;
	}
	if(add)ans=(ans+1)%mod;
	printendl(ans);
	return 0;
}