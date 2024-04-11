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
typedef long long ll;
//---------END-------//
const int N=500050;
char Base[N];
char Query[N];
set<int> Set;
set<int>::iterator cur,it1,it2,it;
int Pair[N];
void Prepare(int n)
{
	int i;
	stack<int> s;
	for(i=1;i<=n;i++)
	{
		Set.insert(i);
		if(Base[i]=='(') s.push(i);
		else Pair[i]=s.top(),Pair[s.top()]=i,s.pop();
	}
}
void Del(int x, int y)
{
	cur=Set.upper_bound(y);
	it1=Set.lower_bound(x);
	it2=Set.upper_bound(y);
	Set.erase(it1,it2);
	if(cur==Set.end()) cur--;
}
int main()
{
	int n,q,p,i;
	scanf("%i %i %i",&n,&q,&p);
	scanf("%s",Base+1);
	Prepare(n);
	cur=Set.find(p);
	scanf("%s",Query+1);
	for(i=1;i<=q;i++)
	{
		if(Query[i]=='L') cur--;
		if(Query[i]=='R') cur++;
		if(Query[i]=='D')
		{
			int u=*cur,t=Pair[u];
			if(t<u) Del(t,u);
			else Del(u,t);
		}
	}
	for(it=Set.begin();it!=Set.end();it++) printf("%c",Base[*it]);
	printf("\n");
}