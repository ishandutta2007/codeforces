#include <bits/stdc++.h>
#define IM using
#define GAY namespace
#define LOL std;
IM GAY LOL
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define rep(i, n) for (int64_t i = 0; i < (int64_t)(n); i++)
#define FILE_IN "polygon.inp"
#define FILE_OUT "polygon.out"
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
#define max(x, y) (((x) > (y)) ? (x) : (y))
#define min(x, y) (((x) < (y)) ? (x) : (y))
#define ord(a, b, c) ((a >= b) and (b >= c))
#define MOD (ll(1000000007))
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
#define bi BigInt
#define list_of_primes {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691, 701, 709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797, 809, 811, 821, 823, 827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887, 907, 911, 919, 929, 937, 941, 947, 953, 967, 971, 977, 983, 991, 997}
typedef long long ll;
ll n,m; 
const int N=1e5+100;
ll a[N],b[N];
bool check(ll mid)
{
	int l=1;
	ll cur=0;
	for(int i=1;i<=n;i++)
	{
		if(l>m) return 1;
		if(a[i]-b[l]>mid) return 0;
		cur=a[i];
		if(b[l]>=a[i]) cur=a[i]+mid;
		else cur=max(mid-(a[i]-b[l])+b[l],a[i]+(mid-a[i]+b[l])/2);
		while(cur>=b[l]&&l<=m)l++;
	}
	return l>m;
}
int main()
{
    fio;
	cin>>n>>m;
	ll mx=0;
	 for(int i=1;i<=n;i++) cin>>a[i],mx=max(a[i],mx);
	 for(int j=1;j<=m;j++) cin>>b[j],mx=max(mx,b[j]);
	 ll l=0,r=mx*m;
	 ll ans;
	 while(l<r)
	 {
	 	ll mid=l+r>>1;
	 	if(check(mid)==0) l=mid+1;
		 else r=mid,ans=mid; 
	 }
	 cout<<l<<endl;
}