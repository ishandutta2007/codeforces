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

int n,d[100111];
int main()
{
	get1(n);
	for(int i=1,u,v;i<n;i++)
	{
		get2(u,v);
		d[u]++;
		d[v]++;
	}
	int cv=0;
	for(int i=1;i<=n;i++)if(d[i]>2)
	{
		if(cv)
		{
			puts("No");
			return 0;
		}
		cv=i;
	}
	if(cv)
	{
		puts("Yes");
		int ans=0;
		for(int i=1;i<=n;i++)ans+=(d[i]==1);
		printendl(ans);
		for(int i=1;i<=n;i++)if(d[i]==1)printf("%d %d\n",cv,i);
	}
	else
	{
		int v1=0,v2=0;
		for(int i=1;i<=n;i++)if(d[i]==1)
		{
			if(v1)v2=i;
			else v1=i;
		}
		printf("Yes\n1\n%d %d\n",v1,v2);
	}
	return 0;
}