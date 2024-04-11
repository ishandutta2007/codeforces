#include<cmath>
#include<algorithm>
#include<bitset>
#include<cassert>
#include<cctype>
#include<cfloat>
#include<ciso646>
#include<climits>
#include<clocale>
#include<complex>
#include<csetjmp>
#include<csignal>
#include<cstdarg>
#include<cstddef>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<cwchar>
#include<cwctype>
#include<deque>
#include<exception>
#include<fstream>
#include<functional>
#include<iomanip>
#include<ios>
#include<iosfwd>
#include<iostream>
#include<istream>
#include<iterator>
#include<limits>
#include<list>
#include<locale>
#include<map>
#include<memory>
#include<new>
#include<numeric>
#include<ostream>
#include<queue>
#include<set>
#include<sstream>
#include<stack>
#include<stdexcept>
#include<streambuf>
#include<string>
#include<typeinfo>
#include<utility>
#include<valarray>
#include<vector>
#define LL long long
#define ll long long
#define ull unsigned long long
#define ULL ull
#define mp make_pair
#define pii pair<int,int>
#define piii pair<int, pii >
#define pll pair <ll,ll>
#define pb push_back
#define big 20160116
#define INF 2147483647
#define pq priority_queue
using namespace std;
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while (ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
const int Maxn=55;
int n,k;
LL a[Maxn];
bool lim[Maxn];
bool dp[Maxn][Maxn];
bool av[Maxn][Maxn];
LL sum[Maxn];
int main(){
	scanf("%d %d",&n,&k);
	for (int i=1;i<=n;i++){
		scanf("%I64d",&a[i]);
		sum[i]=sum[i-1]+a[i];
	}
	LL ans=0;
	for (int i=60;i>=0;i--){
		lim[i]=1;
		memset(dp,false,sizeof(dp));
		dp[0][0]=true;
		memset(av,false,sizeof(av));
		for (int j=1;j<=n;j++){
			for (int l=j;l<=n;l++){
				LL cur=sum[l]-sum[j-1];
				bool flag=true;
				for (int p=0;p<=60;p++){
					if (lim[p] && !(cur>>p&1)) flag=false;
				}
				av[j][l]=flag;
			//	if (flag) cout<<i<<' '<<j<<' '<<l<<endl;
			}
		}
		for (int j=1;j<=k;j++){
			for (int l=1;l<=n;l++){
				for (int pv=1;pv<=l;pv++){
					if (av[pv][l]){
						dp[j][l]|=dp[j-1][pv-1];
					}
				}
			}
		}
		if (dp[k][n]){
			ans|=1ll<<i;
		}
		else{
			lim[i]=0;
		}
	}
	printf("%lld\n",ans);
	return 0;
}