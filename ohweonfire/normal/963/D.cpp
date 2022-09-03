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

const uLL base=443;
uLL power[100111],pre[100111];
inline uLL calhash(int l,int r){return pre[r]-pre[l-1]*power[r-l+1];}

char s[100111],t[100111];
int n,l[100111],q,k[100111],ans[100111];


vector<pair<uLL,int> > qs[100111];
vector<int> pos[100111];

int a[100111],tot;

int main()
{
	power[0]=1;
	for(int i=1;i<100111;i++)power[i]=power[i-1]*base;
	
	scanf("%s",s+1);n=strlen(s+1);
	for(int i=1;i<=n;i++)pre[i]=pre[i-1]*base+s[i]-'a'+1;
	get1(q);
	for(int i=1;i<=q;i++)
	{
		get1(k[i]);scanf("%s",t+1);l[i]=strlen(t+1);
		uLL hsx=0;
		for(int j=1;j<=l[i];j++)hsx=hsx*base+t[j]-'a'+1;
		qs[l[i]].pb(mp(hsx,i));
	}
	
	for(int len=1;len<=n;len++)if(qs[len].size())
	{
		sort(qs[len].begin(),qs[len].end());
		for(int i=1;i<=n-len+1;i++)
		{
			uLL hsy=calhash(i,i+len-1);
			int id=lower_bound(qs[len].begin(),qs[len].end(),mp(hsy,0))-qs[len].begin();
			if(id<(int)qs[len].size()&&qs[len][id].ff==hsy)
				pos[qs[len][id].ss].pb(i);
		}
	}
	
	for(int i=1;i<=q;i++)
	{
		ans[i]=inf;
		for(int j=k[i]-1;j<(int)pos[i].size();j++)
			ans[i]=min(ans[i],pos[i][j]-pos[i][j-k[i]+1]+l[i]);
		if(ans[i]==inf)ans[i]=-1;
		printf("%d\n",ans[i]);
	}
	return 0;
}