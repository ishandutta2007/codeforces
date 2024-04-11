#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define x first
#define y second
#define WT int TT=read();while(TT--) 
#define NO puts("NO");
#define YES puts("YES");
using namespace std;

inline int read()
{
	char c=getchar();int x=0;bool f=0;
	for(;!isdigit(c);c=getchar())f^=!(c^45);
	for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
	if(f)x=-x;return x;
}
void ckmax(int &a,int b){a=(a>b?a:b);}
void ckmin(int &a,int b){a=(a<b?a:b);}

const int M=1e3+10;
int n,a[M],b[20],lim=13,f[20];
vector<int>v,q[20];

signed main()
{
	n=read();int res=n;
	for (int i=0;i<(1<<lim);i++)
		if (__builtin_popcount(i)==lim/2)
		{
			res--,v.pb(i);
			if (!res)break;
		}
	for (int i=0;i<n;i++)
		for (int j=0;j<lim;j++)
			if (((v[i]>>j)&1)^1)q[j].pb(i+1);
	for (int i=0;i<lim;i++)
	{
		if (!q[i].size())continue;
		cout<<"? "<<q[i].size();
		for (auto x:q[i])cout<<' '<<x;
		cout<<endl;f[i]=read();
	}
	cout<<"!";
	for (int i=0;i<n;i++)
	{
		int res=0;
		for (int j=0;j<lim;j++)
			if ((v[i]>>j)&1)res|=f[j];
		cout<<' '<<res;
	}
	cout<<endl;
	return 0;
}