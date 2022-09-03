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

const int magic=1000;
int n,c,a[200111],cnt[200111];
int b[200111],cc;
set<int> s;
int main()
{
	get2(c,n);
	for(int i=1; i<=n; i++)
	{
		get1(a[i]);
		cnt[a[i]]++;
		if(a[i]>magic)s.insert(a[i]);
	}
	for(int k=1; k<=c; k++)
	{
		cc=0;
		int cur=c;
		bool use=(k<=magic);
		while(cur>0)
		{
			set<int>::iterator it=s.upper_bound(cur);
			if(it==s.begin())
			{
				if(!use&&cur>=k)
				{
					cur-=k;
					use=1;
				}
				break;
			}
			it--;
			if(!use&&k>=(*it)&&k<=cur)
			{
				cur-=k;
				use=1;
				continue;
			}
			else
			{
				int t=min(cnt[*it],cur/(*it));
				cur-=t*(*it);
				b[cc++]=*it;
				s.erase(*it);
			}
		}
		
		for(int i=0; i<cc; i++)s.insert(b[i]);
		if(k<=magic)cnt[k]++;
		for(int i=magic;i>=1;i--)
		{
			int t=min(cnt[i],cur/i);
			cur-=t*i;
		}
		if(k<=magic)cnt[k]--;
		if(cur)
		{
			printf("%d\n",k);
			return 0;
		}
	}
	puts("Greed is good");
	return 0;
}