/*
    author:  Maksim1744
    created: 25.12.2020 17:10:49
*/

#include "bits/stdc++.h"

using namespace std;

#define ll   long long
#define ld   long double

#define mp   make_pair
#define pb   push_back
#define eb   emplace_back

#define sum(a)     ( accumulate ((a).begin(), (a).end(), 0ll))
#define mine(a)    (*min_element((a).begin(), (a).end()))
#define maxe(a)    (*max_element((a).begin(), (a).end()))
#define mini(a)    ( min_element((a).begin(), (a).end()) - (a).begin())
#define maxi(a)    ( max_element((a).begin(), (a).end()) - (a).begin())
#define lowb(a, x) ( lower_bound((a).begin(), (a).end(), (x)) - (a).begin())
#define uppb(a, x) ( upper_bound((a).begin(), (a).end(), (x)) - (a).begin())

template<typename T>             vector<T>& operator--            (vector<T>& v){for (auto& i : v) --i;            return  v;}
template<typename T>             vector<T>& operator++            (vector<T>& v){for (auto& i : v) ++i;            return  v;}
template<typename T>             istream& operator>>(istream& is,  vector<T>& v){for (auto& i : v) is >> i;        return is;}
template<typename T>             ostream& operator<<(ostream& os,  vector<T>& v){for (auto& i : v) os << i << ' '; return os;}
template<typename T, typename U> istream& operator>>(istream& is, pair<T, U>& p){is >> p.first >> p.second;        return is;}
template<typename T, typename U> ostream& operator<<(ostream& os, pair<T, U>& p){os << p.first << ' ' << p.second; return os;}
template<typename T, typename U> pair<T,U> operator-(pair<T,U> a, pair<T,U> b){return mp(a.first-b.first, a.second-b.second);}
template<typename T, typename U> pair<T,U> operator+(pair<T,U> a, pair<T,U> b){return mp(a.first+b.first, a.second+b.second);}
template<typename T, typename U> void umin(T& a, U b){if (a > b) a = b;}
template<typename T, typename U> void umax(T& a, U b){if (a < b) a = b;}

#ifdef HOME
#define TAG_LENGTH       25
#define LR_LEFT          left
#define LR_RIGHT         right
#define LR_VALUE         value
#define LR_SECOND_VALUE  mn
#include "C:/C++ libs/print.cpp"
#else
#define showl            42;
#define shows            42;
#define show(...)        42;
#define showm(...)       42;
#define showt(...)       42;
#define printTree(...)   42;
#define printGraph(...)  42;
#define printLRTree(...) 42;
#define printMatrix(...) 42;
#define printWGraph(...) 42;
#define debug     if (false)
#endif

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll rnd (ll l, ll r) { return (ll)(rng() % (r - l + 1)) + l; }
ll rnd (ll r)       { return rng() % r; }
ll rnd ()           { return rng(); }
ld rndf()           { return (ld)rng() / (ld)ULLONG_MAX; }
ld rndf(ld l, ld r) { return rndf() * (r - l) + l; }

using ull = unsigned long long;

ull mul_mod(ull a, ull b, ull mod) {
    return (__uint128_t)a * (__uint128_t)b % mod;
    // ull res = 0;
    // while (b) {
    //     if (b & 1) {
    //         res += a;
    //         if (res >= mod)
    //             res -= mod;
    //     }
    //     b >>= 1;
    //     a <<= 1;
    //     if (a >= mod)
    //         a -= mod;
    // }
    // return res;
}

double ttm = 0;

ll get_divisor(ll n) {
    // maybe check divisors <= 1000 to speed up
    auto f = [&](ll x) {
        return (mul_mod(x, x, n) + 1) % n;
    };
    while (true) {
        ll x = rnd(1, n - 1);
        ll y = f(x);
        int cnt = 0;
        while (x % n != y % n && ++cnt < 30000) {
            ll d = gcd(n, abs(x - y));
            if (d == 0)
                break;
            else if (d != 1)
                return d;
            x = f(x);
            y = f(f(y));
        }
    }
}

// copy mul_mod from rho_pollard
ull mpow_long(ull a, ull p, ull mod) {
    ull res = 1;
    while (p) {
        if (p & 1) res = mul_mod(res, a, mod);
        p >>= 1;
        a = mul_mod(a, a, mod);
    }
    return res;
}

bool is_prime(ull n) {
    if (n < 2)
        return false;
    // maybe check divisors <= 1000 to speed up
    int s = 0;
    ull d = n - 1;
    while (d % 2 == 0) {
        ++s;
        d >>= 1;
    }
    int k = 60;  // log n
    for (int ii = 0; ii < k; ++ii) {
        ull a = rnd(2, n - 2);
        ull x = mpow_long(a, d, n);
        if (x == 1 || x == n - 1)
            continue;
        bool composite = true;
        for (int i = 0; i < s - 1; ++i) {
            x = mul_mod(x, x, n);
            if (x == 1)
                return false;
            if (x == n - 1) {
                composite = false;
                break;
            }
        }
        if (composite)
            return false;
    }
    return true;
}

ll get_prime_divisor(ll n) {
    ll p = n;
    while (!is_prime(p)) {
        auto start_time = clock();
        p = get_divisor(p);
        ttm += (double)(clock() - start_time) / CLOCKS_PER_SEC;
    }
    return p;
}

