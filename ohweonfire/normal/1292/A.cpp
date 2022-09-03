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

const int maxn=1000111;

int n,q,a[2][maxn],tot;

void add(int x)
{
	for(int i=0;i<2;i++)if(a[i][x]&&a[i][x+1])
	{
		tot++;
		return;
	}
}

void remove(int x)
{
	for(int i=0;i<2;i++)if(a[i][x]&&a[i][x+1])
	{
		tot--;
		return;
	}
}

int main()
{
	get2(n,q);
	tot=n-1;
	for(int i=0;i<2;i++)for(int j=1;j<=n;j++)a[i][j]=1;
	for(int i=1,r,c;i<=q;i++)
	{
		get2(r,c);r--;
		if(c>1)remove(c-1);
		if(c<n)remove(c);
		a[r][c]^=1;
		if(c>1)add(c-1);
		if(c<n)add(c);
		puts(tot==n-1?"Yes":"No");
	}
	return 0;
}