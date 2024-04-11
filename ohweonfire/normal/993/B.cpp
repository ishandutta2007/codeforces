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

pii a[111],b[111];
int n,m,v1[111],v2[111];

int getv(const pii&a,const pii&b)
{
	if(a.ff==b.ff&&a.ss!=b.ss)return a.ff;
	if(a.ff==b.ss&&a.ss!=b.ff)return a.ff;
	if(a.ss==b.ff&&a.ff!=b.ss)return a.ss;
	if(a.ss==b.ss&&a.ff!=b.ff)return a.ss;
	return 0;
}

int main()
{
	get2(n,m);
	for(int i=1;i<=n;i++)get2(a[i].ff,a[i].ss);
	for(int i=1;i<=m;i++)get2(b[i].ff,b[i].ss);
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			int tmp=getv(a[i],b[j]);
			if(tmp)
			{
				if(v1[i]==0)v1[i]=tmp;
				else if(v1[i]!=tmp)
				{
					puts("-1");
					return 0;
				}
				if(v2[j]==0)v2[j]=tmp;
				else if(v2[j]!=tmp)
				{
					puts("-1");
					return 0;
				}
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++)if(v1[i])
	{
		if(ans==0)ans=v1[i];
		else if(ans!=v1[i])
		{
			puts("0");
			return 0;
		}
	}
	for(int i=1;i<=m;i++)if(v2[i])
	{
		if(ans==0)ans=v2[i];
		else if(ans!=v2[i])
		{
			puts("0");
			return 0;
		}
	}
	printf("%d\n",ans);
	return 0;
}