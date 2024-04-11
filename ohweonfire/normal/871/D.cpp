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

const int maxn=10000111;
bool pr[maxn];
int n,mnv[maxn],miu[maxn],prm[1000111],tot,cnt[maxn];
int main()
{
	get1(n);
	for(int i=1;i<=n;i++)
	{
		miu[i]=1;
		pr[i]=(i>1);
	}
	for(int i=2;i<=n;i++)
	{
		if(pr[i])
		{
			prm[++tot]=mnv[i]=i;
			miu[i]=-1;
			for(int j=i+i;j<=n;j+=i)
			{
				pr[j]=0;
				if(mnv[j]==0)mnv[j]=i;
				if(j/i%i==0)miu[j]=0;
				else miu[j]*=-1;
			}
		}
	}
	LL ans1=0,ans2=0,ans3=0;
	for(int i=1;i<=n;i++)
	{
		cnt[mnv[i]]++;
		ans1+=1ll*miu[i]*(n/i)*(n/i);
	}
	ans1=(1ll*n*n-ans1)-(n-1)>>1;
	int cur=tot,tot2=0;
	for(int i=1;prm[i]*prm[i]<=n;i++)
	{
		while(cur>=1&&1ll*prm[i]*prm[cur]>n)
		{
			tot2+=cnt[prm[cur]];
			cur--;
		}
		ans2+=1ll*cnt[prm[i]]*tot2;
	}
	tot2=0;
	for(int i=tot;i>=1&&1ll*prm[i]*prm[i]>n;i--)
	{
		ans2+=1ll*tot2*cnt[prm[i]];
		tot2+=cnt[prm[i]];
	}
	
	cur=tot;tot2=0;while(cur>=1&&2*prm[cur]>n)cur--;
	for(int i=1;prm[i]*prm[i]<=n;i++)
	{
		while(cur>=1&&1ll*prm[i]*prm[cur]>n)
		{
			tot2+=cnt[prm[cur]];
			cur--;
		}
		ans3+=1ll*cnt[prm[i]]*tot2;
	}
	cur=tot;tot2=0;while(cur>=1&&2*prm[cur]>n)cur--;
	for(int i=cur;i>=1&&1ll*prm[i]*prm[i]>n;i--)
	{
		ans3+=1ll*tot2*cnt[prm[i]];
		tot2+=cnt[prm[i]];
	}
	
	ans2-=ans3;
	printendl(1ll*(n-1)*(n-2)-ans1-ans2*2+ans3);
	return 0;
}