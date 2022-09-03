// This amazing code is by Eric Sunli Chen.
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>
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

int n,m,q,cl,ce,v;
int a[100111],b[100111];
int main()
{
	get2(n,m);get3(cl,ce,v);
	for(int i=1;i<=cl;i++)get1(a[i]);
	for(int i=1;i<=ce;i++)get1(b[i]);
	get1(q);
	for(int i=1,x,y,xx,yy;i<=q;i++)
	{
		get2(x,y);get2(xx,yy);swap(x,y);swap(xx,yy);
		int ans=inf,lid=lower_bound(a+1,a+cl+1,x)-a,eid=lower_bound(b+1,b+ce+1,x)-b;
		if(y==yy)ans=abs(x-xx);
		
		if(lid<=cl)ans=min(ans,abs(x-a[lid])+abs(xx-a[lid])+abs(y-yy));
		lid--;
		if(lid)ans=min(ans,abs(x-a[lid])+abs(xx-a[lid])+abs(y-yy));
		if(eid<=ce)ans=min(ans,abs(x-b[eid])+abs(xx-b[eid])+(abs(y-yy)+v-1)/v);
		eid--;
		if(eid)ans=min(ans,abs(x-b[eid])+abs(xx-b[eid])+(abs(y-yy)+v-1)/v);
		
		lid=lower_bound(a+1,a+cl+1,xx)-a;eid=lower_bound(b+1,b+ce+1,xx)-b;
		if(lid<=cl)ans=min(ans,abs(x-a[lid])+abs(xx-a[lid])+abs(y-yy));
		lid--;
		if(lid)ans=min(ans,abs(x-a[lid])+abs(xx-a[lid])+abs(y-yy));
		if(eid<=ce)ans=min(ans,abs(x-b[eid])+abs(xx-b[eid])+(abs(y-yy)+v-1)/v);
		eid--;
		if(eid)ans=min(ans,abs(x-b[eid])+abs(xx-b[eid])+(abs(y-yy)+v-1)/v);
		printf("%d\n",ans);
	}
	return 0;
}