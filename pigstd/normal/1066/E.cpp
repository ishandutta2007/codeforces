#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
using namespace std;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

const int M=2e5+10;
const int Mod=998244353;
int n,m,a[M],b[M],sum[M],pow2[M],ans;
char s1[M],s2[M];

signed main()
{
	cin>>n>>m>>s1+1>>s2+1;pow2[0]=1;
	for (int i=1;i<=max(n,m);i++)pow2[i]=pow2[i-1]*2%Mod;
	for (int i=1;i<=n;i++)
		a[i+max(n,m)-n]=s1[i]-'0';
	for (int i=1;i<=m;i++)
		b[i+max(n,m)-m]=s2[i]-'0';
	n=m=max(n,m);
//	for (int i=1;i<=n;i++)cout<<a[i];puts("");
//	for (int i=1;i<=n;i++)cout<<b[i];puts("");
//	cout<<n<<' '<<m<<endl;
	for (int i=1;i<=m;i++)
		sum[i]=sum[i-1]+b[i];
	for (int i=n;i>=1;i--)
		ans=(ans+pow2[n-i]*sum[i]*a[i])%Mod;
	cout<<ans<<endl;
	return 0;
}