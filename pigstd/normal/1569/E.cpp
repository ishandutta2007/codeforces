//AFO countdown:11 Days
#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
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

const int Mod=998244353;
const int M=100;
int k,A,h,n,p[M],ans[M];
map<int,vector<int> >v1[M];

int poww(int a,int b)
{
	int res=1;
	while(b)
	{
		if (b&1)res=res*a%Mod;
		a=a*a%Mod,b>>=1;
	}return res;
} 

signed main()
{
	k=read(),A=read(),h=read();n=(1<<k);
	if (k==1)
	{
		//2 1 or 1 2
		if ((A*A+2*A)%Mod==h)puts("2 1");
		else if ((A+2*A*A)%Mod==h)puts("1 2");
		else puts("-1");return 0;
	}
	if (k==2)
		p[1]=3;
	if (k==3)
		p[1]=p[2]=5,p[3]=3;
	if (k==4)
		p[1]=p[2]=p[3]=p[4]=9,p[5]=p[6]=5,p[7]=3;
	if (k==5)
		p[1]=p[2]=p[3]=p[4]=p[5]=p[6]=p[7]=p[8]=17,p[9]=p[10]=p[11]=p[12]=9,p[13]=p[14]=5,p[15]=3;
	for (int i=0;i<(1<<(n/2)-1);i++)
	{
		queue<int>q;vector<int>v;
		for (int j=1;j<=n/2;j++)q.push(j);
		for (int j=0;j<n/2-1;j++)
		{
			int u1=q.front();q.pop();
			int u2=q.front();q.pop();
			int x=i&(1<<j);
			if (x)v.pb(u2),q.push(u1);
			else v.pb(u1),q.push(u2);
		}int Win=q.front(),Hash=0;
		for (int i=0;i<v.size();i++)
			Hash=(Hash+v[i]*poww(A,p[i+1]))%Mod;
		v1[Win][Hash]=v;
	}
	for (int i=0;i<(1<<(n/2)-1);i++)
	{
		queue<int>q;vector<int>v;
		for (int j=n/2+1;j<=n;j++)q.push(j);
		for (int j=0;j<n/2-1;j++)
		{
			int u1=q.front();q.pop();
			int u2=q.front();q.pop();
			int x=i&(1<<j);
			if (x)v.pb(u2),q.push(u1);
			else v.pb(u1),q.push(u2);
		}int Win=q.front(),Hash=0;
		for (int i=0;i<v.size();i++)
			Hash=(Hash+v[i]*poww(A,p[i+1]))%Mod;
		for (int j=1;j<=n/2;j++)
		{
			//j > win
			//Hash+j*A+Win*A^2=h
			int x1=(h-Hash-j*A-Win*A%Mod*A)%Mod;
			x1=(x1+Mod)%Mod;
			if (v1[j][x1].size()!=0)
			{
				for (int k=0;k<v1[j][x1].size();k++)
					ans[v1[j][x1][k]]=p[k+1];
				for (int k=0;k<v.size();k++)
					ans[v[k]]=p[k+1];
				ans[j]=1,ans[Win]=2;
				for (int k=1;k<=n;k++)
					cout<<ans[k]<<' ';
				return 0;
			}
			//Win > j
			int x2=(h-Hash-Win*A-j*A%Mod*A)%Mod;
			x2=(x2+Mod)%Mod;
			if (v1[j][x2].size()!=0)
			{
				for (int k=0;k<v1[j][x2].size();k++)
					ans[v1[j][x2][k]]=p[k+1];
				for (int k=0;k<v.size();k++)
					ans[v[k]]=p[k+1];
				ans[j]=2,ans[Win]=1;
				for (int k=1;k<=n;k++)
					cout<<ans[k]<<' ';
				return 0;
			}
		}
	}
	puts("-1");
	return 0;
}