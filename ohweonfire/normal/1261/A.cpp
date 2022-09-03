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

int n,k;
char s[2111];
vector<pii>cmd;

void find(int l,char v)
{
	for(int i=l;i<=n;i++)if(s[i]==v)
	{
		cmd.pb(mp(l,i));
		reverse(s+l,s+i+1);
		break;
	}
}

void solve()
{
	cmd.clear();
	scanf("%d%d%s",&n,&k,s+1);
	int tot=0;
	for(int i=1;i<k;i++)
	{
		find(++tot,'(');
		find(++tot,')');
	}
	for(int i=k;i<=n/2;i++)find(++tot,'(');
	for(int i=k;i<=n/2;i++)find(++tot,')');
	printf("%d\n",(int)cmd.size());
	for(int i=0;i<(int)cmd.size();i++)printf("%d %d\n",cmd[i].ff,cmd[i].ss);
}
int main()
{
	int tc;get1(tc);
	while(tc--)solve();
	return 0;
}