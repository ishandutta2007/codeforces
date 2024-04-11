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

const int magic=300;

int n,a[100111],ord[100111];
bool cmp(int x,int y){return a[x]<a[y];}

bool win[100111],lose[magic+100][magic+100];
int main()
{
	get1(n);
	for(int i=1;i<=n;i++)
	{
		get1(a[i]);
		ord[i]=i;
	}
	sort(ord+1,ord+n+1,cmp);
	reverse(ord+1,ord+n+1);
	for(int i=1;i<=n;i++)
	{
		int x=ord[i];
//		printf("x= %d\n",x);
		if(a[x]>=magic)
		{
			for(int k=(x-1)%a[x]+1;k<=n;k+=a[x])
				if(!win[k]&&a[k]>a[x])
					win[x]=1;
		}
		else win[x]=lose[a[x]][x%a[x]];
		if(!win[x])for(int k=1;k<magic;k++)lose[k][x%k]=1;
	}
	for(int i=1;i<=n;i++)putchar(win[i]?'A':'B');
	return 0;
}