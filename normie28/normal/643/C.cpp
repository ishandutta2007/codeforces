
// Problem : C. Levels and Regions
// Contest : Codeforces - VK Cup 2016 - Round 3
// URL : https://codeforces.com/problemset/problem/643/C
// Memory Limit : 256 MB
// Time Limit : 3000 ms
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
#define KM 51
#define MN 200020
 
double dp[MN][KM];
 
int n, k, t[MN];
double acum_num[MN], acum_denom[MN], pref[MN];
 
double C(int l, int r) {
    if(l == 0) return pref[r];
    return pref[r] - pref[l-1] - acum_num[l-1]*(acum_denom[r] - acum_denom[l-1]);
}
 
struct func {
    double a, b;
    int q;
    func() {}
    func(double a, double b, int q): a(a), b(b), q(q) {}
    double y(double x) { return a*x + b; }
    double intersec(func o) {
        return (o.b - b) / (a - o.a);
    }
};
 
struct CHT {
    deque<func> cht;
 
    bool bad(func a, func b, func c) {
        return a.intersec(c) <= a.intersec(b);
    }
    void add(func f) {
        while(cht.size() > 1 && bad(cht[cht.size()-2], cht.back(), f)) {
            cht.pop_back();
        }
        cht.push_back(f);
    }
    pair<double, int> query(double x) {
        while(cht.size() > 1 && cht[0].y(x) >= cht[1].y(x)) cht.pop_front();
        return {cht.front().y(x), cht.front().q};
    }
};
 
pair<double, int> solve(double C) {
    CHT resp;
    pair<double, int> ans;
    resp.add(func(0, C, 1));
    for(int i = 1; i <= n; i++) {
        ans = resp.query(acum_denom[i]);
        ans.first += pref[i];
        resp.add(func(-acum_num[i], ans.first - pref[i] + acum_num[i]*acum_denom[i] + C, ans.second + 1));
    }
    return ans;
}
 
int main() {
	fio;
	cin>>n>>k;
    for(int i = 1; i <= n; i++)
    cin>>t[i];
 
    for(int i = 1; i <= n; i++) {
        acum_num[i] = acum_num[i-1] + t[i];
        acum_denom[i] = acum_denom[i-1] + 1.0/t[i];
        pref[i] = pref[i-1] + acum_num[i]/t[i];
    }
 
    double l = 0, r = 1e16, m;
    pair<double, int> ans;
 
    for(int it = 70; it; it--) {
        m = (l + r)/2;
        ans = solve(m);
        if(ans.second > k) l = m;
        else {
            r = m;
            if(ans.second == k) break;
        }
 
    }
    ans = solve(r);
 
    cout<<fixed<<setprecision(10)<<(ans.first - r*k);
}