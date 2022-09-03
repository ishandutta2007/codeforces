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

const int maxn=100111;

int k,n,m,a[maxn],op[maxn];
vector<pii> add[maxn],mult[maxn],assign[maxn];

vector<pair<pair<LL,LL>,int> >all;
bool cmp(const pair<pair<LL,LL>,int>&a,const pair<pair<LL,LL>,int>&b){return (a.ff.ff*b.ff.ss>b.ff.ff*a.ff.ss);}
bool cmp2(int x,int y){return op[x]<op[y];}

int main()
{
	get3(k,n,m);
	for(int i=1;i<=k;i++)get1(a[i]);
	for(int i=1,tp,x,y;i<=n;i++)
	{
		get3(tp,x,y);op[i]=tp;
		if(tp==1)assign[x].pb(mp(y,i));
		else if(tp==2)add[x].pb(mp(y,i));
		else mult[x].pb(mp(y,i));
	}
	for(int x=1;x<=k;x++)
	{
		sort(assign[x].begin(),assign[x].end(),greater<pii>());
		for(auto v:assign[x])
		{
			if(v.ff>a[x])add[x].pb(mp(v.ff-a[x],v.ss));
			break;
		}
		sort(add[x].begin(),add[x].end(),greater<pii>());
		sort(mult[x].begin(),mult[x].end(),greater<pii>());
		
		LL sum=a[x];
		for(auto v:add[x])
		{
			all.pb(mp(mp(v.ff,sum),v.ss));
			sum+=v.ff;
		}
		for(auto v:mult[x])
		{
			if(v.ff>1)all.pb(mp(mp(v.ff-1,1),v.ss));
		}
	}
	sort(all.begin(),all.end(),cmp);
	vector<int> ans;
	for(int i=0;i<m&&i<(int)all.size();i++)ans.pb(all[i].ss);
	sort(ans.begin(),ans.end(),cmp2);
	printf("%d\n",(int)ans.size());
	for(int i=0;i<(int)ans.size();i++)printf("%d%c",ans[i],i==(int)ans.size()-1?'\n':' ');
	return 0;
}