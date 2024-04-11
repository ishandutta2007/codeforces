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

int n,x[10111],y[10111],bx[30],by[30],xcnt,ycnt;
int tmp[10111],ord[10111];
bool okx[32],oky[32];

int getbase(int t[],int b[])
{
	for(int i=0;i<n;i++)
	{
		tmp[i]=t[i];
		ord[i]=i;
	}
	int cnt=0;
	for(int i=0;i<30;i++)
	{
		int id=-1;
		for(int j=cnt;j<n&&id==-1;j++)if((tmp[j]>>i)&1)id=j;
		if(id==-1)continue;
		swap(tmp[cnt],tmp[id]);
		swap(ord[cnt],ord[id]);
		b[cnt]=ord[cnt];
		for(int j=0;j<n;j++)if(j!=cnt&&(tmp[j]>>i)&1)tmp[j]^=tmp[cnt];
		cnt++;
	}
	return cnt;
}

bool sol[30];
int mat[35][35];
bool find_sol(int base[],int bcnt,int tar)
{
	memset(mat,0,sizeof(mat));
	for(int i=0;i<30;i++)for(int j=0;j<bcnt;j++)mat[i][j]=(base[j]>>i)&1;
	for(int i=0;i<30;i++)sol[i]=(tar>>i)&1;
	for(int i=0;i<30;i++)
	{
		if(mat[i][i]==0)
		{
			int id=-1;
			for(int j=i;j<30&&id==-1;j++)
				if(mat[j][i])id=j;
			if(id==-1)continue;
			for(int j=0;j<30;j++)swap(mat[i][j],mat[id][j]);
			swap(sol[i],sol[id]);
		}
		for(int j=0;j<30;j++)
		{
			if(i!=j&&mat[j][i])
			{
				for(int k=0;k<30;k++)
					mat[j][k]^=mat[i][k];
				sol[j]^=sol[i];
			}
		}
	}
	for(int i=0;i<bcnt;i++)if(sol[i])tar^=base[i];
	if(tar)return false;
	return true;
}

vector<pii> op1,op2;
int main()
{
	get1(n);
	for(int i=0;i<n;i++)get1(x[i]);
	for(int i=0;i<n;i++)get1(y[i]);
	
	xcnt=getbase(x,bx);ycnt=getbase(y,by);
	sort(bx,bx+xcnt);sort(by,by+ycnt);
	for(int i=0;i<xcnt;i++)
	{
		if(i!=bx[i])
		{
			op1.pb(mp(i,bx[i]));
			op1.pb(mp(bx[i],i));
			op1.pb(mp(i,bx[i]));
			swap(x[i],x[bx[i]]);
		}
	}
	for(int i=0;i<ycnt;i++)
	{
		if(i!=by[i])
		{
			op2.pb(mp(i,by[i]));
			op2.pb(mp(by[i],i));
			op2.pb(mp(i,by[i]));
			swap(y[i],y[by[i]]);
		}
	}
	for(int i=0;i<ycnt;i++)
	{
		if(!find_sol(x,xcnt,y[i]))
		{
			puts("-1");
			return 0;
		}
		if(i>=xcnt)
		{
			op1.pb(mp(i,i));
			x[i]=0;
			for(int j=0;j<xcnt;j++)if(sol[j])
			{
				op1.pb(mp(i,j));
				x[i]^=x[j];
			}
		}
		else
		{
			for(int j=i;j<xcnt;j++)if(sol[j])
			{
				if(i!=j)
				{
					op1.pb(mp(i,j));
					op1.pb(mp(j,i));
					op1.pb(mp(i,j));
					swap(x[i],x[j]);
				}
				for(int j2=0;j2<xcnt;j2++)if(sol[j2]&&j!=j2)
				{
					op1.pb(mp(i,j2));
					x[i]^=x[j2];
				}
				break;
			}
		}
	}
	for(int i=ycnt;i<n;i++)
	{
		op1.pb(mp(i,i));
		x[i]=0;
		find_sol(x,ycnt,y[i]);
		for(int j=0;j<ycnt;j++)if(sol[j])
		{
			op1.pb(mp(i,j));
			x[i]^=x[j];
		}
	}
	printf("%d\n",(int)op1.size()+(int)op2.size());
	for(int i=0;i<(int)op1.size();i++)printf("%d %d\n",op1[i].ff+1,op1[i].ss+1);
	for(int i=(int)op2.size()-1;i>=0;i--)
	{
		x[op2[i].ff]^=x[op2[i].ss];
		printf("%d %d\n",op2[i].ff+1,op2[i].ss+1);
	}
	return 0;
}