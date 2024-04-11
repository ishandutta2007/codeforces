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

const int add=200;
const int dx[]={1,1,0,-1,-1,-1,0,1};
const int dy[]={0,-1,-1,-1,0,1,1,1};
set<pii> s;
bool f[35][533][533][8];
int t[35],n;
void cover(int x,int y,int d,int l)
{
//	printf("l= %d\n",l);
	s.insert(mp(x,y));
	while(l--)
	{
		x+=dx[d];
		y+=dy[d];
		s.insert(mp(x,y));
//		printf("Add %d %d\n",x,y);
	}
}
int main()
{
	get1(n);
	for(int i=1;i<=n;i++)get1(t[i]);
	t[1]--;
	f[1][0+add][0+add][0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<533;j++)
			for(int k=0;k<533;k++)
				for(int d=0;d<8;d++)
				{
					if(!f[i][j][k][d])continue;
//					printf("%d %d %d %d gege %d\n",i,j,k,d,s.size());
					int d1=(d+7)&7,d2=(d+1)&7;
					cover(j,k,d,t[i]);
					f[i+1][j+dx[d]*t[i]][k+dy[d]*t[i]][d1]=1;
					f[i+1][j+dx[d]*t[i]][k+dy[d]*t[i]][d2]=1;
				}
	}
	printf("%d\n",s.size());
	return 0;
}