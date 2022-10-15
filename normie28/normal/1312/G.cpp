// Problem: G. Autocompletion
// Contest: Codeforces - Educational Codeforces Round 83 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1312/problem/G
// Memory Limit: 512 MB
// Time Limit: 7000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

/*
	Normie's Template v2.2
	Changes:
	Added modulo binpow and inverse.
*/
 
// Standard library in one include.
#include <bits/stdc++.h>
using namespace std;
 
// ordered_set library.

// AtCoder library. (Comment out these two lines if you're not submitting in AtCoder.) (Or if you want to use it in other judges, run expander.py first.)
//#include <atcoder/all>
//using namespace atcoder;
 
//Pragmas (Comment out these three lines if you're submitting in szkopul.)
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast,unroll-loops,tree-vectorize")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
 
//File I/O.
#define FILE_IN "cseq.inp"
#define FILE_OUT "cseq.out"
#define ofile freopen(FILE_IN,"r",stdin);freopen(FILE_OUT,"w",stdout)
 
//Fast I/O.
#define fio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define nfio cin.tie(0);cout.tie(0)
#define endl "\n"
 
//Order checking.
#define ord(a,b,c) ((a>=b)and(b>=c))
 
//min/max redefines, so i dont have to resolve annoying compile errors.
#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))

// Fast min/max assigns to use with AVX.
// Requires g++ 9.2.0.
template<typename T>
__attribute__((always_inline)) void chkmin(T& a, const T& b) {
    a=(a<b)?a:b;
}

template<typename T>
__attribute__((always_inline)) void chkmax(T& a, const T& b) {
    a=(a>b)?a:b;
}
 
//Constants.
#define MOD (ll(998244353))
const int INF = 1e9+7;
const int maxn = 3e5;
#define mag 320
const long double PI=3.14159265358979;
 
//Pairs and 3-pairs.
#define p1 first
#define p2 second.first
#define p3 second.second
#define fi first
#define se second
#define pii(element_type) pair<element_type,element_type>
#define piii(element_type) pair<element_type,pii(element_type)>
 
//Quick power of 2.
#define pow2(x) (ll(1)<<x)
 
//Short for-loops.
#define ff(i,__,___) for(int i=__;i<=___;i++)
#define rr(i,__,___) for(int i=__;i>=___;i--)
 
//Typedefs.
#define bi BigInt
typedef long long ll;
typedef long double ld;
typedef short sh;

// Binpow and stuff
ll BOW(ll a, ll x, ll p)
{
	if (!x) return 1;
	ll res=BOW(a,x/2,p);
	res*=res;
	res%=p;
	if (x%2) res*=a;
	return res%p;
}
ll INV(ll a, ll p)
{
	return BOW(a,p-2,p);
}
//---------END-------//
struct Node {
    int to[26];
    Node() {
        for (int i=0;i<26;i++) {
            to[i] = -1;
        }
    }
    int par = -1;
    int mark = -1;
    int dp = 0;
};
vector<Node> trie(1);
 
vector<int> stek;
multiset<int> stek_set;
int stek_delta = 0;
vector<int> ans;
void dfs(int v) {
    if (trie[v].par!=-1) {
        trie[v].dp = trie[trie[v].par].dp+1;
    }
 
    if (trie[v].mark!=-1) {
        int max_val = (*stek_set.begin())+stek_delta;
        trie[v].dp = min(trie[v].dp, max_val);
        ans[trie[v].mark] = trie[v].dp;
    }
    stek.push_back(trie[v].dp+1-stek_delta);
    stek_set.insert(stek.back());
    if (trie[v].mark!=-1) {
        stek_delta++;
    }
    for (auto it : trie[v].to) {
        if (it!=-1) {
            dfs(it);
        }
    }
    stek_set.erase(stek_set.find(stek.back()));
    stek.pop_back();
 
}

 
int main() {
	fio;
    int n;
    cin >> n;
    ans.resize(n);
 
    for (int i=0;i<n;i++) {
        int pi;
        char ci;
        cin >> pi >> ci;
        trie.emplace_back();
        trie[pi].to[ci-'a'] = trie.size()-1;
        trie.back().par = pi;
    }
    int k;
    cin >> k;
    for (int i=0;i<k;i++) {
        int ai;
        cin >> ai;
        trie[ai].mark = i;
    }
    dfs(0);
    for (int i=0;i<k;i++) {
        cout << ans[i] << " ";
    }
}