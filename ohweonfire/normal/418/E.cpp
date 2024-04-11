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

const int magic=500,sz=110000/magic;
vector<int> v;
int n,m,a[100111],q[100111][3],ans[100111],l[sz],r[sz],b[100111];

int cnt[sz][200111],bit[sz][100111];
void add(int*bit,int x,int v){if(x==0)return;for(;x<100111;x+=x&-x)bit[x]+=v;}
int query(int*bit,int x){int ret=0;for(;x;x-=x&-x)ret+=bit[x];return ret;}
int query(int*bit,int l,int r){return query(bit,r)-query(bit,l-1);}

int main()
{
	v.pb(0);
	get1(n);
	for(int i=1;i<=n;i++){get1(a[i]);v.pb(a[i]);}
	get1(m);
	for(int i=1;i<=m;i++)
	{
		get3(q[i][0],q[i][1],q[i][2]);
		if(q[i][0]==1)v.pb(q[i][1]);
		else if(q[i][1]>2)q[i][1]=q[i][1]%2+2;
	}
	sort(v.begin(),v.end());v.erase(unique(v.begin(),v.end()),v.end());
	for(int i=1;i<=n;i++)a[i]=lower_bound(v.begin(),v.end(),a[i])-v.begin();
	for(int i=1;i<=m;i++)if(q[i][0]==1)q[i][1]=lower_bound(v.begin(),v.end(),q[i][1])-v.begin();
	
	int t=(n+magic-1)/magic;
	for(int i=0;i<t;i++){l[i]=i*magic+1;r[i]=min(n,(i+1)*magic);for(int j=l[i];j<=r[i];j++)b[j]=i;}
	for(int i=1;i<=n;i++)
	{
		add(bit[b[i]],cnt[b[i]][a[i]],-1);
		cnt[b[i]][a[i]]++;
		add(bit[b[i]],cnt[b[i]][a[i]],1);
		if(i==r[b[i]])
		{
			memcpy(cnt[b[i]+1],cnt[b[i]],sizeof(cnt[b[i]]));
			memcpy(bit[b[i]+1],bit[b[i]],sizeof(bit[b[i]]));
		}
	}
	for(int i=1;i<=m;i++)
	{
		int &u=a[q[i][2]],&bl=b[q[i][2]];
		if(q[i][0]==1)
		{
			int &v=q[i][1];
			for(int j=bl;j<t;j++)
			{
				add(bit[j],cnt[j][u],-1);
				cnt[j][u]--;
				add(bit[j],cnt[j][u],1);
				add(bit[j],cnt[j][v],-1);
				cnt[j][v]++;
				add(bit[j],cnt[j][v],1);
			}
			u=v;
		}
		else
		{
			if(q[i][1]==1)printendl(v[a[q[i][2]]]);
			else
			{
				int ans=0;if(bl)ans=cnt[bl-1][u];
				for(int j=l[bl];j<=q[i][2];j++)ans+=(a[j]==u);
				if(q[i][1]==2)printendl(ans);
				else
				{
					for(int j=q[i][2]+1;j<=r[bl];j++)
					{
						add(bit[bl],cnt[bl][a[j]],-1);
						cnt[bl][a[j]]--;
						add(bit[bl],cnt[bl][a[j]],1);
					}
					printendl(query(bit[bl],ans,100000));
					for(int j=q[i][2]+1;j<=r[bl];j++)
					{
						add(bit[bl],cnt[bl][a[j]],-1);
						cnt[bl][a[j]]++;
						add(bit[bl],cnt[bl][a[j]],1);
					}
				}
			}
		}
	}
	
	return 0;
}