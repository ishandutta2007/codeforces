#line 2 "/home/nok0/documents/programming/library/math/osa_k.hpp"
#include <vector>

struct osa_k {
   private:
	std::vector<int> spf, pr;

   public:
	osa_k() = default;

	osa_k(int MAX) : spf(MAX + 1) {
		for(int i = 2; i <= MAX; i++) {
			if(spf[i] == 0) {
				spf[i] = i;
				pr.push_back(i);
			}
			for(int j = 0; j < pr.size() and pr[j] <= spf[i] and i * pr[j] <= MAX; j++)
				spf[i * pr[j]] = pr[j];
		}
	}

	std::vector<std::pair<int, int>> PF(int n) {
		std::vector<std::pair<int, int>> divisor;
		if(n == 1) return divisor;
		int before = spf[n], cnt = 0;
		while(n > 1) {
			if(spf[n] == before) {
				cnt++;
				n /= spf[n];
			} else {
				divisor.emplace_back(before, cnt);
				before = spf[n];
				cnt = 1;
				n /= spf[n];
			}
		}
		divisor.emplace_back(before, cnt);
		return divisor;
	}

	int smallestprimefactor(const int n) const {
		return spf[n];
	}

	bool isPrime(const int n) const {
		return n == spf[n];
	}
};
#line 2 "/home/nok0/documents/programming/library/template/header.hpp"
#include <bits/stdc++.h>
#line 3 "/home/nok0/documents/programming/library/template/def_name.hpp"

#define pb        push_back
#define eb        emplace_back
#define SZ(x)     ((int)(x).size())
#define all(x)    (x).begin(), (x).end()
#define rall(x)   (x).rbegin(), (x).rend()
#define popcnt(x) __builtin_popcountll(x)
template<class T = int>
using V = std::vector<T>;
template<class T = int>
using VV = std::vector<std::vector<T>>;
template<class T>
using pqup = std::priority_queue<T, std::vector<T>, std::greater<T>>;
using ll = long long;
using ld = long double;
using int128 = __int128_t;
using pii = std::pair<int, int>;
using pll = std::pair<long long, long long>;
#line 3 "/home/nok0/documents/programming/library/template/input.hpp"

template<class T, class U>
std::istream &operator>>(std::istream &is, std::pair<T, U> &p) {
    is >> p.first >> p.second;
    return is;
}
template<class T>
std::istream &operator>>(std::istream &is, std::vector<T> &v) {
    for (T &i : v) is >> i;
    return is;
}
std::istream &operator>>(std::istream &is, __int128_t &a) {
    std::string s;
    is >> s;
    __int128_t ret = 0;
    for (int i = 0; i < (int)s.length(); i++)
        if ('0' <= s[i] and s[i] <= '9')
            ret = 10 * ret + s[i] - '0';
    a = ret * (s[0] == '-' ? -1 : 1);
    return is;
}
namespace scanner {
void scan(int &a) { std::cin >> a; }
void scan(long long &a) { std::cin >> a; }
void scan(std::string &a) { std::cin >> a; }
void scan(char &a) { std::cin >> a; }
void scan(char a[]) { std::scanf("%s", a); }
void scan(double &a) { std::cin >> a; }
void scan(long double &a) { std::cin >> a; }
template<class T, class U>
void scan(std::pair<T, U> &p) { std::cin >> p; }
template<class T>
void scan(std::vector<T> &a) { std::cin >> a; }
void INPUT() {}
template<class Head, class... Tail>
void INPUT(Head &head, Tail &...tail) {
    scan(head);
    INPUT(tail...);
}
}  // namespace scanner
#define VEC(type, name, size)     \
    std::vector<type> name(size); \
    scanner::INPUT(name)
#define VVEC(type, name, h, w)                                    \
    std::vector<std::vector<type>> name(h, std::vector<type>(w)); \
    scanner::INPUT(name)
#define INT(...)     \
    int __VA_ARGS__; \
    scanner::INPUT(__VA_ARGS__)
#define LL(...)            \
    long long __VA_ARGS__; \
    scanner::INPUT(__VA_ARGS__)
#define STR(...)             \
    std::string __VA_ARGS__; \
    scanner::INPUT(__VA_ARGS__)
#define CHAR(...)     \
    char __VA_ARGS__; \
    scanner::INPUT(__VA_ARGS__)
#define DOUBLE(...)     \
    double __VA_ARGS__; \
    scanner::INPUT(__VA_ARGS__)
#define LD(...)              \
    long double __VA_ARGS__; \
    scanner::INPUT(__VA_ARGS__)
#line 3 "/home/nok0/documents/programming/library/template/output.hpp"


