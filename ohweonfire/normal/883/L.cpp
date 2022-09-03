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

struct car
{
	LL ava_tm;
	int id,pos;
	bool operator <(const car&b)const{if(ava_tm!=b.ava_tm)return ava_tm<b.ava_tm;return id<b.id;}
	bool operator >(const car&b)const{return b<*this;}
};
priority_queue<car,vector<car>,greater<car> >pq,have[200111];
set<int>pos;
int n,k,m;
void assign(int p,int nxt,LL nxt_tm)
{
	int id=have[p].top().id;
	printf("%d ",id);
	have[p].pop();if(have[p].empty())pos.erase(p);
	pq.push(car{nxt_tm,id,nxt});
}
int main()
{
	get3(n,k,m);
	for(int i=1,x;i<=k;i++)
	{
		get1(x);
		pq.push(car{0,i,x});
	}
	pos.insert(-inf);pos.insert(inf);
	LL ltm=0;
	for(int i=1;i<=m;i++)
	{
		LL tm,wait=0;int st,ed;
		get3(tm,st,ed);
		if(tm<ltm){wait=ltm-tm;tm=ltm;}
		else ltm=tm;
		while(!pq.empty()&&pq.top().ava_tm<=tm)
		{
			car tmp=pq.top();pq.pop();
			pos.insert(tmp.pos);have[tmp.pos].push(tmp);
		}
		if(pos.size()==2)
		{
			wait+=pq.top().ava_tm-tm;
			tm=ltm=pq.top().ava_tm;
			while(!pq.empty()&&pq.top().ava_tm<=tm)
			{
				car tmp=pq.top();pq.pop();
				pos.insert(tmp.pos);have[tmp.pos].push(tmp);
			}
		}
		set<int>::iterator it=pos.lower_bound(st);
		int l,r=*it;it--;l=*it;
//		printf("st= %d l= %d r= %d\n",st,l,r);
		if(st-l<r-st)assign(l,ed,tm+st-l+abs(ed-st));
		else if(st-l>r-st)assign(r,ed,tm+r-st+abs(ed-st));
		else if(have[l].top()<have[r].top())assign(l,ed,tm+st-l+abs(ed-st));
		else assign(r,ed,tm+r-st+abs(ed-st));
		printf("%I64d\n",wait+min(st-l,r-st));
	}
	return 0;
}