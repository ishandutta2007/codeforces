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
#define N 300010
#define B 550
using namespace std;
int rint(){
	int ret=0;
	char c=getchar();
	while(!isdigit(c)) c=getchar();
	while(isdigit(c)) ret=ret*10+(c-'0'),c=getchar();
	return ret;
}
void rout(ll x){
	if(x<10) putchar(x+48);
	else rout(x/10),putchar((x%10)+48);
	return;
}
int n,m,acnt[N];
map<ll,int> mp;
map<int,int> cnt;
vector<int> v1,v2[N],a;
int main(){
	int T,i,j,k,l,x,y;
	T=rint();
	while(T--)
	{
		n=rint(),m=rint();
		cnt.clear();
		a.clear();
		for(i=0;i<n;++i)
		{
			a.push_back(rint());
			++cnt[a[i]];
		}
		mp.clear();
		for(i=0;i<m;++i)
		{
			x=rint(),y=rint();
			mp[(ll)x*INF+y]=mp[(ll)y*INF+x]=1;
		}
		sort(a.begin(),a.end());
		a.erase(unique(a.begin(),a.end()),a.end());
		n=a.size();
		v1.clear();
		for(i=0;i<n;++i)
		{
			acnt[i]=cnt[a[i]];
			v1.push_back(acnt[i]);
		}
		sort(v1.begin(),v1.end());
		v1.erase(unique(v1.begin(),v1.end()),v1.end());
		for(i=0;i<v1.size();++i)
		{
			v2[v1[i]].clear();
		}
		for(i=0;i<n;++i)
		{
			v2[acnt[i]].push_back(a[i]);
		}
		for(i=0;i<v1.size();++i)
		{
			sort(v2[v1[i]].begin(),v2[v1[i]].end());
		}
		ll ans=0;
		for(i=0;i<v1.size();++i)
		{
			for(j=i;j<v1.size();++j)
			{
				x=v1[i],y=v1[j];
				for(k=0;k<v2[x].size();++k)
				{
					for(l=v2[y].size()-1;l>=0;--l)
					{
						if(v2[x][k]!=v2[y][l]&&(!mp.count((ll)v2[x][k]*INF+v2[y][l])))
						{
							ans=max(ans,(ll)(x+y)*(ll)(v2[x][k]+v2[y][l]));
							break;
						}
					}
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}