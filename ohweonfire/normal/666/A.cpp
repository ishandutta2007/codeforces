//  This code is written by Eric Sunli Chen ( OhWeOnFire ).
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <map>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>
using namespace std;
template<typename T>
void get_int(T &x)
{
	char t=getchar();
	bool neg=false;
	x=0;
	for(; (t>'9'||t<'0')&&t!='-'; t=getchar());
	if(t=='-')neg=true,t=getchar();
	for(; t<='9'&&t>='0'; t=getchar())x=x*10+t-'0';
	if(neg)x=-x;
}
template<typename T>
void print_int(T x)
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

const int maxn=10111;
char s[maxn];
int n;
bool can[maxn][2];
vector<string> st;
bool cmp(int x,int y,int t)
{
	if(x+t>n+1||y+t>n+1)return 1;
	for(int i=0;i<t;i++)if(s[x+i]!=s[y+i])return 1;
	return 0;
}
int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	can[n][0]=can[n][1]=1;
	for(int i=n-2;i>=5;i--)
	{
		can[i][0]|=(can[i+2][0]&cmp(i+1,i+3,2))|can[i+2][1];
		can[i][1]|=can[i+3][0]|(can[i+3][1]&cmp(i+1,i+4,3));
		string t="";
		t+=s[i+1];
		t+=s[i+2];
		if(can[i][0])st.pb(t);
		t+=s[i+3];
		if(can[i][1])st.pb(t);
	}
	sort(st.begin(),st.end());
	st.erase(unique(st.begin(),st.end()),st.end());
	printf("%d\n",st.size());
	for(int i=0;i<(int)st.size();i++)
		cout<<st[i]<<endl;
	return 0;
}