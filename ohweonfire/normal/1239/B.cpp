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

const int maxn=300111;
int n,a[maxn],pos[maxn];
char s[maxn],t[maxn];

int main()
{
	get1(n);scanf("%s",s+1);
	for(int i=1;i<=n;i++)
	{
		a[i]=a[i-1];
		if(s[i]=='(')a[i]++;
		else a[i]--;
	}
	if(a[n])
	{
		puts("0");
		puts("1 1");
		return 0;
	}
	int shift=min_element(a+1,a+n+1)-a,tot=0;
	for(int i=shift+1;i<=n;i++)
	{
		t[++tot]=s[i];
		pos[tot]=i;
	}
	for(int i=1;i<=shift;i++)
	{
		t[++tot]=s[i];
		pos[tot]=i;
	}
	for(int i=1;i<=n;i++)
	{
		a[i]=a[i-1];
		if(t[i]=='(')a[i]++;
		else a[i]--;
	}
	pair<int,pii> ans=mp(0,mp(1,1));
	
	//min = 0
	int last=0,cnt=0,all=0;
	for(int i=1;i<=n;i++)if(a[i]==0)all++;
	for(int i=1;i<=n;i++)
	{
		if(a[i]==2)cnt++;
		if(a[i]<=1)
		{
			ans=max(ans,mp(cnt+all,mp(last+1,i)));
			last=i;
			cnt=0;
		}
	}
	
	//min = -1
	last=cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]==1)cnt++;
		if(a[i]==0)
		{
			ans=max(ans,mp(cnt,mp(last+1,i)));
			last=i;
			cnt=0;
		}
	}
	
	printf("%d\n%d %d\n",ans.ff,pos[ans.ss.ff],pos[ans.ss.ss]);
	return 0;
}