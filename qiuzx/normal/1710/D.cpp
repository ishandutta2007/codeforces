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
#define N 2010
using namespace std;
ll n,fa[N];
string s[N];
ll getf(ll x){return (x==fa[x])?x:fa[x]=getf(fa[x]);}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll T,i,j,k;
	cin>>T;
	while(T--)
	{
		cin>>n;
		for(i=0;i<n;i++)
		{
			cin>>s[i];
			fa[i]=i;
		}
		fa[n]=n;
		for(i=1;i<n;i++)
		{
			for(j=0;s[j].size()>i;j++)
			{
				if(s[j][i]=='1')
				{
					vector<ll> nds;
					ll cur=j;
					while(cur<=j+i)
					{
						nds.push_back(cur);
						cur=getf(cur)+1;
					}
					if(nds.size()<2)
					{
						continue;
					}
					nds[nds.size()-1]=i+j;
					if(nds.size()==2)
					{
						cout<<nds[0]+1<<" "<<nds[1]+1<<endl;
						fa[getf(nds[0])]=getf(nds[1]);
					}
					else
					{
						cout<<nds[1]+1<<" "<<nds[nds.size()-1]+1<<endl;
						fa[getf(nds[1])]=getf(nds[nds.size()-1]);
					}
					for(k=2;k<nds.size();k++)
					{
						cout<<nds[0]+1<<" "<<nds[k]+1<<endl;
						fa[getf(nds[0])]=getf(nds[k]);
					}
				}
			}
		}
	}
	return 0;
}