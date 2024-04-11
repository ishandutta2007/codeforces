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

int n,a[300111];
int main()
{
	get1(n);
	
	LL ans=0;
	int c[2]={1,0},cur=0;
	for(int i=1;i<=n;i++)
	{
		LL x;get1(x);
		a[i]=__builtin_popcountll(x);
		cur^=a[i]&1;
		ans+=c[cur];
		c[cur]++;
	}
	
	for(int i=1;i<=n;i++)
	{
		int mx=0,cur=0,sum=0;
		for(int j=0;j<120&&i+j<=n;j++)
		{
			mx=max(mx,a[i+j]);
			cur^=a[i+j]&1;
			sum+=a[i+j];
			if(!cur&&mx+mx>sum)
				ans--;
		}
	}
	
	printendl(ans);
	return 0;
}