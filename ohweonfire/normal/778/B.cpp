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

map<string,int> id;
int n,m,op[5555],ox[5555],oy[5555],mx[1111],mn[1111],v[5555];//0   1 and   2 or   3 xor
int getid(string &s)
{
	if(s=="?")return n+1;
	return id[s];
}
string num[5555],name;
int getsum(int x)
{
	int ret=0;
	for(int i=1;i<=n;i++)
	{
		if(op[i]==0)v[i]=num[i][x]-'0';
		else if(op[i]==1)v[i]=(v[ox[i]]&v[oy[i]]);
		else if(op[i]==2)v[i]=(v[ox[i]]|v[oy[i]]);
		else if(op[i]==3)v[i]=(v[ox[i]]^v[oy[i]]);
		ret+=v[i];
	}
	return ret;
}
int main()
{
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>name;
		id[name]=i;
		cin>>name>>num[i];
		if(num[i][0]=='0'||num[i][0]=='1')continue;
		ox[i]=getid(num[i]);
		cin>>name;
		if(name=="AND")op[i]=1;
		else if(name=="OR")op[i]=2;
		else op[i]=3;
		cin>>num[i];
		oy[i]=getid(num[i]);
	}
	for(int i=0;i<m;i++)
	{
		int t1,t2;
		v[n+1]=0;
		t1=getsum(i);
		v[n+1]=1;
		t2=getsum(i);
//		printf("%d %d\n",t1,t2);
		if(t1<t2)mx[i]=1;
		else if(t1>t2)mn[i]=1;
	}
	for(int i=0;i<m;i++)putchar(mn[i]+'0');puts("");
	for(int i=0;i<m;i++)putchar(mx[i]+'0');puts("");
	return 0;
}