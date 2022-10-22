#include<bits/stdc++.h>
#define int long long
#define uint unsigned int
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
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
void ckmax(int &a,int b){a=(a>b?a:b);}
void ckmin(int &a,int b){a=(a<b?a:b);}

const int M=1e6+10;
int n,prime[M],f[M],tot;
uint s[M],res;
std::mt19937 rnd(time(0));
uint Rand(){return (1llu*rnd()<<32)+rnd();} 
map<uint,int>t;

void init(int n)
{
	for (int i=2;i<=n;i++)
	{
		if (f[i])continue;
		uint qwq=Rand();//cout<<qwq<<' ';
		for (int j=i;j<=n;j+=i)
		{
			f[j]=1;int tmp=j,w=0;
			while(tmp%i==0)tmp/=i,w^=1;
			if (w)s[j]^=qwq;
		}
	}
	for (int i=1;i<=n;i++)s[i]^=s[i-1],res^=s[i];
}

signed main()
{
	n=read();init(n);
	if (res==0)
	{
		cout<<n<<'\n';
		for (int i=1;i<=n;i++)cout<<i<<' ';
		return 0;
	}
	for (int i=1;i<=n;i++)t[s[i]]=i;
	if (t[res])
	{
		cout<<n-1<<'\n';int tmp=t[res];
		for (int i=1;i<=n;i++)
			if (i!=tmp)cout<<i<<' ';
		return 0;
	}
	for (int i=1;i<=n;i++)
		if (t[s[i]^res])
		{
			cout<<n-2<<'\n';int tmp1=t[s[i]],tmp2=t[s[i]^res];
			for (int i=1;i<=n;i++)
				if (i!=tmp1&&i!=tmp2)cout<<i<<' ';
			return 0;
		}
	assert(n%4==3);
	cout<<n-3<<'\n';
	for (int i=1;i<=n;i++)
		if (i!=2&&i!=n/2&&i!=n)
			cout<<i<<' '; 
	return 0;
}