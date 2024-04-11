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
template<typename T> void getint(T &x)
{
	char t=getchar();
	bool neg=false;
	x=0;
	for(; (t>'9'||t<'0')&&t!='-'; t=getchar());
	if(t=='-')neg=true,t=getchar();
	for(; t<='9'&&t>='0'; t=getchar())x=x*10+t-'0';
	if(neg)x=-x;
}
template<typename T> void printint(T x)
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
#define get1(a) getint(a)
#define get2(a,b) get1(a),get1(b)
#define get3(a,b,c) get1(a),get2(b,c)
#define printendl(a) printint(a),puts("")
typedef long long LL;
typedef unsigned long long uLL;
typedef pair<int,int> pii;
const int inf=0x3f3f3f3f;
const LL Linf=1ll<<61;
const double pi=acos(-1.0);

char s[100111][10];
int n,e,tp[100111],val[100111],use[100111];
queue<int>bad1,bad0,no1,no0,spare;
vector<pii> cmd;
int getval(char*s)
{
	int ret=0;
	for(int i=1; s[i]; i++)
	{
		if(s[i]>='a'&&s[i]<='z')return -1;
		if(i==1&&s[i]=='0')return -1;
		ret=ret*10+s[i]-'0';
	}
	if(ret<1||ret>n)return -1;
	return ret;
}
int main()
{
	get1(n);
	for(int i=1; i<=n; i++)
	{
		scanf("%s%d",s[i]+1,tp+i);
		val[i]=getval(s[i]);if(val[i]!=-1)use[val[i]]=1;
		e+=tp[i];
	}
	for(int i=1;i<=n;i++)if(!use[i])spare.push(i);
	for(int i=1;i<=n;i++)
	{
		if(tp[i]==0)
		{
			if(val[i]==-1)no0.push(i);
			else if(val[i]<=e&&val[i]>0)bad0.push(i);
		}
		else
		{
			if(val[i]==-1)no1.push(i);
			else if(val[i]>e&&val[i]<=n)bad1.push(i);
		}
	}
	bool duang=0;
	if(spare.empty()&&(bad0.size()||bad1.size()))
	{
		duang=1;
		if(bad0.size())
		{
			int x=bad0.front();bad0.pop();
			cmd.pb(mp(-x,323213));spare.push(val[x]);
			val[x]=323213;
			no0.push(x);
		}
		else if(bad1.size())
		{
			int x=bad1.front();bad1.pop();
			cmd.pb(mp(-x,323213));spare.push(val[x]);
			no1.push(x);
		}
	}
	while(!spare.empty())
	{
		int pos=spare.front(),x=-1;spare.pop();
		if(pos<=e)
		{
			if(bad1.size())
			{
				x=bad1.front();bad1.pop();
				spare.push(val[x]);
			}
			else if(no1.size())
			{
				x=no1.front();no1.pop();
			}
		}
		else
		{
			if(bad0.size())
			{
				x=bad0.front();bad0.pop();
				spare.push(val[x]);
			}
			else if(no0.size())
			{
				x=no0.front();no0.pop();
			}
		}
		if(x!=-1)cmd.pb(mp(-x,pos));
	}
	printf("%d\n",cmd.size());
	for(int i=0;i<(int)cmd.size();i++)
	{
		if(duang&&i==0)
		{
			printf("move %s 233333\n",s[-cmd[i].ff]+1);
			sprintf(s[-cmd[i].ff]+1,"233333");
		}
		else
		{
			printf("move %s %d\n",s[-cmd[i].ff]+1,cmd[i].ss);
		}
	}
	return 0;
}