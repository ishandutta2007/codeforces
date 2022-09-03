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

int tot,ls[12000111],rs[12000111],mx[12000111];
int copy(int t){ls[++tot]=ls[t];rs[tot]=rs[t];mx[tot]=mx[t];return tot;}
void modify(int p,int v,int l,int r,int t)
{
	if(l==r)
	{
		mx[t]=v;
		return;
	}
	int mid=(l+r)>>1;
	if(p<=mid)
	{
		ls[t]=copy(ls[t]);
		modify(p,v,l,mid,ls[t]);
	}
	else
	{
		rs[t]=copy(rs[t]);
		modify(p,v,mid+1,r,rs[t]);
	}
	mx[t]=max(mx[ls[t]],mx[rs[t]]);
}
int query(int l,int r,int tl,int tr,int t)
{
	if(l<=tl&&tr<=r)return mx[t];
	int mid=(tl+tr)>>1,ret=0;
	if(l<=mid&&ls[t])ret=max(ret,query(l,r,tl,mid,ls[t]));
	if(r>mid&&rs[t])ret=max(ret,query(l,r,mid+1,tr,rs[t]));
	return ret;
}

int q,rt[400111],n,w[400111];
int pre[20][400111];LL prew[20][400111];
int main()
{
	rt[n=1]=++tot;modify(0,1,0,inf,1);
	
	get1(q);
	LL a,b;int op,last=0;
	while(q--)
	{
		get3(op,a,b);a^=last;b^=last;
		if(op==1)
		{
			n++;w[n]=b;
			rt[n]=copy(rt[a]);
			pre[0][n]=query(b,inf,0,inf,rt[n]);
//			printf("n= %d pre= %d\n",n,pre[0][n]);
			prew[0][n]=w[pre[0][n]];
			for(int i=1;i<20;i++)
			{
				pre[i][n]=pre[i-1][pre[i-1][n]];
				prew[i][n]=prew[i-1][n]+prew[i-1][pre[i-1][n]];
			}
			modify(b,n,0,inf,rt[n]);
		}
		else
		{
			last=0;
			if(b>=w[a])
			{
				b-=w[a];
				for(int i=19;i>=0;i--)if(pre[i][a]&&prew[i][a]<=b)
				{
					b-=prew[i][a];
					a=pre[i][a];
					last|=1<<i;
				}
				last++;
			}
			printendl(last);
		}
	}
	return 0;
}