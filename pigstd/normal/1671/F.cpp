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

const int Mod=998244353;
const int M=210;
int f[30][30][15][15],ans[15][15][15];

void add(int &a,int b){a=(a+b>=Mod)?a+b-Mod:a+b;}

int poww(int a,int b)
{
	int res=1;
	while(b)
	{
		if (b&1)res=res*a%Mod;
		a=a*a%Mod,b>>=1;
	}return res;
}

struct lag
{
	vector<int>x,y;
	void insert(int a,int b){x.pb(a),y.pb(b);}
	void clear(){x.clear(),y.clear();}
	int query(int k)
	{
		int res=0,n=x.size();k%=Mod;
		for (int i=0;i<n;i++)
		{
			int s1=1,s2=1;
			for (int j=0;j<n;j++)
				if (i!=j)s1=s1*(k-x[j]+Mod)%Mod,s2=s2*(x[i]-x[j]+Mod)%Mod;
			res=(res+y[i]*s1%Mod*poww(s2,Mod-2))%Mod;
		}
		return res;
	}
}T[15][15];

void init()
{
	f[1][1][0][0]=1;
	for (int i=2;i<=22;i++)
	{
		for (int j=1;j<=i;j++)
			for (int k=1;k<i;k++)
				for (int w1=0;w1<=11;w1++)
					for (int w2=0;w2<=11;w2++)
						if (w1+(i-j)<=11&&w2+(j<=k)<=11)
							add(f[i][j][w1+i-j][w2+(j<=k)],f[i-1][k][w1][w2]);
		for (int k=1;k<=11;k++)
			for (int x=1;x<=11;x++)
			{
				int res=0;
				for (int j=1;j<=i;j++)add(res,f[i][j][k][x]);
				if (i>=11)T[k][x].insert(i,res);
				else ans[i][k][x]=res;
			}
	}
}

signed main()
{
	init();
	WT
	{
		int n=read(),k=read(),x=read();
		if (n<11)cout<<ans[n][k][x]<<'\n';
		else cout<<T[k][x].query(n)<<'\n';
	}
	return 0;
}