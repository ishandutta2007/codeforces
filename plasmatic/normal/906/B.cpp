#pragma region
#include <bits/stdc++.h>
using namespace std;
// Common Type shorteners and int128
using ll = long long; using ull = unsigned long long; using ld = long double;
using pii = pair<int, int>; using pll = pair<ll, ll>;
template <typename T> using vec = vector<T>;
template <typename K, typename V> using umap = unordered_map<K, V>; template <typename K> using uset = unordered_set<K>;
using vi = vec<int>; using vl = vec<ll>; using vpi = vec<pii>; using vpl = vec<pll>;
#ifdef __SIZEOF_INT128__
using int128 = __int128_t; using uint128 = __uint128_t;
#endif
template<typename I> string intStr(I x) { string ret; while (x > 0) { ret += (x % 10) + '0'; x /= 10; } reverse(ret.begin(), ret.end()); return ret; } // Int to string
// Shorthand Macros
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define mpr make_pair
#define mtup make_tuple
#define pb push_back
#define popcount __builtin_popcount
#define clz __builtin_clz
#define ctz __builtin_ctz
#define finline __attribute__((always_inline))
// Shorthand Function Macros
#define sz(x) ((int)((x).size()))
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (__typeof(a) i = a; i < b; i++)
#define reprev(i, a, b) for (__typeof(a) i = a; i > b; i--)
#define repi(a, b) rep(i, a, b)
#define repj(a, b) rep(j, a, b)
#define repk(a, b) rep(k, a, b)
#define Cmplt(type) bool operator<(const type &o) const
#define Cmpgt(type) bool operator>(const type &o) const
#define Cmpfn(name, type) bool name(const type &a, const type &b)
#define Inop(type) istream& operator>>(istream& in, type &o)
#define Outop(type) ostream& operator<<(ostream& out, type o)
#define Pow2(x) (1LL << (x))
#define scn(type, ...) type __VA_ARGS__; scan(__VA_ARGS__) // scn -> Short for SCan New
// Shorthand Functions
template<typename T> inline void maxa(T& st, T v) { st = max(st, v); }
template<typename T> inline void mina(T& st, T v) { st = min(st, v); }
inline void setprec(ostream& out, int prec) { out << setprecision(prec) << fixed; }
// Out operators and printing for arrays and vectors
template <typename T> ostream& operator<<(ostream& out,vector<T> iter){out<<"[";for(auto t:iter){out<<t<<", ";}out<<"]";return out;}
template <typename T> string arrayStr(T *arr,int sz){string ret = "[";for(int i=0;i<sz;i++){ret+=to_string(arr[i])+", "; } return ret + "]";}
template <typename T> void printArray(T *arr,int sz){for(int i=0;i<sz;i++){cout<<arr[i]<<" "; } cout<<"\n";}
// I/O Operations
inline void scan(){}
template<typename F, typename... R> inline void scan(F &f,R&... r){cin>>f;scan(r...);}
template <typename F> inline void println(F t){cout<<t<<'\n';}
template<typename F, typename... R> inline void println(F f,R... r){cout<<f<<" ";println(r...);}
inline void print(){}
template<typename F, typename... R> inline void print(F f,R... r){cout<<f;print(r...);}
// Debugging
#define db(x) cout << (#x) << ": " << (x) << ", "
#define dblb(s) cout << "[" << (s) << "] "
#define dba(alias, x) cout << (alias) << ": " << (x) << ", "
template<typename F> inline string __generic_tostring(F f) { stringstream ss; ss << f; return ss.str(); }
template<typename F> inline string __join_comma(F f) {return __generic_tostring(f);}
template<typename F, typename... R> string __join_comma(F f, R... r) { return __generic_tostring(f) + ", " + __join_comma(r...); }
#define dbp(alias, ...) cout << (alias) << ": (" << __join_comma(__VA_ARGS__) << "), "
#define dbbin(x, n) cout << (#x) << ": " << bitset<n>(x) << ", "
#define dbarr(x, n) cout << (#x) << ": " << arrayStr((x), (n)) << ", "
#define dbln cout << endl;
#pragma endregion

const int MN = 1e5 + 1;
int N, M;

