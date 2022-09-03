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

typedef unsigned int uint;
uint qpow(uint x,uint y){uint ret=1;do{if(y&1)ret*=x;x*=x;}while(y>>=1);return ret;}
struct Number
{
	uint k,p;//x = k * 2^p ( k is odd )
	Number(uint x)
	{
		p=0;
		while(~x&1)
		{
			x>>=1;
			p++;
		}
		k=x;
	}
	Number(){k=p=0;}
	Number(uint k1,int k2){k=k1;p=k2;}
	Number operator *(const Number&b){return Number(k*b.k,p+b.p);}
	Number operator /(const Number&b){return Number(k*qpow(b.k,(1u<<31)-1),p-b.p);}
};

const int maxn=233;
uint c[maxn],n,p,q;
int main()
{
	get3(n,p,q);
	Number cur(1);
	for(int i=0;i<=p&&i<n;i++)
	{
		c[i]=cur.k<<cur.p;
		cur=cur*Number(n-i);
		cur=cur/Number(i+1);
	}
	uint ans=0;
	for(int i=1;i<=q;i++)
	{
		uint sum=0,v=1;
		for(int j=0;j<n&&j<=p;j++)
		{
			sum+=v*c[j];
			v*=i;
		}
		ans^=sum*i;
	}
	printendl(ans);
	return 0;
}