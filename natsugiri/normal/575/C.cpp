#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;
//TEMPLATE {{{
typedef long long lint;
typedef unsigned long long ulint;
typedef long double ldouble;

#define rep(i, n)         for(int i = 0; i < (int)(n); i++)
#define all(c)           (c).begin(), (c).end()
#define perm(c)          sort(all(c)); for(bool _b = true; _b; _b = next_permutation(all(c)))
#define uniquenize(v)    (v).erase(unique(all(v)), (v).end())
#define sz(c)            int((c).size())

#ifdef HIBIKICHAN
#include <dumper.hpp>
#define dump(x) dumper::dumper(cerr, __LINE__, (#x), (x), 50, 1, 1)
#else
#define dump(x)
#endif

#if defined(_WIN32) || defined(__CYGWIN__)
inline int stoi(const string &s){return atoi(s.c_str());}
inline long long stoll(const string &s){return atoll(s.c_str());}

#endif

//}}}

inline int fastMin(int x, int y) { return (((y - x) >> (32 - 1))&(x^y)) ^ x; }

int A[2][22][22];
int a[22][22];
int fx[22], fy[22];
int x[22], y[22];
int t[22], s[22];
int n, p, q;

const int INF = 1e9;
inline int calc(int S){
    rep(i, n){
        fx[i] = INF; fy[i] = 0;
        x[i] = -1; y[i] = -1;
    }

    rep(i, n) rep(j, n) a[i][j] = A[(S>>i)&1][i][j];
    rep(i, n){
        rep(j, n) fx[i] = max(fx[i], a[i][j]);
    }

    for(int i = 0; i < n; ){
        rep(j, n){
            t[j] = -1;
            s[j] = i;
        }
        s[n] = i;

        for(p = q = 0; p <= q && x[i] < 0; p++){
            for(int k = s[p], j = 0; j < n && x[i] < 0; j++){
                if(fx[k] + fy[j] == a[k][j] && t[j] < 0){
                    s[++q] = y[j], t[j] = k;
                    if(s[q] < 0){
                        for(p = j; p >= 0; j = p){
                            y[j] = k = t[j], p = x[k], x[k] = j;
                        }
                    }
                }
            }
        }

        if(x[i] < 0){
            int d = INF;
            for(int k = 0; k <= q; k++){
                for(int j = 0; j < n; j++){
                    if(t[j] < 0) d = fastMin(d, fx[s[k]] + fy[j] - a[s[k]][j]);
                }
            }

            rep(j, n) fy[j] += (t[j] < 0 ? 0 : d);
            for(int k = 0; k <= q; k++) fx[s[k]] -= d;
        } else {
            i++;
        }
    }

    int res = 0;
    rep(i, n) res += a[i][x[i]];
    return res;
}

int main(){
    cin >> n;
    rep(k, 2) rep(i, n) rep(j, n) cin >> A[k][i][j];

    int U = (1<<n);

    vector<int> AAA;
    for(int S = 0; S < U; S++){
        if(__builtin_popcount(S)*2 != n) continue;
        AAA.push_back(S);
    }

    srand(364);
    random_shuffle(all(AAA));

    int start = clock();
    int ans = 0;
    for(int i = 0; i < sz(AAA); i++){
        if((i & 7) == 0) if(clock() - start >= 1970) break;
        ans = max(ans, calc(AAA[i]));
    }
    cout << ans << endl;
}