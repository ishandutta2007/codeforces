//----------NMFF0B0H----------//
#include <bits/stdc++.h>
#define IM using
#define GAY namespace
#define LOL std;
IM GAY LOL
/*
Search the term 'algorithm visualization' in your favorite Search Engine, do you see VisuAlgo in the first page of the search result :)? Next level: Search that term again, but in your native language (if it is not English). Is VisuAlgo still listed in the first page? :). And get ready to be surprised: Search the name of your favorite data structure or algorithm without mentioning the keyword 'animation' or 'visualization'. Is VisuAlgo still listed in the first page? :):).
*/
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
 
#define rep(i, n) for (int64_t i = 0; i < (int64_t)(n); i++)
#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))
#define FILE_IN "caps.inp"
#define FILE_OUT "caps.out"
#define ofile                     \
    freopen(FILE_IN, "r", stdin); \
    freopen(FILE_OUT, "w", stdout)
#define fio                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0)
#define nfio    \
    cin.tie(0); \
    cout.tie(0)
#define ord(a, b, c) ((a >= b) and (b >= c))
#define MOD (ll(18101203))
#define MAX 300001
#define mag 320
#define p1 first
#define p2 second.first
#define p3 second.second
#define fi first
#define se second
#define pow2(x) (ll(1) << x)
#define pii pair<int, int>
#define piii pair<int, pii>
#define For(i, __, ___) for (int i = __; i <= ___; i++)
#define Rep(i, __, ___) for (int i = __; i >= ___; i--)
#define ordered_set tree<long long, null_type, less<long long>, rb_tree_tag, tree_order_statistics_node_update>
#define endl "\n"
#define vi vector<int>
#define bi bigint
#define get geet
#define list_of_primes {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691, 701, 709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797, 809, 811, 821, 823, 827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887, 907, 911, 919, 929, 937, 941, 947, 953, 967, 971, 977, 983, 991, 997}
typedef long long ll; 
//--------END----------//
ll n,m,k,d,i,j,a,b,t,t1,res1=0,fac[19];
vector<ll> buc[2];
map<pair<long long, long long>, long long> lis[2];
void tri(ll no, ll cur, ll used, ll sum)
{
    if (cur==buc[no].size())
    {
        lis[no][{sum,used}]++;
    }
    else
    {
        tri(no,cur+1,used,sum);
        tri(no,cur+1,used,sum+buc[no][cur]);
        if (buc[no][cur]<=18) 
        tri(no,cur+1,used+1,sum+fac[buc[no][cur]]);
    }
}
int main()
{
//	ofile;
	nfio;
	fac[0]=1;
	for (i=1;i<=18;i++) fac[i]=fac[i-1]*i;
	cin>>n>>k>>m;
	for (i=0;i<n/2;i++)
	{
	    cin>>d;
	    buc[0].push_back(d);
	}
	for (i=n/2;i<n;i++)
	{
	    cin>>d;
	    buc[1].push_back(d);
	}
	for (i=0;i<2;i++)
	{
	    tri(i,0,0,0);
	}
	for (auto el: lis[0])
	{
	    ll tar=el.first.first;
	    ll alloc=el.first.second;
//	    cout<<tar<<' '<<alloc<<' '<<el.second<<endl;
	    for (i=0;i<=k-alloc;i++) res1+=el.second*lis[1][{m-tar,i}];
	}
//	cout<<endl;
	for (auto el: lis[1])
	{
	    ll tar=el.first.first;
	    ll alloc=el.first.second;
//	    cout<<tar<<' '<<alloc<<' '<<el.second<<endl;        
	}
	cout<<res1;
}