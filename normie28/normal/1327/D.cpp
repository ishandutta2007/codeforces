#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define rep(i, n) for (int64_t i = 0; i < (int64_t)(n); i++)
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define FILE_IN "equa.inp"
#define FILE_OUT "equa.out"
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
#define MOD (ll(998244353))
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
//---------END-------//
int n, m, k, t,t1,i,j,l,a,b,aad=0,bad,cad,p[200001],c[200001],used[200001],minn=1e9;
string s;
vi getfac(int x)
{
    vi res;
    for (int i=1;i<=sqrt(x);i++) if (x%i==0)
    {
        res.push_back(i);
        res.push_back(x/i);
    }
    return res;
}
void calc(int x)
{
    used[x]=1;
    vi cycle={x};
    int a,k,j,i=p[x],fail;
    while (i!=x)
    {
        used[i]=1;
        cycle.push_back(i);
        i=p[i];
    }
    vi fac=getfac(cycle.size());
    for (i=0;i<fac.size();i++)
    {
        a=fac[i];
        for (j=0;j<a;j++)
        {
            fail=0;
            for (k=j;k<j+cycle.size();k+=a)
            {
                if (c[cycle[k%cycle.size()]]!=c[cycle[j]]) {fail=1; break;}
            }
            if (!fail) {minn=min(minn,a); break;}
        }
    }
}
int main()
{
//    ofile;
    fio;
    cin>>t;
    for (t1=0;t1<t;t1++)
    {
    cin>>n;
    minn=1e9;
    for (i=1;i<=n;i++)
    {
        used[i]=0;
        cin>>p[i];
    }
    for (i=1;i<=n;i++)
    {
        used[i]=0;
        cin>>c[i];
    }
    for (i=1;i<=n;i++) if (!used[i])
    {
        calc(i);
    }
    cout<<minn<<endl;
    }
}