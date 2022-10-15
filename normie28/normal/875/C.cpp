
// Problem : C. National Property
// Contest : Codeforces - Codeforces Round #441 (Div. 1, by Moscow Team Olympiad)
// URL : https://codeforces.com/problemset/problem/875/C
// Memory Limit : 512 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

/*
 A Submission by $%U%$
 at time: $%Y%$-$%M%$-$%D%$ $%h%$:$%m%$:$%s%$
*/
/*
Several C++20 features have been implemented:
P1668R1, Permitting Unevaluated inline-assembly in constexpr Functions
P1161R3, Deprecate a[b,c]
P0848R3, Conditionally Trivial Special Member Functions
P1091R3, Extending structured bindings
P1143R2, Adding the constinit keyword
P1152R4, Deprecating volatile
P0388R4, Permit conversions to arrays of unknown bound
P0784R7, constexpr new
Concepts, including P0734R0, P0857R0, P1084R2, P1141R2, P0848R3, P1616R1, P1452R2
P1301R4, [[nodiscard("with reason")]]
P1814R0, class template argument deduction for alias templates
P1816R0, class template argument deduction for aggregates
P0960R3, Parenthesized initialization of aggregates
P1331R2, Allow trivial default initialization in constexpr contexts
P1327R1, Allowing dynamic_cast and polymorphic typeid in constexpr contexts
P0912R5, Coroutines (requires -fcoroutines)
Several C++ Defect Reports have been resolved, e.g.:
DR 1560, lvalue-to-rvalue conversion in ?:
DR 1813, __is_standard_layout for a class with repeated bases
DR 2094, volatile scalars are trivially copyable,
DR 2096, constraints on literal unions
DR 2413, typename in conversion-function-ids
DR 2352, Similar types and reference binding
DR 1601, Promotion of enumeration with fixed underlying type
DR 330, Qualification conversions and pointers to arrays of pointers
DR 1307, Overload resolution based on size of array initializer-list
DR 1710, Missing template keyword in class-or-decltype
New warnings:
-Wmismatched-tags, disabled by default, warns about declarations of structs, classes, and class templates and their specializations with a class-key that does not match either the definition or the first declaration if no definition is provided. The option is provided to ease portability to Windows-based compilers.
-Wredundant-tags, disabled by default, warns about redundant class-key and enum-key in contexts where the key can be eliminated without causing an syntactic ambiguity.
G++ can now detect modifying constant objects in constexpr evaluation (which is undefined behavior).
G++ no longer emits bogus -Wsign-conversion warnings with explicit casts.
Narrowing is now detected in more contexts (e.g., case values).
Memory consumption of the compiler has been reduced in constexpr evaluation.
The noexcept-specifier is now properly treated as a complete-class context as per [class.mem].
The attribute deprecated can now be used on namespaces too.
The ABI of passing and returning certain C++ classes by value changed on several targets in GCC 10, including AArch64, ARM, PowerPC ELFv2, S/390 and Itanium. These changes affect classes with a zero-sized subobject (an empty base class, or data member with the [[no_unique_address]] attribute) where all other non-static data members have the same type (this is called a "homogeneous aggregate" in some ABI specifications, or if there is only one such member, a "single element"). In -std=c++17 and -std=c++20 modes, classes with an empty base class were not considered to have a single element or to be a homogeneous aggregate, and so could be passed differently (in the wrong registers or at the wrong stack address). This could make code compiled with -std=c++17 and -std=c++14 ABI incompatible. This has been corrected and the empty bases are ignored in those ABI decisions, so functions compiled with -std=c++14 and -std=c++17 are now ABI compatible again. Example: struct empty {}; struct S : empty { float f; }; void f(S);. Similarly, in classes containing non-static data members with empty class types using the C++20 [[no_unique_address]] attribute, those members weren't ignored in the ABI argument passing decisions as they should be. Both of these ABI changes are now diagnosed with -Wpsabi.

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
#define pow2(x) (ll(1)<<x)
#define pii pair<int,int>
#define piii pair<int,pii>
#define For(i,__,___) for(int i=__;i<=___;i++)
#define Rep(i,__,___) for(int i=__;i>=___;i--)
#define ordered_set tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update>
#define endl "\n"
#define bi BigInt
typedef long long ll;
#define pb push_back
#define F first
#define S second 
#define ld long double
//---------END-------//
int n,m,k,c[501],pos[100001],t,t1,i,j;
const int MAXN = 1001 * 1001 ; 
vector<int> v[MAXN] ; 
vector<int> ans ; 
int mark[MAXN] ; 
vector<int> adj[MAXN] ; 
 
void add(int x)
{
	if(mark[x]==1) return ; 
	if(mark[x]==2)
	{
		cout << "No\n" ; 
		exit(0) ; 
	}
	ans.pb(x) ;  
	mark[x] = 1 ; 
	for(auto v : adj[x])
		add(v) ; 
 
}
 
int32_t main() 
{
	fio; 
	int n , m ; 
	cin >> n >> m ;
	for(int i = 0 ; i < n ; i ++ ) 	
	{
		int x , y ; 
		cin >> x ; 
		while(x--)
		{
			cin >> y ; 
			v[i].pb(y) ; 
		}
	}
	for(int  _ = 0 ; _ < 30 ; _ ++ ) {
		for(int i = 0 ; i < n - 1 ; i ++ ) 
		{
			int x = v[i].size() , y = v[i+1].size() , j = 0 ;
			while(j<min(x,y)&&v[i][j]==v[i+1][j])
				j ++ ; 	
			if(j==min(x,y))
			{
				if(x>y) 
					return cout << "No" << endl , 0 ; 
				continue ; 
			}
			if(v[i][j]>v[i+1][j])
			{
				if(mark[v[i+1][j]]==1||mark[v[i][j]]==2) 
					return cout << "No" << endl , 0 ; 
				add(v[i][j]) ; 
				mark[v[i+1][j]] = 2 ; 
			}
			else
			{
				if(mark[v[i+1][j]]==1)
				{
					if(mark[v[i][j]]==2)
						return cout << "No" << endl , 0 ; 
					add(v[i][j]) ; 
				}
				else 
					adj[v[i+1][j]].pb(v[i][j]) ; 
			}
		}
	}
	sort(ans.begin(),ans.end()) ; 
	ans.resize(unique(ans.begin(),ans.end())-ans.begin()) ; 
	cout << "Yes\n" ;
	cout << ans.size() << endl ; 
	for(auto u : ans)
		cout << u << ' ' ; 
	if(ans.size()) cout << endl; 
}