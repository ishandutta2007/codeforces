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

int a[111],b[111],id[111];

bool check(int n,vector<int>&v)
{
	if(n==0)return true;
	while(true)
	{
		bool have=0;
		for(int i=1;i<=n;i++)if(a[i])have=1;
		if(!have)return true;
		int cur=0;
		bool ok=0;
		for(int i=1;i<=n;i++)
		{
			cur=max(0,cur-b[i]);
			if(a[i]&&cur<=a[i])
			{
				for(int j=i;j>=1;j--)
				{
					if(a[j])v.pb(id[j]);
					a[j]=b[j]=0;
				}
				ok=1;
				break;
			}
		}
		if(!ok)return false;
	}
}

int n,m,v[111],pos[111],hp[111];
int h[111];
int main()
{
	get2(n,m);
	for(int i=1;i<=m;i++)
	{
		get2(pos[i],hp[i]);
		h[pos[i]]=i;
	}
	for(int i=1;i<=n;i++)get1(v[i]);
	
	for(int i=0;i<=n;i++)
	{
		vector<int> v1,v2;
		
		int k=0;
		for(int j=i;j>=1;j--)
		{
			a[++k]=hp[h[j]];
			id[k]=h[j];
			b[k]=v[j];
		}
		if(!check(k,v1))continue;
		if((int)v1.size()==0)continue;
		
		k=0;
		for(int j=i+1;j<=n;j++)
		{
			a[++k]=hp[h[j]];
			id[k]=h[j];
			b[k]=v[j];
		}
		if(!check(k,v2))continue;
		printf("%d\n",max(i,1));
		
		bool fb=0;
		for(auto&v:v1)
		{
			if(!fb)fb=1;
			else putchar(' ');
			printf("%d",v);
		}
		for(auto&v:v2)
		{
			if(!fb)fb=1;
			else putchar(' ');
			printf("%d",v);
		}
		puts("");
		return 0;
	}
	puts("-1");
	return 0;
}