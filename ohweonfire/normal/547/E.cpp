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

const int maxn=500111;

int sv[maxn];
struct suffix_array
{
	int sa[maxn],t[maxn],t2[maxn],c[maxn],n;
	int rk[maxn],v[20][maxn],lg[maxn];
	void construct_sa()
	{
		vector<int> all;for(int i=0;i<n;i++)all.pb(sv[i]);
		sort(all.begin(),all.end());all.erase(unique(all.begin(),all.end()),all.end());
		
		int m=all.size();
		for(int i=0;i<n;i++)sv[i]=lower_bound(all.begin(),all.end(),sv[i])-all.begin();
		
		int *x=t,*y=t2;
		for(int i=0;i<m;i++)c[i]=0;
		for(int i=0;i<n;i++)c[x[i]=sv[i]]++;
		for(int i=1;i<m;i++)c[i]+=c[i-1];
		for(int i=n-1;i>=0;i--)sa[--c[x[i]]]=i;
		
		for(int k=1;k<=n;k<<=1)
		{
			int p=0;
			for(int i=n-k;i<n;i++)y[p++]=i;
			for(int i=0;i<n;i++)if(sa[i]>=k)y[p++]=sa[i]-k;
			for(int i=0;i<m;i++)c[i]=0;
			for(int i=0;i<n;i++)c[x[y[i]]]++;
			for(int i=1;i<m;i++)c[i]+=c[i-1];
			for(int i=n-1;i>=0;i--)sa[--c[x[y[i]]]]=y[i];
			swap(x,y);
			x[sa[0]]=0;p=1;
			for(int i=1;i<n;i++)x[sa[i]]=(y[sa[i]]==y[sa[i-1]]&&y[sa[i]+k]==y[sa[i-1]+k])?p-1:p++;
			if(p>=n)break;
			m=p;
		}
	}
	void construct_lcp()
	{
		int k=0;
		for(int i=0;i<n;i++)rk[sa[i]]=i;
		for(int i=0;i<n-1;i++)
		{
			if(k)k--;
			int j=sa[rk[i]-1];
			while(sv[i+k]==sv[j+k])k++;
			v[0][rk[i]]=k;
		}
		for(int i=2;i<n;i++)lg[i]=lg[i>>1]+1;
		for(int i=1;i<20;i++)
		{
			for(int j=2;j<n;j++)
			{
				int nxt=j+(1<<i-1);
				if(nxt>=n)v[i][j]=v[i-1][j];
				else v[i][j]=min(v[i-1][j],v[i-1][nxt]);
			}
		}
	}
	int qlcp(int l,int r)
	{
		if(l==r)return n-l;
		l=rk[l];
		r=rk[r];
		if(l>r)swap(l,r);l++;
		int t=lg[r-l+1];
		return min(v[t][l],v[t][r-(1<<t)+1]);
	}
	void get_bound(int v,int len,int &lb,int &ub)
	{
		v=rk[v];
		int l=0,r=v,mid;
		while(l<r-1)
		{
			mid=(l+r)>>1;
			if(qlcp(sa[mid],sa[v])>=len)r=mid;else l=mid;
		}
		lb=r;
		l=v;r=n;
		while(l<r-1)
		{
			mid=(l+r)>>1;
			if(qlcp(sa[mid],sa[v])>=len)l=mid;else r=mid;
		}
		ub=l;
	}
}sa;

int bit[200111];
void add(int x,int v){for(;x<200111;x+=x&-x)bit[x]+=v;}
int query(int x){int ret=0;for(;x;x-=x&-x)ret+=bit[x];return ret;}

vector<int> vadd[maxn],vsub[maxn];
char s[maxn];
int n,q,lb[maxn],rb[maxn],tot,pos[maxn];
int lv[maxn],rv[maxn],ql[maxn],qr[maxn],ans[maxn];

int main()
{
	get2(n,q);
	
	tot=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s);
		lb[i]=tot;
		for(int j=0;s[j];j++)
		{
			pos[tot]=i;
			sv[tot++]=s[j]-'a'+1;
		}
		rb[i]=tot-1;
		sv[tot++]=i+27;
	}
//	for(int i=0;i<tot;i++)printf("%d ",sv[i]);puts("");
	sa.n=tot+1;
	sa.construct_sa();
	sa.construct_lcp();
	
	for(int i=1,k;i<=q;i++)
	{
		get2(ql[i],qr[i]);get1(k);
		sa.get_bound(lb[k],rb[k]-lb[k]+1,lv[i],rv[i]);
		if(lv[i])vsub[lv[i]-1].pb(i);
		vadd[rv[i]].pb(i);
	}
	
	for(int i=0;i<tot;i++)
	{
		if(pos[sa.sa[i]])add(pos[sa.sa[i]],1);
		for(auto v:vadd[i])ans[v]+=query(qr[v])-query(ql[v]-1);
		for(auto v:vsub[i])ans[v]-=query(qr[v])-query(ql[v]-1);
	}
	for(int i=1;i<=q;i++)printendl(ans[i]);
	
	return 0;
}