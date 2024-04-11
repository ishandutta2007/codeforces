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
 
const int maxn=2511;
pii pp[2511];
pair<long double,int> p[5111];
int n,t1[2511],t2[2511],pre[5111];
bool cmp(const pii&x,const pii&y){return atan2(x.ss,x.ff)<atan2(y.ss,y.ff);}
 
int main()
{
	get1(n);
	for(int i=1;i<=n;i++)get2(pp[i].ff,pp[i].ss);
	
	LL ans=0;
	for(int i=1;i<=n;i++)
	{
		int nn=0;
		for(int j=1;j<=n;j++)if(i!=j)
		{
			p[++nn]=mp(atan2l(pp[j].ss-pp[i].ss,pp[j].ff-pp[i].ff),j);
			p[++nn]=mp(atan2l(pp[i].ss-pp[j].ss,pp[i].ff-pp[j].ff),-j);
		}
		sort(p+1,p+nn+1);
		memset(t1,0,sizeof(t1));
		for(int j=1;j<=nn;j++)
		{
			int id=abs(p[j].ss);
			if(!t1[id])t1[id]=j;else t2[id]=j;
			pre[j]=pre[j-1];
			if(id==p[j].ss)pre[j]++;
		}
		for(int j=1;j<=n;j++)if(i!=j)
		{
			if(t1[j]>t2[j])swap(t1[j],t2[j]);
			int n1=pre[t2[j]]-pre[t1[j]-1]-1,n2=n-2-n1;
			ans+=(LL)n1*(n1-1)+(LL)n2*(n2-1);
		}
	}
	ans/=4;
	ans=(LL)n*(n-1)*(n-2)*(n-3)/6-ans;
	ans=(LL)ans*(n-4)/2;
	printendl(ans);
	return 0;
}