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

int n;
vector<int> ans[155];
int main()
{
	ans[0]={1};ans[1]={0,1};
	for(int i=2;i<=150;i++)
	{
		ans[i].pb(0);for(auto x:ans[i-1])ans[i].pb(x);
		bool ok=1;
		for(int j=0;j<(int)ans[i-2].size();j++){ans[i][j]+=ans[i-2][j];ok&=abs(ans[i][j])<2;}
		if(!ok)for(int j=0;j<(int)ans[i-2].size();j++)ans[i][j]-=ans[i-2][j]*2;
	}
	get1(n);
	printf("%d\n",(int)ans[n].size()-1);for(auto x:ans[n])printf("%d ",x);puts("");
	n--;printf("%d\n",(int)ans[n].size()-1);for(auto x:ans[n])printf("%d ",x);puts("");
	return 0;
}