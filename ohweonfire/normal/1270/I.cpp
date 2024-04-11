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

int k;
LL a[1<<9][1<<9],b[1<<9][1<<9],c[1<<9][1<<9];
int t,x[100],y[100];

void mult(LL a[1<<9][1<<9],LL b[1<<9][1<<9])
{
	static int vx[100],vy[100];
	int tot=0;
	for(int i=0;i<(1<<k);i++)for(int j=0;j<(1<<k);j++)if(b[i][j])
	{
		vx[tot]=i;vy[tot]=j;
		tot++;
	}
	
	memset(c,0,sizeof(c));
	for(int i=0;i<(1<<k);i++)for(int j=0;j<(1<<k);j++)for(int t=0;t<tot;t++)
		c[(i+vx[t])&((1<<k)-1)][(j+vy[t])&((1<<k)-1)]^=(a[i][j]&b[vx[t]][vy[t]]);
	memcpy(a,c,sizeof(c));
}
void sq(LL a[1<<9][1<<9])
{
	static int vx[100],vy[100];
	memset(c,0,sizeof(c));
	for(int i=0;i<(1<<k);i++)for(int j=0;j<(1<<k);j++)c[(i<<1)&((1<<k)-1)][(j<<1)&((1<<k)-1)]^=a[i][j];
	memcpy(a,c,sizeof(c));
}

int main()
{
	get1(k);
	for(int i=0;i<(1<<k);i++)for(int j=0;j<(1<<k);j++)get1(a[i][j]);
	get1(t);
	for(int i=0;i<t;i++)
	{
		get2(x[i],y[i]);
		x[i]--;y[i]--;
	}
	for(int i=t-1;i>=0;i--)
	{
		x[i]+=(1<<k)-x[0];
		y[i]+=(1<<k)-y[0];
		x[i]&=(1<<k)-1;
		y[i]&=(1<<k)-1;
		b[x[i]][y[i]]=(1ll<<60)-1;
	}
	
	for(int p=0;p<k;p++)
	{
		mult(a,b);
		sq(b);
	}
	int ans=0;
	for(int i=0;i<(1<<k);i++)for(int j=0;j<(1<<k);j++)if(a[i][j])ans++;
	printendl(ans);
	return 0;
}