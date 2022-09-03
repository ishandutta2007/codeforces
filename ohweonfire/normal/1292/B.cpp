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

LL sx,sy,x,y,ax,ay,bx,by,t;
int main()
{
	get2(x,y);get2(ax,ay);get2(bx,by);
	get3(sx,sy,t);
	
	vector<pair<LL,LL> >vs;
	while(abs(x)+abs(y)<=t+sx+sy)
	{
		vs.pb(mp(x,y));
		x=x*ax+bx;
		y=y*ay+by;
	}
	
	int ans=0;
	for(int l=0;l<(int)vs.size();l++)for(int r=0;r<(int)vs.size();r++)
	{
		LL curt=abs(sx-vs[l].ff)+abs(sy-vs[l].ss);
		curt+=abs(vs[l].ff-vs[r].ff)+abs(vs[l].ss-vs[r].ss);
		if(curt<=t)ans=max(ans,max(r-l+1,l-r+1));
	}
	printendl(ans);
	return 0;
}