
// Problem : E. Anton and Permutation
// Contest : Codeforces - Codeforces Round #404 (Div. 2)
// URL : https://codeforces.com/problemset/problem/785/E
// Memory Limit : 512 MB
// Time Limit : 4000 ms
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
#define block 500
typedef long long ll;
//---------END-------//
int arr[200003],bit[500][200003],n;
long long int res;
void update(int bi[],int in,int val)
{
	while(in<=n)
	{
		bi[in]+=val;
		in=in+(in&(-in));
	}
}
int get_sum(int bi[],int in)
{
	int tot=0;
	while(in)
	{
		tot+=bi[in];
		in=in-(in&(-in));
	}
	return tot;
}
int main()
{
	fio;
	int i,q;
	cin>>n>>q;
	for(i=0;i<n;i++)
	{
		arr[i]=i+1;
		update(bit[i/block],i+1,1);
	}
	while(q--)
	{
		int a,b;
		cin>>a>>b;
		a--;b--;
		if(a>b)
		swap(a,b);
		int a_block=a/block,b_block=b/block;
		if(a_block==b_block)
		{
			for(i=a+1;i<b;i++)
			{
				if(arr[i]>arr[a])
					res++;
				else
					res--;
				if(arr[i]>arr[b])
					res--;
				else
					res++;
			}
		}
		else
		{
			int na=(a_block+1)*block;
			for(i=a+1;i<na;i++)
			{
				if(arr[i]>arr[a])
					res++;
				else
					res--;
				if(arr[i]>arr[b])
					res--;
				else
					res++;
			}
			for(i=a_block+1;i<b_block;i++)
				res+=2*(get_sum(bit[i],arr[b])-get_sum(bit[i],arr[a]));
			for(i=b_block*block;i<b;i++)
			{
				if(arr[i]>arr[a])
					res++;
				else
					res--;
				if(arr[i]>arr[b])
					res--;
				else
					res++;
			}
		}
		if(arr[a]>arr[b])
			res--;
		else if(arr[a]<arr[b])	
			res++;
		update(bit[a_block],arr[a],-1);
		update(bit[b_block],arr[b],-1);
		
		update(bit[a_block],arr[b],1);
		update(bit[b_block],arr[a],1);
		swap(arr[a],arr[b]);
		cout<<res<<endl;
	}
}