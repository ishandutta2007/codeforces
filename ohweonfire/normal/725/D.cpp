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

int n,ans;
pair<LL,LL> t[300111];
priority_queue<LL,vector<LL>,greater<LL> >q;
int main()
{
	get1(n);
	for(int i=1;i<=n;i++)
		get2(t[i].ff,t[i].ss);
	sort(t+2,t+n+1);reverse(t+2,t+n+1);
	LL cur=t[1].ff;int curt=n,i;
	for(i=2;i<=n;i++)
	{
		if(t[i].ff>t[1].ff)q.push(t[i].ss-t[i].ff+1);
		else
		{
			curt=i-1;
			break;
		}
	}
	ans=curt;
	while(!q.empty())
	{
		LL x=q.top();q.pop();
		cur-=x;curt--;
		if(cur<0)break;
		while(i<=n)
		{
			if(t[i].ff>cur)
			{
				q.push(t[i].ss-t[i].ff+1);
				i++;
				curt++;
			}
			else break;
		}
		ans=min(ans,curt);
	}
	printendl(ans);
	return 0;
}