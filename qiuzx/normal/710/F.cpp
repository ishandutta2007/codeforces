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
struct Trie{
	ll tot,ch[N][26],val[N];
	void init()
	{
		tot=0;
		return;
	}
	void ins(string s,ll v)
	{
		ll i,cur=0;
		for(i=0;i<s.size();i++)
		{
			if(ch[cur][s[i]-'a']==0)
			{
				ch[cur][s[i]-'a']=++tot;
			}
			cur=ch[cur][s[i]-'a'];
		}
		val[cur]+=v;
		return;
	}
	ll query(string s)
	{
		ll i,cur=0,ret=0;
		for(i=0;i<s.size();i++)
		{
			if(ch[cur][s[i]-'a']==0)
			{
				break;
			}
			cur=ch[cur][s[i]-'a'];
			ret+=val[cur];
		}
		return ret;
	}
}trie;
ll n,val[N],bas=5237,pw[N],sz[N],hval[N];
bool vis[N];
char buf[N];
vector<ll> plc;
map<ll,ll> mp;
ll gethash(string s)
{
	ll ret=0,i;
	for(i=0;i<s.size();i++)
	{
		ret=(ret*bas+(s[i]-'a'+10))%mod;
	}
	return ret;
}
ll calc(ll l,ll r)
{
	return (hval[r+1]+mod-((hval[l]*pw[r-l+1])%mod))%mod;
}
int main(){
	ll i,j,k,tp;
	trie.init();
	pw[0]=1;
	for(i=1;i<N;i++)
	{
		pw[i]=(pw[i-1]*bas)%mod;
	}
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld%s",&tp,&buf);
		string s=buf;
		if(tp==1)
		{
			if(s.size()>=B)
			{
				plc.push_back(i);
				vis[i]=false;
				sz[i]=s.size();
				val[i]=gethash(s);
				mp[val[i]]=i;
			}
			else
			{
				trie.ins(s,1);
			}
		}
		else if(tp==2)
		{
			if(s.size()>=B)
			{
				vis[mp[gethash(s)]]=true;
			}
			else
			{
				trie.ins(s,-1);
			}
		}
		else
		{
			hval[0]=0;
			for(j=0;j<s.size();j++)
			{
				hval[j+1]=(hval[j]*bas+(s[j]-'a'+10))%mod;
			}
			ll ans=0;
			for(j=0;j<plc.size();j++)
			{
				if(!vis[plc[j]])
				{
					for(k=0;k+sz[plc[j]]<=s.size();k++)
					{
						if(calc(k,k+sz[plc[j]]-1)==val[plc[j]])
						{
							ans++;
						}
					}
				}
			}
			while(s.size())
			{
				ans+=trie.query(s);
				s.erase(s.begin());
			}
			printf("%lld\n",ans);
			fflush(stdout);
		}
	}
	return 0;
}