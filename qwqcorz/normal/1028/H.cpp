#include<bits/stdc++.h>
#define ull unsigned long long
#define mk make_pair
#define fi first
#define se second
using namespace std;
const int N=2e5+5;
const int M=1.5e6+5;
const ull Add1=998244353;
const ull Mod1=1919810111;
const ull Add2=19260817;
const ull Mod2=1e9+7;

int read()
{
	int s=0;
	char c=getchar(),lc='+';
	while (c<'0'||'9'<c) lc=c,c=getchar();
	while ('0'<=c&&c<='9') s=s*10+c-'0',c=getchar();
	return lc=='-'?-s:s;
}
void write(int x)
{
	if (x<0)
	{
		putchar('-');
		x=-x;
	}
	if (x<10) putchar(x+'0');
	else
	{
		write(x/10);
		putchar(x%10+'0');
	}
}
void print(int x,char c='\n')
{
	write(x);
	putchar(c);
}
int Min[20];
int ans[M];
vector<pair<int,int>>q[N];
unordered_map<ull,int>mp[8];
vector<int>a[N];

signed main()
{
	memset(Min,0x3f,sizeof(Min));
	int n=read(),Q=read();
	for (int i=1;i<=n;i++)
	{
		int x=read();
		for (int j=2;j*j<=x;j++)
		if (x%j==0)
		{
			int cnt=0;
			while (x%j==0) x/=j,cnt++;
			if (cnt&1) a[i].push_back(j);
		}
		if (x>1) a[i].push_back(x);
		sort(a[i].begin(),a[i].end());
	}
	for (int i=1;i<=Q;i++)
	{
		int l=read(),r=read();
		q[l].push_back(mk(r,i));
	}
	for (int i=n;i>=1;i--)
	{
		int siz=a[i].size();
		for (int j=0;j<(1<<siz);j++)
		{
			int cnt=0;
			ull hash1=0,hash2=0;
			for (int k=0;k<siz;k++) if ((j>>k)&1) hash1=(hash1*5032108LLu+a[i][k]+Add1)%Mod1,cnt++;
			for (int k=0;k<siz;k++) if ((j>>k)&1) hash2=(hash2*5032108LLu+a[i][k]+Add2)%Mod2,cnt++;
			ull hash=hash1*Mod2+hash2;
			for (int k=0;k<=7;k++)
			if (mp[k].count(hash))
			{
				int tot=siz+k-cnt;
				Min[tot]=min(Min[tot],mp[k][hash]);
			}
			mp[siz][hash]=i;
		}
		for (auto j:q[i])
		for (int k=0;k<=14;k++) if (Min[k]<=j.fi)
		{
			ans[j.se]=k;
			break;
		}
	}
	for (int i=1;i<=Q;i++) print(ans[i]);
	
	return 0;
}