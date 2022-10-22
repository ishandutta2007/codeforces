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

const int M=2e3+10;
const int Mod=1e9+7;
int n,m,a[M][M];
queue<pair<pair<int,int>,int> >q;
int bx[]={1,-1,0,0};
int by[]={0,0,1,-1};

int poww(int a,int b)
{
	int res=1;
	while(b)
	{
		if (b&1)res=res*a%Mod;
		b>>=1,a=a*a%Mod;
	}return res;
}

signed main()
{
	WT
	{
		n=read(),m=read();int cnt=0;
		for (int i=1;i<=n;i++)
		{
			string s;cin>>s;
			for (int j=1;j<=m;j++)
				if (s[j-1]=='0')a[i][j]=0;
				else a[i][j]=-1,cnt++;
		}
		int res=poww(2,cnt);
		if (cnt==n*m)res=(res-1+Mod)%Mod;
		cout<<res<<endl;
	}
	return 0;
}