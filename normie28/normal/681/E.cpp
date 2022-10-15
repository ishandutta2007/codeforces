
// Problem : D. Binary String To Subsequences
// Contest : Codeforces - Codeforces Round #661 (Div. 3)
// URL : https://codeforces.com/contest/1399/problem/D
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
#define fef(i,a,b) for(ll i=a;i<=b;i++)
#define rer(i,a,b) for(ll i=b;i>=a;i--)
#define wew while(true)
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
//---------END-------//

#undef M_PIl
#define LD double
#define EPSILON 1E-9
#define M_PIl pi
#define LL long long
 
 
const LD pi = std::acos(-1.0);
const LD pin2 = M_PIl * 2.0L;
 
int main()
{
    fio;
    LL x0, y0, r0, v, t, x, y, r;
    cin >> x0 >> y0 >> v >> t;
    r0 = v * t;
    vector <pair <LD, LD> > res;
    int n;
    cin >> n;
    for (; n; --n)
    {
        cin >> x >> y >> r;
 
        LD dist((x - x0) * (x - x0) + (y - y0) * (y - y0));
 
        if (dist < 1.0 * r * r + EPSILON)
        {
            cout << 1;
            return 0;
        }
        dist = sqrt(dist);
        if (dist - EPSILON > 1.0 * (r + r0))
            continue;
 
        LD easy_l(sqrt(dist * dist - 1.0 * r * r)), alpha(atan2((LD) (y - y0), (LD) (x - x0)));
        double begin(alpha), end(alpha), delta;
 
        if (easy_l < 1.0 * r0 + EPSILON)
            delta = asin((1.0 * r) / dist);
        else
            delta = acos((1.0 * r0 * r0 + dist * dist - 1.0 * r * r) / (2.0 * r0 * dist));
 
        begin -= delta;
        end += delta;
 
        if (end > pi)
        {
            res.push_back({ begin, pi });
            res.push_back({ -pi, end - pin2 });
        }
        else if (begin < -pi)
        {
            res.push_back({ -pi, end });
            res.push_back({ begin + pin2, pi });
        }
        else
            res.push_back({ begin, end });
    }
 
    sort(res.begin(), res.end());
 
    if (!res.size())
    {
        cout << 0;
        return 0;
    }
    //res.push_back({ 2 * pin2, 2 * pin2 });
    LD gl(0), prev(-pi);
    for (int i(0); i < res.size(); ++i)
    {
        if (res[i].first > prev)
            prev = res[i].first;
        if (res[i].second <= prev)
            continue;
        gl += res[i].second - prev;
        prev = res[i].second;
    }
    cout << setprecision(10) << (gl / pin2);
}