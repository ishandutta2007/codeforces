// This amazing code is by Eric Sunli Chen.
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iomanip>
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

int n,q;
LL l[100111],t[100111],sum[100111],ans[100111],g,r,c;
bool cmp(int x,int y){return (c-t[x]%c+c)%c<(c-t[y]%c+c)%c;}

set<pair<int,pii> >st;

void addseg(pii x,LL v){sum[x.ff]+=v;sum[x.ss+1]-=v;if(x.ff>x.ss)sum[1]+=v;}
pii combine(pii a,pii b)
{
	if(a.ff==0)return b;
	return mp(a.ff,b.ss);
}
void go(LL now)
{
	int tl=now%c,tr=(now%c+r+c)%c;
	if(tl<=tr)
	{
		pii cur=mp(0,0);
		for(auto v=st.lower_bound(mp(tl,mp(0,0))),nv=v;v!=st.end()&&v->ff<=tr;v=nv)
		{
			addseg(v->ss,(v->ff-tl+c)%c);
			cur=combine(cur,v->ss);nv=v;nv++;
			st.erase(v);
		}
		if(cur.ff)st.insert(mp(tl,cur));
	}
	else
	{
		pii cur=mp(0,0);
		for(auto v=st.lower_bound(mp(tl,mp(0,0))),nv=v;v!=st.end();v=nv)
		{
			addseg(v->ss,(v->ff-tl+c)%c);
			cur=combine(cur,v->ss);nv=v;nv++;
			st.erase(v);
		}
		for(auto v=st.begin(),nv=v;v!=st.end()&&v->ff<=tr;v=nv)
		{
			addseg(v->ss,(v->ff-tl+c)%c);
			cur=combine(cur,v->ss);nv=v;nv++;
			st.erase(v);
		}
		if(cur.ff)st.insert(mp(tl,cur));
	}
	
}

int ord[100111];
int main()
{
	get3(n,g,r);c=g+r;
	for(int i=1;i<=n+1;i++){get1(l[i]);l[i]+=l[i-1];}
	get1(q);for(int i=1;i<=q;i++){ord[i]=i;get1(t[i]);}
	sort(ord+1,ord+q+1,cmp);
	for(int i=1;i<=q;i++)st.insert(mp((c-t[ord[i]]%c)%c,mp(i,i)));
	for(int i=1;i<=n;i++)go(l[i]);
	for(int i=1;i<=q;i++)
	{
		sum[i]+=sum[i-1];
		ans[ord[i]]=sum[i]+t[ord[i]]+l[n+1];
	}
	for(int i=1;i<=q;i++)printf("%I64d\n",ans[i]);
	return 0;
}