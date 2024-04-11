
// Problem : E. Empire Strikes Back
// Contest : Codeforces - Codeforces Round #181 (Div. 2)
// URL : https://codeforces.com/problemset/problem/300/E
// Memory Limit : 512 MB
// Time Limit : 5000 ms
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
typedef long long ll;
//---------END-------//
const int maxn = int(1e7) + 10;
bool prime[maxn];
int mx[maxn];
long long cnt[maxn];
vector<int>primes;
bool check(long long val)
{
    for(auto &p : primes)
    {
        ll cur = p;
        ll sum = 0;
        while(cur <= val)
        {
            sum += val/cur;
            cur *= p;
        }
        if(sum < cnt[p])
            return 0;
    }
    return 1;
}
int main()
{
	fio;
    int n;
    cin>>n; 
    for(int i = 2; i < maxn; i++)
    {
        if(prime[i] == 0)
        {
            primes.push_back(i);
            for(int j = i; j < maxn; j += i)
            {
                mx[j] = i;
                prime[j] = 1;
            }
        }
    }
    for(int i = 0; i < n; i++)
    {
        int a;
        cin>>a;
        cnt[a]++;
    }
 
    for(int i = maxn-2; i >= 0; i--)
    {
        cnt[i] += cnt[i+1];
    }
 
    for(int i = maxn-2; i >= 2; i--)
    {
        if(mx[i] != i)
            cnt[mx[i]] += cnt[i];
        cnt[i / mx[i]] += cnt[i];
    }
    ll lo = 1,hi = 1e16,res = 0;
    while(lo <= hi)
    {
        ll mid = (lo+hi)/2;
        if(check(mid))
        {
            res = mid;
            hi = mid - 1;
        }
        else
            lo = mid + 1;
    }
    cout<<res;
}