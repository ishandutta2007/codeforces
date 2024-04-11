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
const int M=2030;
int C[M<<1][M<<1],n,m,res,sum1[M][M];

int calc(int n,int m)
{
	if (n<1||n+m<1)return 0;
	else return C[n+m-1][n-1];
}

void init(int n)
{
	for (int i=0;i<=n;i++)
	{
		C[i][0]=1;
		for (int j=1;j<=i;j++)C[i][j]=(C[i-1][j-1]+C[i-1][j])%Mod;
	}
}

signed main()
{
	n=read(),m=read();init(n+m);
	for (int i=1;i<max(n,m);i++)
	{
		sum1[i][0]=calc(i,0);
		for (int j=1;j<max(n,m);j++)
			sum1[i][j]=(sum1[i][j-1]+calc(i,j))%Mod;
	}
	for (int i=1;i<m;i++)
	{
		int cnt2=0;
		for (int j=1;j<n;j++)
		{
			int cnt1=sum1[i][n-j-1];
			if (j>=2)cnt2=(cnt2+calc(m-i,n-j+1)*sum1[m-i][j-2])%Mod;
//			for (int k=0;k<n-j;k++)cnt1=(cnt1+calc(i,k))%Mod;
//			for (int k=2;k<=j;k++)
//			{
//				cnt2=cnt2+calc(m-i,n-k+1)*sum1[m-i][k-2];
//				for (int w=0;w+1<k;w++)
//					cnt2=(cnt2+calc(m-i,w)*calc(m-i,n-k+1))%Mod;
//			}
			res=(res+cnt1*cnt2%Mod*calc(i,j))%Mod;
//			cout<<cnt1<<' '<<cnt2<<' '<<calc(i,j)<<'\n';
		}
	}
	swap(n,m);
	for (int i=1;i<m;i++)
	{
		int cnt2=0;
		for (int j=1;j<n;j++)
		{
			int cnt1=sum1[i][n-j-1];
			if (j>=2)cnt2=(cnt2+calc(m-i,n-j+1)*sum1[m-i][j-2])%Mod;
//			for (int k=0;k<n-j;k++)cnt1=(cnt1+calc(i,k))%Mod;
//			for (int k=2;k<=j;k++)
//			{
//				cnt2=cnt2+calc(m-i,n-k+1)*sum1[m-i][k-2];
//				for (int w=0;w+1<k;w++)
//					cnt2=(cnt2+calc(m-i,w)*calc(m-i,n-k+1))%Mod;
//			}
			res=(res+cnt1*cnt2%Mod*calc(i,j))%Mod;
//			cout<<cnt1<<' '<<cnt2<<' '<<calc(i,j)<<'\n';
		}
	}
//	cout<<res<<'\n';
	swap(n,m);
	for (int i=1;i<n;i++)for (int j=1;j<m;j++)
	{
		int qwq1=sum1[j][i-1],qwq2=sum1[m-j][n-i-1];
//		for (int k=0;k<=i-1;k++)qwq1=(qwq1+calc(j,k))%Mod;
//		for (int k=0;k<=n-i-1;k++)qwq2=(qwq2+calc(m-j,k))%Mod;
//		cout<<qwq1<<' '<<qwq2<<'\n';
		res=(res+calc(j,n-i)*calc(m-j,i)%Mod*qwq1%Mod*qwq2)%Mod;
	} 
	cout<<res*2%Mod<<'\n';
	return 0;
}