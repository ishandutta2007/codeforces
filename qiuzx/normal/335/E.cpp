//ANMHLIJKTJIY!
#pragma GCC optimize(2)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline","fast-math","unroll-loops","no-stack-protector")
#pragma GCC diagnostic error "-fwhole-program"
#pragma GCC diagnostic error "-fcse-skip-blocks"
#pragma GCC diagnostic error "-funsafe-loop-optimizations"
#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 998244353
#define F first
#define S second
#define ll long long
#define N 100010
using namespace std;
string s;
ll n,h;
double ans;
int main(){
	ll i,j;
	cin>>s>>n>>h;
	if(s=="Bob")
	{
		cout<<n<<endl;
		return 0;
	}
	if(s=="Alice")
	{
		ans=n;
		//(n-j)*(1/2^(2i))*(1-1/(2^i))^(j-1)*(2^i-2^(i-1)*(1+(j-1)/(2^i-1)))
		double x1=1,x2=1;
		for(i=1;i<=h;i++)
		{
			x1=x2;
			x2*=2;
			double cur=1;
			for(j=1;j<n;j++)
			{
				ans+=(double)(n-j)*(double)cur*((double)x2-x1*((double)1.0+(double)(j-1)/(x2-1)))/(x2*x2);
				cur=cur*((double)1.0-(double)1.0/x2);
			}
		}
		printf("%.15lf\n",ans);
	}
	return 0;
}