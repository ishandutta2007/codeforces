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
#define N 1000010
using namespace std;
ll q,sum[N][2];
string s;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll T,i,l,r;
	cin>>T;
	while(T--)
	{
		cin>>s>>q;
		sum[0][0]=sum[0][1]=0;
		for(i=0;i<s.size();i++)
		{
			sum[i+1][0]=sum[i][0],sum[i+1][1]=sum[i][1];
			sum[i+1][i&1]=(sum[i+1][i&1]+(s[i]=='('||s[i]==')'));
		}
		while(q--)
		{
			cin>>l>>r;
			printf("%lld\n",abs((sum[r][0]-sum[l-1][0])-(sum[r][1]-sum[l-1][1])));
		}
	}
	return 0;
}