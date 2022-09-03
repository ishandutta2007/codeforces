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

int n,a[100111],b[100111];
vector<int> g[100111];
int main()
{
	get1(n);
	for(int i=1;i<=n;i++)
	{
		get1(a[i]);
		g[n-a[i]-1].pb(i);
	}
	int cur=0;
	for(int i=0;i<n;i++)
	{
		int sz=(int)g[i].size();
		if(sz%(i+1))
		{
			puts("Impossible");
			return 0;
		}
		for(int j=0;j<(int)g[i].size();j++)
		{
			if(j%(i+1)==0)cur++;
			b[g[i][j]]=cur;
		}
	}
	puts("Possible");
	for(int i=1;i<=n;i++)printf("%d ",b[i]);
	return 0;
}