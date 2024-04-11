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

const int maxn=3111;
int r,c,n,k,x[maxn],y[maxn];
vector<int> have[maxn];
int cnt[maxn],pre[maxn],nxt[maxn];

int remove(int id)
{
	static int vl[15],vr[15],sl[15],sr[15];
	int cl=0,cr=0,cur=y[id];
	sl[0]=sr[0]=0;
	for(cl=1;cl<=k&&cur;cl++,cur=pre[cur])
	{
		vl[cl]=cur;
		sl[cl]=sl[cl-1]+cnt[cur];
	}
	cl--;
	cur=y[id];
	for(cr=1;cr<=k&&cur;cr++,cur=nxt[cur])
	{
		vr[cr]=cur;
		sr[cr]=sr[cr-1]+cnt[cur];
	}
	cr--;
	
//	printf("id= %d\n",id);
//	printf("cl= %d cr= %d\n",cl,cr);
//	for(int i=1;i<=cl;i++)printf("%d ",vl[i]);puts("");
//	for(int i=1;i<=cr;i++)printf("%d ",vr[i]);puts("");
	
	int ret=0;cur=1;
	for(int i=cl;i>=1;i--)
	{
		while(cur<=cr&&sl[i]+sr[cur]-cnt[y[id]]<k)cur++;
//		printf("i= %d cur= %d sum= %d\n",i,cur,sl[i]+sr[cur]-cnt[y[id]]);
		if(cur<=cr&&sl[i]+sr[cur]-cnt[y[id]]==k)
		{
//			printf("l= %d %d r= %d %d\n",vl[i],pre[vl[i]],vr[cur],nxt[vr[cur]]);
			ret+=(vl[i]-pre[vl[i]])*(nxt[vr[cur]]-vr[cur]);
		}
	}
	
	cnt[y[id]]--;
	if(cnt[y[id]]==0)
	{
		int lv=pre[y[id]],rv=nxt[y[id]];
		nxt[lv]=rv;pre[rv]=lv;
	}
	return ret;
}

int main()
{
	get2(r,c);get2(n,k);
	for(int i=1;i<=n;i++)
	{
		get2(x[i],y[i]);
		have[x[i]].pb(i);
	}
	
	LL ans=0;
	for(int i=1;i<=r;i++)
	{
		for(int j=1;j<=n;j++)if(x[j]>=i)cnt[y[j]]++;
		int last=0;
		for(int j=1;j<=c;j++)if(cnt[j])
		{
			if(last)nxt[last]=j;
			pre[j]=last;
			last=j;
		}
		nxt[last]=c+1;
		int sum=0;
		for(int ii=r;ii>=i;ii--)
		{
			int sum=0;
			for(auto v:have[ii])sum+=remove(v);
			ans+=(LL)sum*(r-ii+1);
		}
	}
	printendl(ans);
	return 0;
}