template<class T, class U>
std::ostream &operator<<(std::ostream &os, const std::pair<T, U> &p) {
    os << p.first << " " << p.second;
    return os;
}
template<class T>
std::ostream &operator<<(std::ostream &os, const std::vector<T> &a) {
    for (int i = 0; i < int(a.size()); ++i) {
        if (i) os << " ";
        os << a[i];
    }
    return os;
}
std::ostream &operator<<(std::ostream &dest, __int128_t &value) {
    std::ostream::sentry s(dest);
    if (s) {
        __uint128_t tmp = value < 0 ? -value : value;
        char buffer[128];
        char *d = std::end(buffer);
        do {
            --d;
            *d = "0123456789"[tmp % 10];
            tmp /= 10;
        } while (tmp != 0);
        if (value < 0) {
            --d;
            *d = '-';
        }
        int len = std::end(buffer) - d;
        if (dest.rdbuf()->sputn(d, len) != len) {
            dest.setstate(std::ios_base::badbit);
        }
    }
    return dest;
}
template<class T>
void print(const T a) { std::cout << a << '\n'; }
template<class Head, class... Tail>
void print(Head H, Tail... T) {
    std::cout << H << ' ';
    print(T...);
}
template<class T>
void printel(const T a) { std::cout << a << '\n'; }
template<class T>
void printel(const std::vector<T> &a) {
    for (const auto &v : a)
        std::cout << v << '\n';
}
template<class Head, class... Tail>
void printel(Head H, Tail... T) {
    std::cout << H << '\n';
    printel(T...);
}
void Yes(const bool b = true) { std::cout << (b ? "Yes\n" : "No\n"); }
void No() { std::cout << "No\n"; }
void YES(const bool b = true) { std::cout << (b ? "YES\n" : "NO\n"); }
void NO() { std::cout << "NO\n"; }
#line 2 "/home/nok0/documents/programming/library/template/rep.hpp"

#define foa(v, a)                   for (auto &v : a)
#define repname(a, b, c, d, e, ...) e
#define rep(...)                    repname(__VA_ARGS__, rep3, rep2, rep1, rep0)(__VA_ARGS__)
#define rep0(x)                     for (int rep_counter = 0; rep_counter < (x); ++rep_counter)
#define rep1(i, x)                  for (int i = 0; i < (x); ++i)
#define rep2(i, l, r)               for (int i = (l); i < (r); ++i)
#define rep3(i, l, r, c)            for (int i = (l); i < (r); i += (c))

#define repsname(a, b, c, ...) c
#define reps(...)              repsname(__VA_ARGS__, reps1, reps0)(__VA_ARGS__)
#define reps0(x)               for (int reps_counter = 1; reps_counter <= (x); ++reps_counter)
#define reps1(i, x)            for (int i = 1; i <= (x); ++i)

#define rrepname(a, b, c, ...) c
#define rrep(...)              rrepname(__VA_ARGS__, rrep1, rrep0)(__VA_ARGS__)
#define rrep0(x)               for (int rrep_counter = (x)-1; rrep_counter >= 0; --rrep_counter)
#define rrep1(i, x)            for (int i = (x)-1; i >= 0; --i)
#line 6 "/home/nok0/documents/programming/library/template/all"
using namespace std;
#line 3 "b.cpp"

osa_k pf(100000);

int main() {
	INT(t);
	V<> divcnt(100001, 1);
	reps(i, 100000) {
		auto vec = pf.PF(i);
		for(auto [key, cnt] : vec) {
			divcnt[i] *= cnt + 1;
		}
	}

	while(t--) {
		VEC(int, a, 3);
		vector<int> cnt(1 << 3);
		VV<> candi(3);
		int res = 0;
		int gall = gcd(gcd(a[0], a[1]), a[2]);
		rep(i, 1, 1 << 3) {
			if(i == 1) {
				cnt[i] = divcnt[a[0]]
				         - divcnt[gcd(a[0], a[1])]
				         - divcnt[gcd(a[0], a[2])]
				         + divcnt[gall];
			}
			if(i == 2) {
				cnt[i] = divcnt[a[1]]
				         - divcnt[gcd(a[1], a[2])]
				         - divcnt[gcd(a[1], a[0])]
				         + divcnt[gall];
			}
			if(i == 4) {
				cnt[i] = divcnt[a[2]]
				         - divcnt[gcd(a[2], a[0])]
				         - divcnt[gcd(a[2], a[1])]
				         + divcnt[gall];
			}
			if(i == 3) {
				cnt[i] = divcnt[gcd(a[0], a[1])]
				         - divcnt[gall];
			}
			if(i == 5) {
				cnt[i] = divcnt[gcd(a[0], a[2])]
				         - divcnt[gall];
			}
			if(i == 6) {
				cnt[i] = divcnt[gcd(a[1], a[2])]
				         - divcnt[gall];
			}
			if(i == 7) {
				cnt[i] = divcnt[gall];
			}
			if(cnt[i]) {
				rep(j, 3) {
					if(i >> j & 1) candi[j].pb(i);
				}
			}
		}
		auto nhr = [](int n, int r) {
			ll ret = 1;
			n = n + r - 1;
			reps(i, r) {
				ret *= n + 1 - i;
				ret /= i;
			}
			return ret;
		};
		set<V<>> st;
		foa(u, candi[0]) {
			foa(v, candi[1]) {
				foa(x, candi[2]) {
					V<> tmp{u, v, x};
					sort(all(tmp));
					if(st.count(tmp)) continue;
					st.insert(tmp);
					if(tmp[0] == tmp[1]) {
						if(tmp[1] == tmp[2]) {
							res += nhr(cnt[tmp[0]], 3);
						} else {
							res += nhr(cnt[tmp[0]], 2) * cnt[tmp[2]];
						}
					} else {
						if(tmp[1] == tmp[2]) {
							res += nhr(cnt[tmp[1]], 2) * cnt[tmp[0]];
						} else {
							res += cnt[tmp[0]] * cnt[tmp[1]] * cnt[tmp[2]];
						}
					}
				}
			}
		}
		print(res);
	}
}