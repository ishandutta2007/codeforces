#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<vector>
#include<queue>
#include<bitset>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<map>
#include<cassert>
#include<string>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
const int N=100010;
struct Node
{
	int cnta,cntb,cntc,inans,outansa,outansc;
	void init(char c)
	{
		cnta=cntb=cntc=inans=outansa=outansc=0;
		if(c=='a')cnta++;else if(c=='b')cntb++;else cntc++;
	}
	Node& operator+=(const Node&a)
	{
		inans=min(min(inans+a.cntc,a.inans+cnta),outansa+a.outansc);
		outansa=min(outansa+a.cntb,a.outansa+cnta);
		outansc=min(outansc+a.cntc,a.outansc+cntb);
		cnta+=a.cnta;
		cntb+=a.cntb;
		cntc+=a.cntc;
		return (*this);
	}
	int getans(){return inans;}
}tree[N<<2];
int n,q;
char s[N];
void build(int p,int le,int ri)
{
	if(le==ri){tree[p].init(s[le]);return;}
	int mid=(le+ri)>>1;
	build(p<<1,le,mid);
	build(p<<1|1,mid+1,ri);
	(tree[p]=tree[p<<1])+=tree[p<<1|1];
}
void modify(int p,int le,int ri,int x,char c)
{
	if(le==ri){tree[p].init(c);return;}
	int mid=(le+ri)>>1;
	if(x<=mid)modify(p<<1,le,mid,x,c);
	else modify(p<<1|1,mid+1,ri,x,c);
	(tree[p]=tree[p<<1])+=tree[p<<1|1];
}
int main()
{
	scanf("%d%d",&n,&q);
	scanf("%s",s+1);
	build(1,1,n);
	rep(i,q)
	{
		int x;char c[5];
		scanf("%d%s",&x,c);
		modify(1,1,n,x,c[0]);
		printf("%d\n",tree[1].getans());
	}
    return 0;
}