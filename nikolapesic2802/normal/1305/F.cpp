
// Problem : F. Kuroni and the Punishment
// Contest : Ozon Tech Challenge 2020 (Div.1 + Div.2, Rated, T-shirts + prizes!)
// URL : https://codeforces.com/contest/1305/problem/F
// Memory Limit : 256 MB
// Time Limit : 2500 ms
// Powered by CP Editor (https://github.com/cpeditor/cp-editor)

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>

#define ll long long
#define pb push_back
#define f first
#define s second
#define sz(x) (int)(x).size()
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define D(x) cerr << #x << " is " << (x) << "\n";
#define ld long double
#define li __int128

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>; ///find_by_order(),order_of_key()
template<class T1, class T2> ostream& operator<<(ostream& os, const pair<T1,T2>& a) { os << '{' << a.f << ", " << a.s << '}'; return os; }
template<class T> ostream& operator<<(ostream& os, const vector<T>& a){os << '{';for(int i=0;i<sz(a);i++){if(i>0&&i<sz(a))os << ", ";os << a[i];}os<<'}';return os;}
template<class T> ostream& operator<<(ostream& os, const deque<T>& a){os << '{';for(int i=0;i<sz(a);i++){if(i>0&&i<sz(a))os << ", ";os << a[i];}os<<'}';return os;}
template<class T> ostream& operator<<(ostream& os, const set<T>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T> ostream& operator<<(ostream& os, const set<T,greater<T> >& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T> ostream& operator<<(ostream& os, const multiset<T>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T> ostream& operator<<(ostream& os, const multiset<T,greater<T> >& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T1,class T2> ostream& operator<<(ostream& os, const map<T1,T2>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T1, class T2> istream& operator>>(istream& is,pair<T1,T2>& a) {is>>a.f>>a.s;return is;}
template<class T> istream& operator>>(istream& is,vector<T>& a) {for(auto &p:a)is>>p;return is;}

// Integer factorization in O(N^{1/4}
// uses squfof from msieve https://github.com/radii/msieve
// with fixes to work for n = p^3
// works up to 10^18
// probably fails on 5003^5 which is ~10^{18.5}

template<typename T, typename SFINAE = void> struct bigger_type{};
template<typename T> using bigger_type_t = typename bigger_type<T>::type;
template<typename T> struct bigger_type<T, typename enable_if<is_integral<T>::value && is_signed<T>::value && sizeof(T) == 4>::type>{using type = long long;};
template<typename T> struct bigger_type<T, typename enable_if<is_integral<T>::value && !is_signed<T>::value && sizeof(T) == 4>::type>{using type = unsigned long long;};
template<typename T> struct bigger_type<T, typename enable_if<is_integral<T>::value && is_signed<T>::value && sizeof(T) == 8>::type>{using type = __int128;};
template<typename T> struct bigger_type<T, typename enable_if<is_integral<T>::value && !is_signed<T>::value && sizeof(T) == 8>::type>{using type = unsigned __int128;};

template<typename int_t = unsigned long long>
struct Mod_Int{
    static inline int_t add(int_t const&a, int_t const&b, int_t const&mod){
        int_t ret = a+b;
        if(ret>=mod) ret-=mod;
        return ret;
    }
    static inline int_t sub(int_t const&a, int_t const&b, int_t const&mod){
        return add(a, mod-b);
    }
    static inline int_t mul(int_t const&a, int_t const&b, int_t const&mod){
				return (ll)(a%mod)*(b%mod)%mod;
        return a*static_cast<bigger_type_t<int_t>>(b)%mod;
    }
    static inline int_t pow(int_t const&a, int_t const&b, int_t const&mod){
        int_t ret = 1;
        int_t base = a;
        for(int i=0;b>>i;++i){
            if((b>>i)&1) ret = mul(ret, base, mod);
            base = mul(base, base, mod);
        }
        return ret;
    }
};

template<typename T>
bool is_prime(T x){
    static_assert(is_integral<T>::value);
    if(x<T(4)) return x>T(1);
    for(T i=2;i*i<=x;++i){
        if(x%i == 0) return false;
    }
    return true;
}

template<typename T>
bool miller_rabin_single(T const&x, T base){
    static_assert(is_integral<T>::value);
    if(x<T(4)) return x>T(1);
    if(x%2 == 0) return false;
    base%=x;
    if(base == 0) return true;

    T xm1 = x-1;
    int j = 1;
    T d = xm1/2;
    while(d%2 == 0){ // could use __builtin_ctz
        d/=2;
        ++j;
    }
    T t = Mod_Int<T>::pow(base, d, x);
    if(t==T(1) || t==T(xm1)) return true;
    for(int k=1;k<j;++k){
        t = Mod_Int<T>::mul(t, t, x);
        if(t == xm1) return true;
        if(t<=1) break;
    }
    return false;
}

template<typename T>
bool miller_rabin_multi(T const&){return true;}
template<typename T, typename... S>
bool miller_rabin_multi(T const&x, T const&base, S const&...bases){
    static_assert(is_integral<T>::value);
    if(!miller_rabin_single(x, base)) return false;
    return miller_rabin_multi(x, bases...);
}

template<typename T>
bool miller_rabin(T const&x){
    static_assert(is_integral<T>::value);
    if(x < 316349281) return miller_rabin_multi(x, T(11000544), T(31481107));
    if(x < 4759123141ull) return miller_rabin_multi(x, T(2), T(7), T(61));
    return miller_rabin_multi(x, T(2), T(325), T(9375), T(28178), T(450775), T(9780504), T(1795265022));
}

template<typename T>
T isqrt(T const&x){
    static_assert(is_integral<T>::value);
    assert(x>=T(0));
    T ret = static_cast<T>(sqrtl(x));
    while(ret>0 && ret*ret>x) --ret;
    while(x-ret*ret>2*ret)
        ++ret;
    return ret;
}
template<typename T>
T icbrt(T const&x){
    static_assert(is_integral<T>::value);
    assert(x>=T(0));
    T ret = static_cast<T>(cbrt(x));
    while(ret>0 && ret*ret*ret>x) --ret;
    while(x-ret*ret*ret>3*ret*(ret+1))
        ++ret;
    return ret;
}
vector<uint16_t> saved;
// fast prime factorization from
// https://github.com/radii/msieve
uint64_t squfof_iter_better(uint64_t const&x, uint64_t const&k, uint64_t const&it_max, uint32_t cutoff_div){
    if(__gcd((uint64_t)k, x)!=1) return __gcd((uint64_t)k, x);
    //cerr << "try: " << x << " " << k << "\n";
    saved.clear();
    uint64_t scaledn = k*x;
    if(scaledn>>62) return 1;
    uint32_t sqrtn = isqrt(scaledn);
    uint32_t cutoff = isqrt(2*sqrtn)/cutoff_div;
    uint32_t q0 = 1;
    uint32_t p1 = sqrtn;
    uint32_t q1 = scaledn-p1*p1;

    if(q1 == 0){
        uint64_t factor = __gcd(x, (uint64_t)p1);
        return factor==x ? 1:factor;
    }

    uint32_t multiplier = 2*k;
    uint32_t coarse_cutoff = cutoff * multiplier;
    //cerr << "at: " << multiplier << "\n";

    uint32_t i, j;
    uint32_t p0 = 0;
    uint32_t sqrtq = 0;

    for(i=0;i<it_max;++i){
        uint32_t q, bits, tmp;

        tmp = sqrtn + p1 - q1;
        q = 1;
        if (tmp >= q1)
            q += tmp / q1;

        p0 = q * q1 - p1;
        q0 = q0 + (p1 - p0) * q;

        if (q1 < coarse_cutoff) {
            tmp = q1 / __gcd(q1, multiplier);

            if (tmp < cutoff) {
                saved.push_back((uint16_t)tmp);
            }
        }

        bits = 0;
        tmp = q0;
        while(!(tmp & 1)) {
            bits++;
            tmp >>= 1;
        }
        if (!(bits & 1) && ((tmp & 7) == 1)) {

            sqrtq = (uint32_t)isqrt(q0);

            if (sqrtq * sqrtq == q0) {
                for(j=0;j<saved.size();++j){
                    if(saved[j] == sqrtq) break;
                }
                if(j == saved.size()) break;
                //else cerr << "skip " << i << "\n";;
            }
        }
        tmp = sqrtn + p0 - q0;
        q = 1;
        if (tmp >= q0)
            q += tmp / q0;

        p1 = q * q0 - p0;
        q1 = q1 + (p0 - p1) * q;

        if (q0 < coarse_cutoff) {
            tmp = q0 / __gcd(q0, multiplier);

            if (tmp < cutoff) {
                saved.push_back((uint16_t) tmp);
            }
        }
    }

    if(sqrtq == 1) { return 1;}
    if(i == it_max) { return 1;}

    q0 = sqrtq;
    p1 = p0 + sqrtq * ((sqrtn - p0) / sqrtq);
    q1 = (scaledn - (uint64_t)p1 * (uint64_t)p1) / (uint64_t)q0;

    for(j=0;j<it_max;++j) {
        uint32_t q, tmp;

        tmp = sqrtn + p1 - q1;
        q = 1;
        if (tmp >= q1)
            q += tmp / q1;

        p0 = q * q1 - p1;
        q0 = q0 + (p1 - p0) * q;

        if (p0 == p1) {
            q0 = q1;
            break;
        }

        tmp = sqrtn + p0 - q0;
        q = 1;
        if (tmp >= q0)
            q += tmp / q0;

        p1 = q * q0 - p0;
        q1 = q1 + (p0 - p1) * q;

        if (p0 == p1)
            break;
    }
    if(j==it_max) {cerr << "RNG\n"; return 1;} // random fail

    uint64_t factor = __gcd((uint64_t)q0, x);
    if(factor == x) factor=1;
    return factor;
}
uint64_t squfof(uint64_t const&x){
    static array<uint32_t, 16> multipliers{1, 3, 5, 7, 11, 3*5, 3*7, 3*11, 5*7, 5*11, 7*11, 3*5*7, 3*5*11, 3*7*11, 5*7*11, 3*5*7*11};
    //uint64_t cbrt_x = icbrt(x);
    //if(cbrt_x*cbrt_x*cbrt_x == x) return cbrt_x;
    uint32_t iter_lim = 1;
    for(uint32_t iter_fact = 1;iter_fact<2;iter_fact*=4){
        for(uint32_t const&k : multipliers){
            if(numeric_limits<uint64_t>::max()/k<=x) continue; //would overflow
            uint32_t const it_max = iter_fact*iter_lim;
            uint64_t factor = squfof_iter_better(x, k, it_max, 1);
            if(factor==1 || factor==x) continue;
            return factor;
        }
    }
    return x;
}

template<typename T>
vector<T> factorize(T x){
    static_assert(is_integral<T>::value);
    vector<T> ret;
    const uint32_t trial_limit = 1000;
    auto trial = [&](int i){while(x%i == 0){x/=i; ret.push_back(i);}};
    trial(2); trial(3);
    for(uint32_t i=5, j=2;i<trial_limit && i*i <= x;i+=j, j=6-j){
        trial(i);
    }
    if(x>1){
        static stack<T> s;
        s.push(x);
        while(!s.empty()){
            x = s.top(); s.pop();
            if(!miller_rabin(x)){
                T factor = squfof(x);
                if(factor == 1 || factor == x){ret.pb(factor);continue;}
                s.push(factor);
                s.push(x/factor);
            } else {
                ret.push_back(x);
            }
        }
    }
    sort(ret.begin(), ret.end());
    return ret;
}

unordered_set<ll> primes;
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
 
    int n;
    cin >> n;
 
    vector<ll> A(n);
    for (auto &a : A)
        cin >> a;
 
    int ii = 0;
    ll best = 0;
    for (auto a : A) {
        best += a & 1;
        auto tr=factorize(a);
        for(auto p:tr)
        	primes.insert(p);
    }
 
    for (auto p : primes) {
        ll cost = 0;
        for (auto a : A) {
            ll x = a % p;
            cost += x < p - x && a >= p ? x : p - x;
            if (cost >= best)
                break;
        }
        best = min(best, cost);
    }
    cout << best;
}