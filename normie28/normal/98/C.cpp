
/*
	Normie's Template v2.0
*/
 
// Standard library in one include.
#include <bits/stdc++.h>
using namespace std;
 
// ordered_set library.
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set(el) tree<el,null_type,less<el>,rb_tree_tag,tree_order_statistics_node_update>
 
// AtCoder library. (Comment out these two lines if you're not submitting in AtCoder.) (Or if you want to use it in other judges, run expander.py first.)
//#include <atcoder/all>
//using namespace atcoder;
 
//Pragmas (Comment out these three lines if you're submitting in szkopul.)
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
 
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

//Constants.
#define MOD (ll(998244353))
#define MAX 300001
#define mag 320
 
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
//---------END-------//
struct pkt
{
    double x, y;
};
 
double Odl(pkt l1, pkt l2, pkt p)
{
    double l = abs((l1.y - l2.y) * p.x + (l2.x - l1.x) * p.y + l1.y * (l1.x - l2.x) - l1.x * (l1.y - l2.y));
    double m = sqrt((l1.y - l2.y) * (l1.y - l2.y) + (l2.x - l1.x) * (l2.x - l1.x));
    return l / m;
}
 
int main()
{
    fio;
    double a, b, l;
    cin >> a >> b >> l;
    if (a > b)
        swap(a, b);
    if (l <= a)
    {
        cout << l;
        return 0;
    }
    if (l > a && l <= b)
    {
        cout << a;
        return 0;
    }
    double L = 0, P = l, s1, s2, odp;
    for (int i = 0; i < 60; ++i)
    {
        s1 = L + (P - L) / 3.0;
        s2 = P - (P - L) / 3.0;
        double w1 = Odl({s1, 0}, {0, sqrt(l * l - s1 * s1)}, {a, b});
        double w2 = Odl({s2, 0}, {0, sqrt(l * l - s2 * s2)}, {a, b});
        odp = w2;
        if (w1 > w2)
            L = s1;
        if (w1 < w2)
            P = s2;
        if (w1 == w2)
        {
            L = s1;
            P = s2;
        }
    }
    if (odp < 0.0000001)
        cout << "My poor head =(";
    else
    {
        cout << fixed << setprecision(7)<<odp;
    }
}