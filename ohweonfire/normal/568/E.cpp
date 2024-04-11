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

int n,a[100111];

int timer;
struct bit
{
	int tag[200111];
	pii v[200111];
	void add(int x,pii val)
	{
		for(x;x<200111;x+=x&-x)
		{
			if(tag[x]!=timer)
			{
				tag[x]=timer;
				v[x]=mp(-10000000,0);
			}
			v[x]=max(v[x],val);
		}
	}
	pii query(int x)
	{
		pii ret=mp(-10000000,0);
		for(;x;x-=x&-x)
			if(tag[x]==timer)ret=max(ret,v[x]);
		return ret;
	}
}front,back;

int f[100111],cntpre[200111],pospre[100111],pre[100111];

void update(int p,pii v,int add)
{
	if(f[p]<v.ff+add)
	{
		f[p]=v.ff+add;
		pre[p]=v.ss;
	}
}

void solve(int l,int r)
{
	if(l==r)
	{
		if(!f[l])
		{
			f[l]=1;
			pre[l]=0;
		}
		return;
	}
	int mid=(l+r)>>1;
	solve(l,mid);
	
	vector<int>v;vector<pair<int,int> >v2;v.push_back(-10000000);
	for(int i=l;i<=mid;i++)if(a[i])
	{
		v.push_back(cntpre[a[i]]-pospre[i]);
		v2.push_back(make_pair(a[i],-i));
	}
	for(int i=mid+1;i<=r;i++)if(a[i])
	{
		v.push_back(cntpre[a[i]-1]-pospre[i-1]);
		v2.push_back(make_pair(a[i],-i));
	}
	sort(v.begin(),v.end());sort(v2.begin(),v2.end());
	timer++;int sz=(int)v.size();
	for(int i=0;i<(int)v2.size();i++)
	{
		int p=-v2[i].second;
		if(p<=mid)
		{
			int id=lower_bound(v.begin(),v.end(),cntpre[a[p]]-pospre[p])-v.begin();
			front.add(id,mp(f[p]-pospre[p],p));
			back.add(sz-id+1,mp(f[p]-cntpre[a[p]],p));
		}
		else
		{
			int id=lower_bound(v.begin(),v.end(),cntpre[a[p]-1]-pospre[p-1])-v.begin();
			update(p,front.query(id-1),pospre[p-1]+1);
			update(p,back.query(sz-id+1),cntpre[a[p]-1]+1);
//			f[p]=max(f[p],max(front.query(id-1)+pospre[p-1],back.query(sz-id+1)+cntpre[a[p]-1])+1);
		}
	}
	
	solve(mid+1,r);
}

int m,b[100111];

void go(int v)
{
	if(v==1)return;
	int u=pre[v],cur=a[u]+1;
	go(u);
//	printf("u= %d v= %d lv= %d rv= %d\n",u,v,a[u],a[v]);
	for(int i=u+1;i<v;i++)if(!a[i])
	{
		while(cur<a[v]&&!cntpre[cur])cur++;
		if(cur==a[v])break;
		a[i]=cur;
		cntpre[cur]--;cur++;
	}
}

int main()
{
	scanf("%d",&n);
	for(int i=2;i<=n+1;i++)scanf("%d",a+i);
	n+=2;
	a[1]=0;a[n]=1000000001;
	
	scanf("%d",&m);
	for(int i=1;i<=m;i++)scanf("%d",b+i);
	
	vector<int> vs;vs.pb(-1);
	for(int i=1;i<=n;i++)vs.pb(a[i]);
	for(int i=1;i<=m;i++)vs.pb(b[i]);
	sort(vs.begin(),vs.end());vs.erase(unique(vs.begin(),vs.end()),vs.end());
	for(int i=1;i<=n;i++)a[i]=lower_bound(vs.begin(),vs.end(),a[i])-vs.begin();
	for(int i=1;i<=m;i++)b[i]=lower_bound(vs.begin(),vs.end(),b[i])-vs.begin();
	
	int sz=(int)vs.size();
	for(int i=1;i<=m;i++)cntpre[b[i]]=1;
	for(int i=1;i<=sz;i++)cntpre[i]+=cntpre[i-1];
	for(int i=1;i<=n;i++)pospre[i]=pospre[i-1]+(a[i]==0);
	
	solve(1,n);
	memset(cntpre,0,sizeof(cntpre));
	for(int i=1;i<=m;i++)cntpre[b[i]]++;
	go(n);
	int cur=0;
	for(int i=1;i<=n;i++)if(!a[i])
	{
		while(!cntpre[cur])cur++;
		cntpre[cur]--;
		a[i]=cur;
	}
//	for(int i=1;i<=n;i++)printf("i= %d f= %d\n",i,f[i]);
//	printf("hehe %d\n",f[n]-2);
	for(int i=2;i<n;i++)printf("%d ",vs[a[i]]);puts("");
	return 0;
}