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

const int maxn=300111;

const int mod1=998244353;
const int mod2=1e9+7;
const int mod3=1e9+9;
const int base1=1042314;
const int base2=5135489;
const int base3=58437289;

int n,a[maxn];

pair<int,pii> hsv[maxn];
int top,stk[maxn];

void solve()
{
	get1(n);for(int i=1;i<=n;i++)get1(a[i]);
	top=0;
	map<pair<int,pii>,int> cnt;
	cnt[mp(0,mp(0,0))]++;
	LL ans=0;
	for(int i=1;i<=n;i++)
	{
		if(top&&a[i]==stk[top])top--;
		else
		{
			int h1=hsv[top].ff,h2=hsv[top].ss.ff,h3=hsv[top].ss.ss;
			h1=((LL)h1*base1+a[i])%mod1;
			h2=((LL)h2*base2+a[i])%mod2;
			h3=((LL)h3*base3+a[i])%mod3;
			hsv[++top]=mp(h1,mp(h2,h3));
			stk[top]=a[i];
		}
		ans+=cnt[hsv[top]];
		cnt[hsv[top]]++;
	}
	printendl(ans);
}

int main()
{
	int tc;get1(tc);while(tc--)solve();
	return 0;
}