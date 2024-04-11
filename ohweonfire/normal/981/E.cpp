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

int n,q,ql[10111],qr[10111],qv[10111];

vector<int> vl[10111],vr[10111];
bitset<10111>ans;

void solve(int l,int r,const bitset<10111>&cur)
{
	bitset<10111>vv=cur;
	if(l==r)
	{
		for(auto&v:vl[l])if(qr[v]>=r)vv|=(vv<<qv[v]);
		for(auto&v:vr[l])if(ql[v]<r)vv|=(vv<<qv[v]);
		ans|=vv;
		return;
	}
	
	int mid=(l+r)>>1;
	for(int i=l;i<=mid;i++)for(auto&v:vl[i])if(qr[v]>r)
		vv|=(vv<<qv[v]);
	solve(mid+1,r,vv);
	vv=cur;
	for(int i=mid+1;i<=r;i++)for(auto&v:vr[i])if(ql[v]<l)
		vv|=(vv<<qv[v]);
	solve(l,mid,vv);
}
int main()
{
	bitset<10111>vv;vv.set(0);
	get2(n,q);
	for(int i=1;i<=q;i++)
	{
		get3(ql[i],qr[i],qv[i]);
		vl[ql[i]].pb(i);
		vr[qr[i]].pb(i);
	}
	solve(1,n,vv);
	int cnt=0;
	for(int i=1;i<=n;i++)cnt+=ans.test(i);
	printendl(cnt);
	for(int i=1;i<=n;i++)if(ans[i])printf("%d ",i);
	return 0;
}