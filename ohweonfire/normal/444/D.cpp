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
int geths(char*s){int ret=0;for(int i=0;s[i];i++)ret=ret*27+s[i]-'a'+1;return ret;}
char s[50111];
int id[27*27*27*27+100],ids[50111][4],tot,len[200111],sz[200111],n,bid[200111],btot;
int ans[200000/magic+10][200111];
vector<int> st[200111];

int pre[50111],suf[50111];
void calc_ans(int x,int*ans)
{
	for(int i=0;i<=n+1;i++)
	{
		pre[i]=-inf;
		suf[i]=inf;
	}
	for(int i=0;i<(int)st[x].size();i++)
	{
		pre[st[x][i]]=st[x][i];
		suf[st[x][i]+len[x]]=st[x][i]+len[x];
	}
	for(int i=1;i<=n;i++)pre[i]=max(pre[i],pre[i-1]);
	for(int i=n;i>=1;i--)suf[i]=min(suf[i],suf[i+1]);
	for(int i=1;i<=tot;i++)
	{
		ans[i]=n+1;
		for(int _=0;_<st[i].size();_++)
		{
			int st2=st[i][_],mxl=max(len[x],len[i]);
			if(st2+len[i]-mxl>0)ans[i]=min(ans[i],st2+len[i]-pre[st2+len[i]-mxl]+1);
			if(st2+mxl<=n)ans[i]=min(ans[i],suf[st2+mxl]-st2+1);
		}
	}
}
char t1[5],t2[5];
int getsmall(int x,int y)
{
//	printf("small- %d %d\n",x,y);
	int ret=n+1;
	int cur=0;
	for(int i=0;i<(int)st[x].size();i++)
	{
		while(cur!=st[y].size()&&st[y][cur]<=st[x][i])cur++;
		if(cur)ret=min(ret,max(st[y][cur-1]+len[y],st[x][i]+len[x])-st[y][cur-1]+1);
	}
	cur=0;
	for(int i=0;i<(int)st[y].size();i++)
	{
		while(cur!=st[x].size()&&st[x][cur]<=st[y][i])cur++;
		if(cur)ret=min(ret,max(st[x][cur-1]+len[x],st[y][i]+len[y])-st[x][cur-1]+1);
	}
	return ret;
}
bool contain(char*s,char*t)
{
	if(strlen(s)<strlen(t))return false;
	for(int i=0;i<=strlen(s)-strlen(t);i++)
	{
		bool ok=1;
		for(int j=0;j<strlen(t);j++)
			ok&=(t[j]==s[i+j]);
		if(ok)return true;
	}
	return false;
}
int main()
{
	scanf("%s",s+1);n=strlen(s+1);
	for(int i=1;i<=n;i++)
	{
		int hsy=0;
		for(int j=0;j<4&&i+j<=n;j++)
		{
			hsy=hsy*27+s[i+j]-'a'+1;
			if(id[hsy]==0)
			{
				id[hsy]=++tot;
				len[tot]=j;
			}
			ids[i][j]=id[hsy];
			st[ids[i][j]].pb(i);
			sz[ids[i][j]]++;
		}
	}
	for(int i=1;i<=n;i++)if(sz[i]>=magic)
	{
		bid[i]=++btot;
		calc_ans(i,ans[btot]);
	}
	int q;get1(q);
	while(q--)
	{
		scanf("%s%s",t1,t2);
		int hsx=id[geths(t1)],hsy=id[geths(t2)];
		if(hsx==0||hsy==0)
		{
			puts("-1");
			continue;
		}
		if(contain(t1,t2))printendl(strlen(t1));
		else if(contain(t2,t1))printendl(strlen(t2));
		else if(bid[hsx])printendl(ans[bid[hsx]][hsy]);
		else if(bid[hsy])printendl(ans[bid[hsy]][hsx]);
		else printf("%d\n",getsmall(hsx,hsy));
	}
	return 0;
}