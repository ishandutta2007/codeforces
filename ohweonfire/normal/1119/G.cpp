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

const int maxn=1000111;

int n,m,hp[maxn],sum,ans;

int a[maxn];

int main()
{
	get2(n,m);
	
	vector<int> vs;
	for(int i=1;i<=m;i++)
	{
		get1(hp[i]);
		sum+=hp[i];
		if(i!=m&&sum%n)vs.pb(sum%n);
	}
	
	ans=(sum+n-1)/n;
	
	vs.pb(0);vs.pb(n);
	sort(vs.begin(),vs.end());
	vs.erase(unique(vs.begin(),vs.end()),vs.end());
	
	for(int i=1;i<(int)vs.size();i++)
		a[i]=vs[i]-vs[i-1];
	
	printf("%d\n",ans);
	for(int i=1;i<=m;i++)printf("%d ",a[i]);puts("");
	
	int cur=1;
	for(int i=1;i<=ans;i++)
	{
		for(int j=1;j<=m;j++)
		{
			hp[cur]-=a[j];
			printf("%d ",min(cur,m));
			while(cur<=m&&hp[cur]<=0)cur++;
		}
		puts("");
	}
	
	if(cur<=m)puts("baojing");
	return 0;
}