const ll N = 1e5;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    vector<bool> isp(N, true); isp[0] = isp[1] = false;
    for (int i = 2; i * i < N; ++i)
        if (isp[i])
            for (int j = i * i; j < N; j += i)
                isp[j] = false;

    vector<ll> primes;
    for (int i = 0; i < N; ++i)
        if (isp[i])
            primes.pb(i);

    int n, k;
    cin >> n >> k;
    vector<pair<ll, vector<ll>>> nums(n);

    vector<bool> wtf(n, false);

    for (int i = 0; i < n; ++i) {
        cin >> nums[i].first;
        ll k = nums[i].first;
        for (auto p : primes) {
            if (k == 1) break;
            if (p * p > k) {
                nums[i].second.pb(k);
                k = 1;
                break;
            }
            if (k % p == 0) {
                while (k % p == 0)
                    k /= p;
                nums[i].second.pb(p);
            }
        }

        if (k == 1) continue;

        for (int ii = 0; ii < 2; ++ii) {
            ll l = 1, r = (ll)sqrt(k) + 5;
            while (r - l > 1) {
                ll c = (l + r) / 2;
                if (c * c <= k)
                    l = c;
                else
                    r = c;
            }
            if (l * l == k) {
                k = l;
            } else {
                break;
            }
        }
        {
            ll l = 1, r = (ll)sqrt(k) + 5;
            while (r - l > 1) {
                ll c = (l + r) / 2;
                if (c * c * c <= k)
                    l = c;
                else
                    r = c;
            }
            if (l * l * l == k) {
                k = l;
            }
        }

        if (is_prime(k)) {
            nums[i].second.pb(k);
            continue;
        }

        wtf[i] = true;
        continue;

        while (k != 1) {
            assert(k > 1);
            if (N * N > k) {
                nums[i].second.pb(k);
                break;
            }
            ll p = get_prime_divisor(k);
            k /= p;
            assert(p != 1);
            nums[i].second.pb(p);
        }
        sort(nums[i].second.begin(), nums[i].second.end());
        nums[i].second.erase(unique(nums[i].second.begin(), nums[i].second.end()), nums[i].second.end());
    }
    cerr << ttm << endl;
    map<ll, vector<int>> pr;
    vector<int> comp;

    vector<bool> bad(n, false);

    vector<ll> other_primes = primes;
    for (int i = 0; i < n; ++i) {
        if (!wtf[i] && nums[i].second.size() == 1) {
            other_primes.pb(nums[i].second[0]);
            // cerr << "+ " << nums[i].second[0] << endl;
        }
    }
    sort(other_primes.begin(), other_primes.end());
    other_primes.erase(unique(other_primes.begin(), other_primes.end()), other_primes.end());

    for (int i = 0; i < n; ++i) {
        if (wtf[i]) {
            nums[i].second.clear();
            ll k = nums[i].first;
            for (auto p : other_primes) {
                if (k == 1) break;
                if (k % p == 0) {
                    while (k % p == 0)
                        k /= p;
                    nums[i].second.pb(p);
                }
            }
            // cerr << k << ' ' << nums[i].second << endl;
            if (k != 1) {
                bad[i] = true;
            } else {
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        if (bad[i]) continue;
        if (nums[i].second.size() == 1) {
            if (pr[nums[i].second[0]].size() < 2)
                pr[nums[i].second[0]].pb(i);
        }
    }

    for (int i = 0; i < n; ++i) {
        if (bad[i]) continue;
        for (auto p : nums[i].second) {
            if (pr[p].size() < 2) {
                bad[i] = true;
                break;
            }
        }
    }

    comp.clear();
    pr.clear();

    for (int i = 0; i < n; ++i) {
        if (bad[i]) continue;
        if (nums[i].second.size() == 1) {
            if (pr[nums[i].second[0]].size() < 2)
                pr[nums[i].second[0]].pb(i);
            else
                comp.pb(i);
        } else {
            comp.pb(i);
        }
    }

    vector<int> ans;
    vector<bool> u(n, false);

    if (k % 2 == 1) {
        int mn = 1e8;
        int ind = -1;
        for (int i : comp) {
            if (nums[i].second.size() < mn) {
                mn = nums[i].second.size();
                ind = i;
            }
        }
        if (mn * 2 + 1 > k) {
            cout << 0 << '\n';
            return 0;
        }
        ans.pb(ind);
        --k;
        u[ind] = true;
        for (auto p : nums[ind].second) {
            for (auto j : pr[p]) {
                ans.pb(j);
                u[j] = true;
                --k;
            }
        }
    }

    for (auto [pp, v] : pr) {
        assert(v.size() == 2);
        assert(u[v[0]] == u[v[1]]);
        if (u[v[0]]) continue;
        if (k == 0) break;
        for (auto j : v) {
            u[j] = true;
            --k;
            ans.pb(j);
        }
    }

    for (auto i : comp) {
        if (u[i]) continue;
        if (k == 0) break;
        --k;
        ans.pb(i);
        u[i] = true;
    }

    if (k != 0) {
        cout << 0 << '\n';
        return 0;
    }

    for (auto i : ans) {
        cout << nums[i].first << ' ';
    }
    cout << '\n';

    return 0;
}