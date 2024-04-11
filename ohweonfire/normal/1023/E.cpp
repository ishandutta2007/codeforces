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

int n;

char s[10];
bool query(int x,int y,int xx,int yy)
{
	if(x<1||y<1||xx>n||yy>n||x>xx||y>yy)return false;
	if(x==1&&y==1&&xx==n&&yy==n)return true;
	printf("? %d %d %d %d\n",x,y,xx,yy);fflush(stdout);
	scanf("%s",s);
	if(s[0]=='A')exit(0);
	return s[0]=='Y';
}

int main()
{
	get1(n);
	
	pii piv;
	for(int i=1;i<=n;i++)
	{
		if(query(1,1,i,n-i+1)&&query(i,n-i+1,n,n))
		{
			piv=mp(i,n-i+1);
			break;
		}
	}
	
	vector<pii>ansl,ansr,ans;
	pii tmp=mp(1,1);
	while(tmp!=piv)
	{
		ansl.pb(tmp);
		if(query(tmp.ff,tmp.ss+1,n,n))tmp.ss++;
		else tmp.ff++;
	}
	
	tmp=mp(n,n);
	while(tmp!=piv)
	{
		ansr.pb(tmp);
		if(query(1,1,tmp.ff-1,tmp.ss))tmp.ff--;
		else tmp.ss--;
	}
	
	for(int i=0;i<(int)ansl.size();i++)ans.pb(ansl[i]);
	ans.pb(piv);
	for(int i=(int)ansr.size()-1;i>=0;i--)ans.pb(ansr[i]);
	
	printf("! ");
	for(int i=1;i<(int)ans.size();i++)if(ans[i].ff==ans[i-1].ff)putchar('R');else putchar('D');
	
	puts("");fflush(stdout);
	
	return 0;
}