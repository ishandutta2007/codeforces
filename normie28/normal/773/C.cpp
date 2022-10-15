
// Problem : C. Prairie Partition
// Contest : Codeforces - VK Cup 2017 - Round 3
// URL : https://codeforces.com/problemset/problem/773/C
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

/*
 A Submission by $%U%$
 at time: $%Y%$-$%M%$-$%D%$ $%h%$:$%m%$:$%s%$
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
#define FILE_IN "cseq.inp"
#define FILE_OUT "cseq.out"
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
typedef long long LL; 
typedef long double LD;
//---------END-------//
 
int cnt[43];
set<LL> help;
map<LL,int> mp;
int cur[43];
int lft[43];
vector<int> fin;
 
int val(LL tmp)
{
	int cn=0;
	while(tmp)
	{
		tmp/=2;
		cn++;
	}
	return cn;
}
 
int main() 
{
	int n;
	cin>>n;
	for(LL i=1;i<=2e12;i=i*2)
	{
		help.insert(i);
		mp[i]=0;
	}
 
	for(int i=1;i<=n;i++)
	{
		LL a;
		cin>>a;
 
		if(help.find(a)!=help.end())
		{
			mp[a]++;
		}
 
		cnt[val(a)]++;
	}	
	int ans=0;
	int num=0;
	while(true)
	{
		LL lst=0;
		for(map<LL,int> :: iterator it=mp.begin();it!=mp.end();it++)
		{
			if(it->second==0)
			{
				break;
			}
			else
			{
				lst=it->first;
			}
		}
 
		if(lst==0)
		{
			break;
		}
		num++;
		cur[val(lst)]++;
		int yu=1;
 
		for(LL i=1;i<=lst;i=i*2)
		{
			cnt[yu]--;
			mp[i]--;
			yu++;
		}
		for(int i=0;i<=42;i++)
		{
			lft[i]=cur[i];
		}
 
		int flg=0;
		for(int i=42;i>=1;i--)
		{
			if(i!=42)
			{
				lft[i]+=lft[i+1];
			}
			if(lft[i]>=cnt[i])
			{
				lft[i]-=cnt[i];
			}
			else
			{
				flg=1;
				break;
			}
 
			
		}
		if(flg==0)
		{
			fin.push_back(num);
			ans++;
		}
	}
	if(ans==0)
	{
		cout<<-1<<endl;
	}
	else
	{
		for(int i=0;i<fin.size();i++)
		{
			cout<<fin[i]<<' ';
		}
	}
}