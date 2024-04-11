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

#define pow yjzakioi2019
int qpow(int x,int y,int p)
{
	int ret=1;
	while(y)
	{
		if(y&1)ret=(LL)ret*x%p;
		x=(LL)x*x%p;
		y>>=1;
	}
	return ret;
}

int chk[5555],d,p,tot;
void add(int a,int b,int c)
{
#ifndef EEEEEericKKK
	printf("+ %d %d %d\n",a,b,c);
#else
	chk[c]=(chk[a]+chk[b])%p;
	tot++;
#endif
}
void pow(int a,int b)
{
#ifndef EEEEEericKKK
	printf("^ %d %d\n",a,b);
#else
	chk[b]=qpow(chk[a],d,p);
	tot++;
#endif
}


void addto(int s,int k,int t)
{
	if(k<0)k+=p;if(k>=p)k-=p;
	while(k)
	{
		if(k&1)add(s,t,t);
		k>>=1;
		if(k)add(s,s,s);
	}
}
void mult(int s,int k,int t)
{
	add(s,s,t);
	addto(s,k-2,t);
}

int a[12][12],b[12][12],c[12][12];
void gauss(int n)
{
	for(int i=0;i<n;i++)
	{
		if(!a[i][i])
		{
			for(int j=i+1;j<n;j++)if(a[j][i])
			{
				for(int k=0;k<n;k++)swap(a[i][k],a[j][k]);
				for(int k=0;k<n;k++)swap(b[i][k],b[j][k]);
				break;
			}
		}
		if(!a[i][i])puts("baojing");
		
		int rv=qpow(a[i][i],p-2,p);
		for(int j=0;j<n;j++)a[i][j]=(LL)a[i][j]*rv%p;
		for(int j=0;j<n;j++)b[i][j]=(LL)b[i][j]*rv%p;
		
		for(int j=0;j<n;j++)if(i!=j)
		{
			int coef=(p-a[j][i])%p;
			for(int k=0;k<n;k++)a[j][k]=(a[j][k]+(LL)a[i][k]*coef)%p;
			for(int k=0;k<n;k++)b[j][k]=(b[j][k]+(LL)b[i][k]*coef)%p;
		}
	}
}

int one=4,tmp=5;
void getsqr(int s,int t)
{
	pow(s,tmp);
	mult(tmp,b[2][0],t);
	for(int i=1;i<=d;i++)
	{
		add(s,one,s);
		pow(s,tmp);
		addto(tmp,b[2][i],t);
	}
}

int main()
{
//	chk[1]=233;chk[2]=666;
//	for(int i=3;i<=5000;i++)chk[i]=1;
	get2(d,p);
	for(int i=0;i<=d;i++)
	{
		c[i][0]=1;
		for(int j=1;j<=i;j++)c[i][j]=(c[i-1][j]+c[i-1][j-1])%p;
	}
	for(int i=0;i<=d;i++)
	{
		int prod=1;
		for(int j=d;j>=0;j--)
		{
			a[i][j]=(LL)c[d][j]*prod%p;
			prod=(LL)prod*i%p;
		}
		b[i][i]=1;
	}
	gauss(d+1);
	
	add(1,2,3);
	getsqr(1,5000);getsqr(2,4999);getsqr(3,4998);
	
	addto(5000,-1,4998);
	addto(4999,-1,4998);
	mult(4998,(p+1)/2,4997);
	
#ifndef EEEEEericKKK
	puts("f 4997");
#else
	printf("tot= %d\n",tot);
#endif
	return 0;
}