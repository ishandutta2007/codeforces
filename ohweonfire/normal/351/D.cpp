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
template<typename T> void get_int(T &x)
{
	char t=getchar();
	bool neg=false;
	x=0;
	for(; (t>'9'||t<'0')&&t!='-'; t=getchar());
	if(t=='-')neg=true,t=getchar();
	for(; t<='9'&&t>='0'; t=getchar())x=x*10+t-'0';
	if(neg)x=-x;
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
#define get2(a,b) get1(a),get1(b)
#define get3(a,b,c) get1(a),get2(b,c)
#define printendl(a) print_int(a),puts("")
typedef long long LL;
typedef unsigned long long uLL;
typedef pair<int,int> pii;
const int inf=0x3f3f3f3f;
const LL Linf=1ll<<61;
const double pi=acos(-1.0);

const int magic=300;

int n,q,a[100111],ans[100111],ord[100111],ql[100111],qr[100111];
int pre[100111],nxt[100111];
int curl,curr,tot,ok,cnt[100111],dif[100111];

bool cmp(int x,int y){return mp(ql[x]/magic,qr[x])<mp(ql[y]/magic,qr[y]);}

void addr()
{
	curr++;
	cnt[a[curr]]++;
	if(cnt[a[curr]]==1)tot++;
	if(cnt[a[curr]]==1)ok++;
	else if(cnt[a[curr]]>2&&curr-pre[curr]!=pre[curr]-pre[pre[curr]])
	{
		if(dif[a[curr]]==0)ok--;
		dif[a[curr]]++;
	}
}
void addl()
{
	curl--;
	cnt[a[curl]]++;
	if(cnt[a[curl]]==1)tot++;
	if(cnt[a[curl]]==1)ok++;
	else if(cnt[a[curl]]>2&&nxt[curl]-curl!=nxt[nxt[curl]]-nxt[curl])
	{
		if(dif[a[curl]]==0)ok--;
		dif[a[curl]]++;
	}
}
void delr()
{
	if(cnt[a[curr]]==1)tot--;
	if(cnt[a[curr]]==1)ok--;
	else if(cnt[a[curr]]>2&&curr-pre[curr]!=pre[curr]-pre[pre[curr]])
	{
		dif[a[curr]]--;
		if(dif[a[curr]]==0)ok++;
	}
	cnt[a[curr]]--;
	curr--;
}
void dell()
{
	if(cnt[a[curl]]==1)tot--;
	if(cnt[a[curl]]==1)ok--;
	else if(cnt[a[curl]]>2&&nxt[curl]-curl!=nxt[nxt[curl]]-nxt[curl])
	{
		dif[a[curl]]--;
		if(dif[a[curl]]==0)ok++;
	}
	cnt[a[curl]]--;
	curl++;
}

int main()
{
	get1(n);
	for(int i=1;i<=n;i++)
	{
		get1(a[i]);
		if(cnt[a[i]])
		{
			pre[i]=cnt[a[i]];
			nxt[cnt[a[i]]]=i;
		}
		cnt[a[i]]=i;
	}
	memset(cnt,0,sizeof(cnt));
	get1(q);
	for(int i=1;i<=q;i++)
	{
		ord[i]=i;
		get2(ql[i],qr[i]);
	}
	sort(ord+1,ord+q+1,cmp);
	
	for(int _=1;_<=q;_++)
	{
		int i=ord[_];
		while(curr<qr[i])addr();
		while(curl>ql[i])addl();
		while(curr>qr[i])delr();
		while(curl<ql[i])dell();
		ans[i]=tot+(ok==0);
	}
	for(int i=1;i<=q;i++)printendl(ans[i]);
	return 0;
}