/*
    Aho-Corasick suffix automaton
    Version 1.1
    Now uses exit links
    Verified with https://open.kattis.com/problems/stringmultimatching
*/
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define rep(i,n) for(int64_t i=0;i < (int64_t)(n);i++)
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define FILE_IN "birds.inp"
#define FILE_OUT "birds.out"
#define ofile freopen(FILE_IN,"r",stdin);freopen(FILE_OUT,"w",stdout)
#define fio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define nfio cin.tie(0);cout.tie(0)
#define max(x,y) (((x)>(y))?(x):(y))
#define min(x,y) (((x)<(y))?(x):(y))
#define ord(a,b,c) ((a>=b)and(b>=c))
#define MOD (ll(1000000007))
#define MAX 300001
#define mag 320
#define p1 first
#define p2 second.first
#define p3 second.second
#define fi first
#define se second
#define pow2(x) (ll(1)<<x)
#define pii pair<int,int>
#define piii pair<int,pii>
#define For(i,__,___) for(int i=__;i<=___;i++)
#define Rep(i,__,___) for(int i=__;i>=___;i--)
#define ordered_set tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update>
#define endl "\n"
#define bi BigInt
#define pi 3.1415926535897
typedef long long ll;
//----------START-----------//

struct mzls
{
	int next[26],fail,count;
	void init()
	{
		memset(next,0,sizeof(next));
		count=0;
		fail=0;
	}
}s[2][500005];
char s1[500005],s2[2][500005];
int n,len,id[2],f[500005][2],a1[500005];
inline void ins(int d)
{
	int nt=0;
	for(int i=0;i<len;i++)
	{
		int j=s1[i]-'a';
		if(s[d][nt].next[j]==0)
		{
			s[d][++id[d]].init();
			s[d][nt].next[j]=id[d];
		}
		nt=s[d][nt].next[j];
	}
	s[d][nt].count++;
}
inline void make_fail(int d)
{
	int t1=0;
	queue<int>que;
	for(int i=0;i<26;i++)
		if(s[d][0].next[i]!=0)
			que.push(s[d][0].next[i]);
	int nt;
	while(!que.empty())
	{
		int ml=que.front();
		a1[++t1]=ml;
		que.pop();
		for(int i=0;i<26;i++)
			if(s[d][ml].next[i]!=0)
			{
				int to=s[d][ml].next[i];
				que.push(to);
				nt=s[d][ml].fail;
				while(nt>0&&s[d][nt].next[i]==0)
					nt=s[d][nt].fail;
				if(s[d][nt].next[i]!=0)
					nt=s[d][nt].next[i];
				s[d][to].fail=nt;
			}
	}
	for(int i=1;i<=t1;i++)
		s[d][a1[i]].count+=s[d][s[d][a1[i]].fail].count;
}
inline void cal(int d)
{
	int nt=0;
	for(int i=0;i<len;i++)
	{
		int j=s2[d][i]-'a';
		while(nt>0&&s[d][nt].next[j]==0)
			nt=s[d][nt].fail;
		if(s[d][nt].next[j]!=-1)
			nt=s[d][nt].next[j];
		f[i][d]=s[d][nt].count;
	}
}
int main()
{
	int T=1;
	while(T--)
	{
		scanf("%s",s2[0]);
		len=strlen(s2[0]);
		scanf("%d",&n);
		s[0][id[0]=0].init();
		s[1][id[1]=0].init();
		for(int i=0;i<len;i++)
			s2[1][i]=s2[0][len-i-1];
		while(n--)
		{
			scanf("%s",s1);
			len=strlen(s1);
			ins(0);
			reverse(s1,s1+len);
			ins(1);
		}
		make_fail(0),make_fail(1);
		len=strlen(s2[0]);
		cal(0),cal(1);
		long long ans=0;
		for(int i=1;i<len;i++)
			ans+=1ll*f[i-1][0]*f[len-i-1][1];
		printf("%lld",ans);
	}
    return 0;
}