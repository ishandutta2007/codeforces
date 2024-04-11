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
typedef vector<int> vi;
const int inf=0x3f3f3f3f;
const LL Linf=1ll<<61;
const double pi=acos(-1.0);

const int maxn=1000111;
int n,a[maxn],mark[maxn];

void solve()
{
	get1(n);
	for(int i=1;i<=n;i++)
	{
		get1(a[i]);
		a[i]=i-a[i];
		mark[i]=0;
	}
	vector<int> ans;
	for(int i=1;i<=n;i++)if(!mark[i])
	{
		int tmp=i;
		while(!mark[tmp])
		{
			mark[tmp]=i;
			tmp=a[tmp];
		}
		if(mark[tmp]==i)
		{
			int ttmp=a[tmp];ans.pb(tmp);
			while(ttmp!=tmp)
			{
				ans.pb(ttmp);
				ttmp=a[ttmp];
			}
			printf("%d\n",(int)ans.size());
			for(int j=0;j<(int)ans.size();j++)printf("%d ",ans[j]);puts("");
			return;
		}
	}
}

int main()
{
	int tc;
	get1(tc);
	while(tc--)solve();
	return 0;
}