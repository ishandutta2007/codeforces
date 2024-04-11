// not my code https://codeforces.com/blog/entry/93179
 
#pragma GCC target("fpmath=sse,sse2") // Turns off excess precision
// #pragma GCC target("fpmath=387") // Turns on excess precision
 
// #pragma GCC optimize("Ofast,unroll-loops")
// #pragma GCC target("avx,avx2,fma")
 
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ull unsigned long long
#define dd double
#define ld long double
#define sl(n) scanf("%lld", &n)
#define si(n) scanf("%d", &n)
#define pll pair <ll, ll>
#define pii pair <int, int>
#define mp make_pair
#define pb push_back
#define all(v) v.begin(), v.end()
#define inf (1LL << 61)
#define loop(i, start, stop, inc) for(ll i = start; i <= stop; i += inc)
#define for1(i, stop) for(ll i = 1; i <= stop; ++i)
#define for0(i, stop) for(ll i = 0; i < stop; ++i)
#define rep1(i, start) for(ll i = start; i >= 1; --i)
#define rep0(i, start) for(ll i = (start-1); i >= 0; --i)
#define ms(n, i) memset(n, i, sizeof(n))
#define casep(n) printf("Case %lld:", ++n)
#define pn printf("\n")
#define pf printf
#define EL '\n'
#define fastio std::ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 
// === DEBUG MACRO STARTS HERE === //
#ifndef ONLINE_JUDGE
#define DEBUG
#define SYS_COL system("COLOR")
#endif
 
int recur_depth = 0;
#ifdef DEBUG
#define dbg(x) {++recur_depth; auto x_=x; --recur_depth; SYS_COL; \
                cerr<<string(recur_depth, '\t')<<"\e[91m"<<__func__<<":" \
                <<__LINE__<<"\t"<<#x<<" = "<<x_<<"\e[39m"<<endl;}
 
template<typename Ostream, typename Cont>
typename enable_if<is_same<Ostream,ostream>::value,
            Ostream&>::type operator<<(Ostream& os,  const Cont& v) {
	os<<"[";
	for(auto& x:v){os<<x<<", ";}
	return os<<"]";
}
template<typename Ostream, typename ...Ts>
Ostream& operator<<(Ostream& os,  const pair<Ts...>& p){
	return os<<"{"<<p.first<<", "<<p.second<<"}";
}
#else
#define dbg(x)
#endif
// === DEBUG MACRO ENDS HERE === //
 
#define ff first
#define ss second
 
ll s, a, b, c;
 
inline double dist(double x, double y, double z)
{
    if((x==0 && a != 0) || (y==0 && b != 0) || (z==0 && c != 0))
        return -inf;
 
    double f1 = 0, f2 = 0, f3 = 0;
 
    if(x != 0) f1 = a*log(x);
    if(y != 0) f2 = b*log(y);
    if(z != 0) f3 = c*log(z);
 
    return f1 + f2 + f3;
}
 
pair<double, double> solve(double x)
{
    double lo = 0, hi = s-x;
    pair <double , double> ret;
    ll cnt = 200;
 
    while(cnt--) {
        double mid1 = (2*lo+hi)/3, mid2 = (lo+2*hi)/3;
 
        double got1 = dist(x, mid1, s-(x+mid1)), got2 = dist(x, mid2, s-(x+mid2));
 
        if(got1 > got2) {
            ret = mp(got1, mid1);
            hi = mid2;
        }
        else {
            ret = mp(got2, mid2);
            lo = mid1;
        }
    }
 
    return ret;
}
 
int main()
{
    cin >> s >> a >> b >> c;
 
    double lo = 0, hi = s, p1 = 0, p2 = 0;
    ll cnt = 200;
 
    while(cnt--) {
        double mid1 = (2*lo+hi)/3, mid2 = (lo+2*hi)/3;
 
        pair <double, double> got1 = solve(mid1), got2 = solve(mid2);
 
        if(got1.ff > got2.ff) {
            p1 = mid1, p2 = got1.ss;
            hi = mid2;
        }
        else {
            p1 = mid2, p2 = got2.ss;
            lo = mid1;
        }
    }
 
    cout << setprecision(15) << fixed << p1 << " " << p2 << " " << (double)s-(p1+p2) << EL;
 
    return 0;
}