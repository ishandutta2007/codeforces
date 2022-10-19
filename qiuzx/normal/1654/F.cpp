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
#define N (1<<18)+10
using namespace std;
ll n,currk[N],lstrk[N];
string s;
int main(){
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	ll i,j;
	cin>>n>>s;
	for(i=0;i<(1<<n);i++)
	{
		currk[i]=(s[i]-'a');
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<(1<<n);j++)
		{
			lstrk[j]=currk[j];
		}
		vector<pair<ll,ll> > pr;
		for(j=0;j<(1<<n);j++)
		{
			currk[j]=lstrk[j]*INF+lstrk[j^(1<<i)];
			pr.push_back(make_pair(currk[j],j));
		}
		sort(pr.begin(),pr.end());
		currk[pr[0].S]=0;
		for(j=1;j<pr.size();j++)
		{
			currk[pr[j].S]=currk[pr[j-1].S]+(pr[j].F!=pr[j-1].F);
		}
	}
	ll cg=-1,mn=LINF;
	for(i=0;i<(1<<n);i++)
	{
		if(mn>currk[i])
		{
			mn=currk[i];
			cg=i;
		}
	}
	string ans="";
	for(i=0;i<(1<<n);i++)
	{
		ans+=s[i^cg];
	}
	cout<<ans<<endl;
	return 0;
}