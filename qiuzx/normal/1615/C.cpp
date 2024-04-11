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
ll n;
string s,t;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll i,T;
	cin>>T;
	while(T--)
	{
		cin>>n>>s>>t;
		if(s=="000"&&t!="000")
		{
			cout<<-1<<endl;
			continue;
		}
		ll t1=0,t2=0,t3=0,t4=0;
		for(i=0;i<n;i++)
		{
			t1+=(s[i]=='0'&&t[i]=='0');
			t2+=(s[i]=='0'&&t[i]=='1');
			t3+=(s[i]=='1'&&t[i]=='0');
			t4+=(s[i]=='1'&&t[i]=='1');
		}
		ll ans=LINF;
		if(t3+t4-1==t3+t1)
		{
			ans=min(ans,t1+t4);
		}
		if(t3==t2)
		{
			ans=min(ans,t2+t3);
		}
		cout<<(ans==LINF?-1:ans)<<endl;
	}
	return 0;
}