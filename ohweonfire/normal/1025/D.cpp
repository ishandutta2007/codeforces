// This amazing code is by Eric Sunli Chen.
#include<bits/stdc++.h>
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

bool con[777][777];
int n,a[777],cnt;
bool dp[777][777][2];

int main()
{
	get1(n);
	for(int i=1;i<=n;i++)get1(a[i]);
	
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)con[i][j]=(__gcd(a[i],a[j])>1);
	for(int i=1;i<=n+1;i++)dp[i][i-1][0]=dp[i][i-1][1]=1;
	for(int l=1;l<n;l++)
	{
		for(int i=1;i<=n-l+1;i++)
		{
			int j=i+l-1;
			for(int rt=i;rt<=j;rt++)if(dp[i][rt-1][1]&&dp[rt+1][j][0])
			{
				dp[i][j][0]|=con[rt][i-1];
				dp[i][j][1]|=con[rt][j+1];
			}
		}
	}
	for(int i=1;i<=n;i++)if(dp[1][i-1][1]&&dp[i+1][n][0])
	{
		puts("Yes");
		return 0;
	}
	puts("No");
	return 0;
}