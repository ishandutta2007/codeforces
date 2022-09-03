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

#define div orzfizzydavid
bitset<7111> a[100111],div[7111],mul[7111];
int n,q,mu[7111];
char ans[1000111];

int main()
{
	mu[1]=1;for(int i=1;i<=7000;i++)for(int j=i+i;j<=7000;j+=i)mu[j]-=mu[i];
	for(int i=1;i<=7000;i++)for(int j=i;j<=7000;j+=i)
	{
		div[j].set(i);
		if(mu[j/i])mul[i].set(j);
	}
	
	get2(n,q);
	int tot=0;
	for(int i=1,op,x,y,z;i<=q;i++)
	{
		get1(op);
		if(op==1)
		{
			get2(x,y);
			a[x]=div[y];
		}
		else if(op==2)
		{
			get3(x,y,z);
			a[x]=a[y]^a[z];
		}
		else if(op==3)
		{
			get3(x,y,z);
			a[x]=a[y]&a[z];
		}
		else
		{
			get2(x,y);
			int ret=(a[x]&mul[y]).count()&1;
			ans[++tot]='0'+ret;
		}
	}
	
	printf("%s\n",ans+1);
    return 0;
}