int tmp[10], ans[10][10];
bool bad(int from, int to) {
    if (from < to) swap(from, to);
    if (M != 1 && (from - to) % M == 0) return true;
    if (to + 1 == from && (M == 1 || to % M != 0)) return true;
    return false;
}
bool check() {
    repi(0, N) {
        repj(0, M) {
            int val = ans[i][j];
            if (i > 0 && bad(ans[i - 1][j], val)) return false;
            if (i < N - 1 && bad(ans[i + 1][j], val)) return false;
            if (j > 0 && bad(ans[i][j - 1], val)) return false;
            if (j < M - 1 && bad(ans[i][j + 1], val)) return false;
        }
    }

    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    scan(N, M);

    if (N * M <= 10) {
        iota(tmp, tmp + (N * M), 1);
        do {
            int ptr = 0;
            repi(0, N)
                repj(0, M)
                    ans[i][j] = tmp[ptr++];
            if (check()) break;
        } while (next_permutation(tmp, tmp + (N * M)));

        if (!check())
            println("NO");
        else {
            println("YES");
            repi(0, N) {
                repj(0, M) print(ans[i][j], ' ');
                print('\n');
            }
        }

        return 0;
    }
    else {
        println("YES");
        if (N == 1) {
            int c = -1;
            while ((c += 2) <= M) print(c, ' ');
            c = 0;
            while ((c += 2) <= M) print(c, ' ');
            print('\n');
        }
        else if (M == 1) {
            int c = -1;
            while ((c += 2) <= N) println(c);
            c = 0;
            while ((c += 2) <= N) println(c);
        }
        else if (M == 2) {
            vi v;
            int cur = 1;
            while (cur <= N * M) {
                v.pb(cur);
                if (cur % 2) cur += 3;
                else cur++;
            }
            cur = 2;
            while (cur <= N * M) {
                v.pb(cur);
                if (cur % 2) cur += 3;
                else cur++;
            }
            int ptr = 0;
            repi(0, N) {
                repj(0, M) 
                    print(v[ptr++], ' ');
                print('\n');
            }
        }
        else if (N == 2 && M % 2) {
            vec<vi> ans(2, vi(M));
            repi(0, M) ans[0][i] = i * 2 + 1;
            repi(0, M) ans[1][i] = (M - i) * 2;
            repi(1, M) {
                if (abs(ans[0][i] - ans[1][i]) % M == 0) {
                    swap(ans[1][i - 1], ans[1][i]);
                }
            }
            repi(0, 2) {
                repj(0, M) print(ans[i][j], ' ');
                print('\n');
            }
            print('\n');
        }
        else if (M % 2) {
            if (N == 3) {
                vec<vi> ans(3, vi(M));
                int cur = 1, tt = N * M;
                repi(0, N) {
                    repj(0, M) {
                        ans[i][j] = cur;
                        cur += 2;
                        if (cur > tt) cur = 2;
                    }
                }

                repi(0, 2) {
                    repj(0, M - 1) {
                        if (abs(ans[i][j] - ans[i + 1][j]) == M) {
                            swap(ans[i + 1][j], ans[i + 1][j + 1]);
                        }
                    }
                }

                repi(0, N) {
                    repj(0, M) print(ans[i][j], ' ');
                    print('\n');
                }

                return 0;
            }
            int cur = 1, tt = N * M;
            // if (N % 2 == 0) {
                repi(0, N) {
                    repj(0, M) {
                        print(cur, ' ');
                        cur += 2;
                        if (cur > tt) cur = 2;
                    }
                    print('\n');
                }
                // return 0;
            // }
            // repi(0, N) {
            //     if (i % 2) {
            //         repj(i < N - 1 ? 2 : 0, M) {
            //             print(cur, ' ');
            //             cur += 2;
            //             if (cur % M <= 1 && cur != tt) {
            //                 cur += 2;
            //             }
            //             if (cur > tt) {
            //                 cur -= tt;
            //                 if (cur == 3) cur--;
            //             }
            //         }
            //         if (i < N - 1)
            //             print((i + 1) * M, ' ', (i + 1) * M + 1, ' ');
            //     }
            //     else {
            //         if (i < N - 1)
            //             print((i + 1) * M, ' ', (i + 1) * M + 1, ' ');
            //         repj(i < N - 1 ? 2 : 0, M) {
            //             print(cur, ' ');
            //             cur += 2;
            //             if (cur % M <= 1 && cur != tt) {
            //                 cur += 2;
            //             }
            //             if (cur > tt) {
            //                 cur -= tt;
            //                 if (cur == 3) cur--;
            //             }
            //         }
            //     }
            //     print('\n');
            // }            
        }
        else {
            if (N % 2 == 0) {
                int l = 1, r = N * M;
                repi(0, N) {
                    repj(0, M) {
                        if (j % 2) print(r--, ' ');
                        else print(l++, ' ');
                    }
                    print('\n');
                }
                return 0;
            }

            // N is odd, M is even
            int octr = -1, ectr = 0;
            repi(0, N - 1) {
                vi val;
                if (i % 2 == 0) {
                    repj(0, M)
                        val.pb(octr += 2);
                }
                else {
                    repj(0, M)
                        val.pb(ectr += 2);
                    reverse(all(val));
                }
                repj(0, M)
                    print(val[j], ' ');
                print('\n');
            }

            int cur = N * M - 1;
            repj(0, M / 2) {
                print(cur, ' '); cur -= 2;
            }
            cur = N * M;
            repj(0, M / 2) {
                print(cur, ' '); cur -= 2;
            }
            print('\n');

            // int l = 1, r = N * M, ctr = 0;
            // repi(0, N) {
            //     repj(0, M) {
            //         if (i == 0 && j == 0) {
            //             print(N * M / 2, ' ');
            //             continue;
            //         }
            //         if (i == N - 1 && j == M - 1) {
            //             print(N * M / 2 + 1, ' ');
            //             continue;
            //         }
            //         if (ctr % 2) print(r--, ' ');
            //         else print(l++, ' ');
            //         ctr++;
            //     }
            //     print('\n');
            // }
            // int ctr = 1;
            // repi(0, N) {
            //     vi row;
            //     repj(0, M) {
            //         row.pb(ctr);
            //         ctr += 2;
            //         if (ctr > N * M)
            //             ctr = 2;
            //     }
            //     // db(i); db(row); dbln;
            //     if (i % 2) { reverse(all(row)); }
            //     repj(0, M)
            //         print(row[j], ' ');
            //     print('\n');
            // }            
        }
    }

    return 0;
}