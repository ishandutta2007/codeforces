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

const int maxn=888;

// labels starting from one
template<typename Mat1,typename Mat2>
vector<int> Matroid_Intersection(Mat1&M1,Mat2&M2)
{
	static bool choose[maxn],X1[maxn],X2[maxn],vis[maxn];
	static int pre[maxn];
	static vector<int> g[maxn];
	
	if(!M1.check(vector<int>())||!M2.check(vector<int>()))return vector<int>();
	assert(M1.size()==M2.size());int SZ=M1.size();
	memset(choose,0,sizeof(choose[0])*(SZ+10));
	
	vector<int> I;
	for(int i=1;i<=SZ;i++)if(M1.test(i)&&M2.test(i))
	{
		I.pb(i);
		M1.check(I);
		M2.check(I);
		choose[i]=1;
	}
	
	while(true)
	{
		memset(X1,0,sizeof(X1[0])*(SZ+10));
		memset(X2,0,sizeof(X2[0])*(SZ+10));
		
		vector<int> I;
		for(int i=1;i<=SZ;i++)if(choose[i])I.pb(i);
		
		assert(M1.check(I));
		assert(M2.check(I));
		
		bool update=0;
		for(int i=1;i<=SZ;i++)if(!choose[i])
		{
			X1[i]=M1.test(i);
			X2[i]=M2.test(i);
			if(X1[i]&&X2[i])
			{
				choose[i]=1;
				update=1;
				break;
			}
		}
		
		if(update)continue;
		memset(vis,0,sizeof(vis[0])*(SZ+10));
		for(int i=1;i<=SZ;i++)g[i].clear();
		
		for(auto x:I)
		{
			vector<int>nI;
			for(auto v:I)if(v!=x)nI.push_back(v);
			M1.check(nI);
			M2.check(nI);
			
			for(int i=1;i<=SZ;i++)if(!choose[i])
			{
				if(M2.test(i))g[i].pb(x);
				if(M1.test(i))g[x].pb(i);
			}
		}
		
		queue<int> q;
		for(int i=1;i<=SZ;i++)if(X1[i])
		{
			vis[i]=1;
			pre[i]=0;
			q.push(i);
		}
		
		while(!q.empty())
		{
			int x=q.front();q.pop();
			if(X2[x])
			{
				update=1;
				int cur=x;
				while(cur)
				{
					choose[cur]^=1;
					cur=pre[cur];
				}
				break;
			}
			
			for(int i=0;i<(int)g[x].size();i++)if(!vis[g[x][i]])
			{
				vis[g[x][i]]=1;
				q.push(g[x][i]);
				pre[g[x][i]]=x;
			}
		}
		if(!update)return I;
	}
}

/*
struct Matroid
{
	int SZ;
	int size();
	bool check(vector<int> v);
	bool test(int x);
};

check(v): return [ v is independent ], support test(x) after this check
test(x): let v be last check argument, return [ v + {x} is independent ]
*/

struct Color_Matroid
{
	int col[maxn],lim[maxn],SZ,n;
	int count[maxn];
	inline int size(){return SZ;}
	inline bool check(const vector<int>&v)
	{
		memset(count,0,sizeof(int)*(n+10));
		for(int i=0;i<(int)v.size();i++)
		{
			assert(1<=v[i]&&v[i]<=SZ);
			int c=col[v[i]];
			count[c]++;
			if(count[c]>lim[c])return false;
		}
		return true;
	}
	inline bool test(int x){return count[col[x]]<lim[col[x]];}
}M1;

struct graphic_matroid
{
	int SZ,n,eu[maxn],ev[maxn],f[maxn];
	int size(){return SZ;}
	inline int gf(int x){return x==f[x]?x:f[x]=gf(f[x]);}
	bool check(const vector<int>&es)
	{
		for(int i=1;i<=n;i++)f[i]=i;
		for(auto i:es)
		{
			if(gf(eu[i])==gf(ev[i]))return false;
			f[f[eu[i]]]=f[ev[i]];
		}
		return true;
	}
	bool test(int id){return gf(eu[id])!=gf(ev[id]);}
}M2;

const int N=25;

char s[N][N],t[N*2][N*2];
int n,m,vtot,etot,id[N][N],eid[N][N][2],dgr[N][N],f[maxn];
int gf(int x){return x==f[x]?x:f[x]=gf(f[x]);}
bool choose[maxn];

void solve()
{
	memset(s,0,sizeof(s));
	get2(n,m);for(int i=1;i<=n;i++)scanf("%s",s[i]+1);
	
	memset(id,0,sizeof(id));
	memset(eid,0,sizeof(eid));
	memset(dgr,0,sizeof(dgr));
	memset(M1.lim,0,sizeof(M1.lim));
	
	vtot=etot=0;
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)if(s[i][j]=='O')id[i][j]=++vtot;
	
	M1.n=M2.n=vtot;
	int sum=0;
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)if(s[i][j]=='O'&&(i>1||j>1))
	{
		if((i+j)%2==0)
		{
			sum+=2;
			M1.lim[id[i][j]]=2;
		}
		if(s[i][j+1]=='O')
		{
			eid[i][j][0]=++etot;
			M2.eu[etot]=id[i][j];
			M2.ev[etot]=id[i][j+1];
			if((i+j)%2==0)M1.col[etot]=id[i][j];
			else M1.col[etot]=id[i][j+1];
			dgr[i][j]++;
			dgr[i][j+1]++;
		}
		if(s[i+1][j]=='O')
		{
			eid[i][j][1]=++etot;
			M2.eu[etot]=id[i][j];
			M2.ev[etot]=id[i+1][j];
			if((i+j)%2==0)M1.col[etot]=id[i][j];
			else M1.col[etot]=id[i+1][j];
			dgr[i][j]++;
			dgr[i+1][j]++;
		}
	}
	
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)if(s[i][j]=='O'&&(i>1||j>1)&&(i+j)%2==0&&dgr[i][j]<2)
	{
		puts("NO");
		return;
	}
	
	M1.SZ=M2.SZ=etot;
	
//	M2.debug();
	
	vector<int> ans=Matroid_Intersection(M1,M2);
	if((int)ans.size()<sum)
	{
		puts("NO");
		return;
	}
	puts("YES");
	
	memset(choose,0,sizeof(choose));
	for(int i=1;i<=vtot;i++)f[i]=i;
	for(int i=0;i<sum;i++)
	{
		choose[ans[i]]=1;
		f[gf(M2.eu[ans[i]])]=gf(M2.ev[ans[i]]);
	}
	
	memset(t,0,sizeof(t));
	for(int i=1;i<=n+n-1;i++)for(int j=1;j<=m+m-1;j++)t[i][j]=' ';
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)
	{
		t[i*2-1][j*2-1]=s[i][j];
		if(s[i][j]=='X')continue;
		if(choose[eid[i][j][0]])t[i*2-1][j*2]='O';
		else if(s[i][j+1]=='O'&&gf(id[i][j])!=gf(id[i][j+1]))
		{
			f[gf(id[i][j])]=gf(id[i][j+1]);
			t[i*2-1][j*2]='O';
		}
		
		if(choose[eid[i][j][1]])t[i*2][j*2-1]='O';
		else if(s[i+1][j]=='O'&&gf(id[i][j])!=gf(id[i+1][j]))
		{
			f[gf(id[i][j])]=gf(id[i+1][j]);
			t[i*2][j*2-1]='O';
		}
	}
	for(int i=1;i<=n+n-1;i++)printf("%s\n",t[i]+1);
}

int main()
{
	int tc;
	get1(tc);
	while(tc--)solve();
	return 0;
}