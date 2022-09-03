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

const int maxn=100111;
char s[maxn],t[3][maxn];

int n,q,l[3],nxt[maxn][26];

int val[311][311][311];

void recalc(int u,int v,int w)
{
	int nv=n+1;
	if(u)nv=min(nv,nxt[min(n,val[u-1][v][w])+1][t[0][u]-'a']);
	if(v)nv=min(nv,nxt[min(n,val[u][v-1][w])+1][t[1][v]-'a']);
	if(w)nv=min(nv,nxt[min(n,val[u][v][w-1])+1][t[2][w]-'a']);
	val[u][v][w]=nv;
}

int main()
{
	scanf("%d%d",&n,&q);
	
	scanf("%s",s+1);
	for(int i=0;i<26;i++)nxt[n+1][i]=n+1;
	for(int i=n;i>=1;i--)
	{
		memcpy(nxt[i],nxt[i+1],sizeof(nxt[i]));
		nxt[i][s[i]-'a']=i;
	}
	
	char op[5],opv[5];int id;
	
	while(q--)
	{
		scanf("%s%d",op,&id);id--;
		if(op[0]=='-')l[id]--;
		else
		{
			scanf("%s",opv);
			t[id][++l[id]]=opv[0];
			
			int lb[3]={0,0,0},rb[3]={l[0],l[1],l[2]};
			lb[id]=rb[id]=l[id];
			
			for(int t0=lb[0];t0<=rb[0];t0++)for(int t1=lb[1];t1<=rb[1];t1++)
			for(int t2=lb[2];t2<=rb[2];t2++)recalc(t0,t1,t2);
		}
		if(val[l[0]][l[1]][l[2]]<=n)puts("YES");
		else puts("NO");
	}
	return 0;
}