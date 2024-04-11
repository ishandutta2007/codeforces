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

int n,k;
pii ask(const vector<int>&v)
{
	assert(v.size()==k);
	printf("?");for(int i=0;i<(int)v.size();i++)printf(" %d",v[i]);
	puts("");fflush(stdout);
	int a,b;get2(a,b);
	return mp(a,b);
}

pii ans[555];
int main()
{
	get2(n,k);n=k+1;
	
	for(int i=1;i<=n;i++)
	{
		vector<int> v;
		for(int j=1;j<=n;j++)if(i!=j)v.pb(j);
		ans[i]=ask(v);
	}
	pii piv1=ans[1],piv2;int cnt=1;
	for(int i=2;i<=n;i++)if(ans[i]!=ans[1])piv2=ans[i];else cnt++;
	if(piv1.ss>piv2.ss)printf("! %d\n",cnt);
	else printf("! %d\n",n-cnt);
	
	return 0;
}