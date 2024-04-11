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
string s,t;
ll l,r,ans=0,sum[N][10];
map<string,ll> id;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll i,j;
	cin>>s>>t;
	id["RR"]=0,id["RG"]=1,id["RB"]=2,id["GR"]=3,id["GG"]=4,id["GB"]=5,id["BR"]=6,id["BG"]=7,id["BB"]=8;
	for(i=1;i<t.size();i++)
	{
		for(j=0;j<9;j++)
		{
			sum[i+1][j]=sum[i][j];
		}
		string cur="";
		cur+=t[i-1],cur+=t[i];
		sum[i+1][id[cur]]++;
	}
	l=r=0;
	for(i=0;i<s.size();i++)
	{
		while(r+1<t.size()&&s[i]!=t[r])
		{
			r++;
		}
		ans+=r-l+1;
		if(i>0&&s[i]!=s[i-1])
		{
			string cur="";
			cur+=s[i],cur+=s[i-1];
			ans-=sum[r+1][id[cur]]-sum[l][id[cur]];
		}
		r++;
		if(l<r&&t[l]==s[i])
		{
			l++;
		}
		if(r==t.size())
		{
			r--;
		}
	}
	cout<<ans<<endl;
	return 0;
}