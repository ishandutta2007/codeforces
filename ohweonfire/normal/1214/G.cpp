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

const int maxn=2111;

int n,m,q,cnt[maxn];
bitset<maxn> a[maxn],flip_v[maxn];
bool have[maxn][maxn];
set<pii> st,need;

void add_pair(int u,int v)
{
	have[u][v]=((a[v]&a[u])!=a[u]);
	if(have[u][v])need.insert(mp(u,v));
}
void del_pair(int u,int v)
{
	if(have[u][v])need.erase(mp(u,v));
	have[u][v]=0;
}
void delline(int x)
{
	auto it=st.find(mp(cnt[x],x));
	int pre=0,nxt=0;
	if(it!=st.begin())
	{
		it--;
		pre=it->ss;
		it++;
	}
	it++;
	if(it!=st.end())nxt=it->ss;
	it--;
	
	if(pre)del_pair(pre,x);
	if(nxt)del_pair(x,nxt);
	if(pre&&nxt)add_pair(pre,nxt);
	st.erase(it);
}

void addline(int x)
{
	st.insert(mp(cnt[x],x));
	auto it=st.find(mp(cnt[x],x));
	int pre=0,nxt=0;
	if(it!=st.begin())
	{
		it--;
		pre=it->ss;
		it++;
	}
	it++;
	if(it!=st.end())nxt=it->ss;
	it--;
	
	if(pre&&nxt)del_pair(pre,nxt);
	if(pre)add_pair(pre,x);
	if(nxt)add_pair(x,nxt);
}

void getans(int u,int v)
{
	if(u>v)swap(u,v);
	int k1=(a[u]&~a[v])._Find_first(),k2=(a[v]&~a[u])._Find_first();
	if(k1>k2)swap(k1,k2);
	printf("%d %d %d %d\n",u,k1,v,k2);
}

int main()
{
	get3(n,m,q);
	for(int i=1;i<=n;i++)addline(i);
	for(int i=1;i<=m;i++)for(int j=1;j<=i;j++)flip_v[i].set(j);
	for(int i=1,x,l,r;i<=q;i++)
	{
		get3(x,l,r);
		delline(x);
		a[x]^=flip_v[r]^flip_v[l-1];
		cnt[x]=a[x].count();
		addline(x);
		if(need.size()==0)puts("-1");
		else getans(need.begin()->ff,need.begin()->ss);
	}
	return 0;
}