//SB
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC target("avx")
#pragma GCC optimize ("O2")
#pragma GCC optimize ("O3")
#pragma GCC optimize ("O1")
#pragma GCC optimize ("O0")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize("-fdelete-null-pointer-checks,inline-functions-called-once,-funsafe-loop-optimizations,-fexpensive-optimizations,-foptimize-sibling-calls,-ftree-switch-conversion,-finline-small-functions,inline-small-functions,-frerun-cse-after-loop,-fhoist-adjacent-loads,-findirect-inlining,-freorder-functions,no-stack-protector,-fpartial-inlining,-fsched-interblock,-fcse-follow-jumps,-fcse-skip-blocks,-falign-functions,-fstrict-overflow,-fstrict-aliasing,-fschedule-insns2,-ftree-tail-merge,inline-functions,-fschedule-insns,-freorder-blocks,-fwhole-program,-funroll-loops,-fthread-jumps,-fcrossjumping,-fcaller-saves,-fdevirtualize,-falign-labels,-falign-loops,-falign-jumps,unroll-loops,-fsched-spec,-ffast-math,Ofast,inline,-fgcse,-fgcse-lm,-fipa-sra,-ftree-pre,-ftree-vrp,-fpeephole2",3)
#pragma GCC target("avx","sse2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 998244353
#define F first
#define S second
#define ll long long
#define N 16
using namespace std;
int n,m,k,len[N],id[N][N],curupd,tmx;
ll ans[N],res=0;
bool conn[N][N],vis[(1<<12)+10][13][13];
pair<int,pair<int,int> > upd[1000000];
bool check(int mask,int l,int r)
{
	if(mask==(1<<n)-1)
	{
		return true;
	}
	upd[curupd++]=make_pair(mask,make_pair(l,r));
	vis[mask][l][r]=true;
	for(int c=1;c<=tmx;++c)
	{
		for(int i=0;i<len[c];++i)
		{
			int ci=id[c][i];
			if((!(mask&(1<<ci))))
			{
				for(int j=i+1;j<len[c];++j)
				{
					int cj=id[c][j];
					if((!(mask&(1<<cj)))&&ci!=cj)
					{
						if(((conn[l][ci]&&conn[r][cj])||(conn[l][cj]&&conn[r][ci]))&&(!vis[mask|(1<<ci)|(1<<cj)][ci][cj]))
						{
							if(check(mask|(1<<ci)|(1<<cj),ci,cj))
							{
								return true;
							}
						}
					}
				}
			}
		}
	}
	return false;
}
void dfs(int x,int mx)
{
	if(x==n)
	{
		for(int i=1;i<=mx;i++)
		{
			if(len[i]&1)
			{
				return;
			}
		}
		tmx=mx;
		curupd=0;
		for(int c=1;c<=mx;++c)
		{
			for(int i=0;i<len[c];++i)
			{
				for(int j=i+1;j<len[c];++j)
				{
					int ci=id[c][i],cj=id[c][j];
					if(conn[ci][cj])
					{
						upd[curupd++]=make_pair((1<<ci)|(1<<cj),make_pair(ci,cj));
						vis[(1<<ci)|(1<<cj)][ci][cj]=true;
						if(check((1<<ci)|(1<<cj),ci,cj))
						{
							++ans[mx];
							for(int l=0;l<curupd;++l)
							{
								vis[upd[l].F][upd[l].S.F][upd[l].S.S]=false;
							}
							return;
						}
					}
				}
			}
		}
		for(int l=0;l<curupd;++l)
		{
			vis[upd[l].F][upd[l].S.F][upd[l].S.S]=false;
		}
		return;
	}
	for(int i=1;i<=mx+1&&i<=n/2;++i)
	{
		id[i][len[i]]=x;
		++len[i];
		dfs(x+1,max(mx,i));
		--len[i];
	}
	return;
}
int main(){
	int i,x,y;
	ll cur;
	cin>>n>>m>>k;
	for(int i=0;i<m;++i)
	{
		cin>>x>>y;
		conn[x-1][y-1]=conn[y-1][x-1]=true;
	}
	dfs(0,0);
	cur=k;
	for(int i=1;i<=k;++i)
	{
		res+=ans[i]*cur;
		cur*=(k-i);
	}
	cout<<res<<endl;
	return 0;
}