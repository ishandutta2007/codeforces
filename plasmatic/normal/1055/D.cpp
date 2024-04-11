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

// gfg stuff
void computeLPSArray(const char* pat, int M, int* lps); 
  
// Prints occurrences of txt[] in pat[] 
int KMPSearch(const char* pat, const char* txt) 
{ 
    int M = strlen(pat); 
    int N = strlen(txt); 
  
    // create lps[] that will hold the longest prefix suffix 
    // values for pattern 
    int lps[M]; 
  
    // Preprocess the pattern (calculate lps[] array) 
    computeLPSArray(pat, M, lps); 

    int res = INF;
  
    int i = 0; // index for txt[] 
    int j = 0; // index for pat[] 
    while (i < N) { 
        if (pat[j] == txt[i]) { 
            j++; 
            i++; 
        } 
  
        if (j == M) { 
            mina(res, i - j); // 0-indexed
            j = lps[j - 1]; 
        } 
  
        // mismatch after j matches 
        else if (i < N && pat[j] != txt[i]) { 
            // Do not match lps[0..lps[j-1]] characters, 
            // they will match anyway 
            if (j != 0) 
                j = lps[j - 1]; 
            else
                i = i + 1; 
        } 
    } 

    return res == INF ? -1 : res;
} 
  
// Fills lps[] for given patttern pat[0..M-1] 
void computeLPSArray(const char* pat, int M, int* lps) 
{ 
    // length of the previous longest prefix suffix 
    int len = 0; 
  
    lps[0] = 0; // lps[0] is always 0 
  
    // the loop calculates lps[i] for i = 1 to M-1 
    int i = 1; 
    while (i < M) { 
        if (pat[i] == pat[len]) { 
            len++; 
            lps[i] = len; 
            i++; 
        } 
        else // (pat[i] != pat[len]) 
        { 
            // This is tricky. Consider the example. 
            // AAACAAAA and i = 7. The idea is similar 
            // to search step. 
            if (len != 0) { 
                len = lps[len - 1]; 
  
                // Also, note that we do not increment 
                // i here 
            } 
            else // if (len == 0) 
            { 
                lps[i] = 0; 
                i++; 
            } 
        } 
    } 
} 

const int MN = 3001;
int N,
    L[MN], R[MN];
string A[MN], B[MN];
bool same[MN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    scan(N);
    repi(0, N) 
        scan(A[i]);
    repi(0, N) 
        scan(B[i]);

    int replen = -1;
    string subFind, subRepl;
    repi(0, N) {
        if (A[i] == B[i]) {
            same[i] = true;
            continue;
        }

        L[i] = INF; R[i] = -1;
        int len = A[i].length();
        repj(0, len)
            if (A[i][j] != B[i][j])
                mina(L[i], j), maxa(R[i], j);
        
        if (replen == -1) {
            replen = R[i] - L[i] + 1;
            subFind = A[i].substr(L[i], replen);
            subRepl = B[i].substr(L[i], replen);
        }
        else {
            if (replen != R[i] - L[i] + 1 || 
                subFind != A[i].substr(L[i], replen) || 
                subRepl != B[i].substr(L[i], replen)) {
                println("NO");
                return 0;
            }
        }
    }

    bool good = true;
    do {
        char fst = 0;
        repi(0, N) {
            if (!same[i]) {
                if (!fst) fst = A[i][R[i] + 1];
                else good &= A[i][R[i] + 1] == fst;
                good &= R[i] < int(A[i].length()) - 1;
            }
        }
        if (good)
            repi(0, N)
                if (!same[i])
                    R[i]++;
    } while (good);

    good = true;
    do {
        char fst = 0;
        repi(0, N) {
            if (!same[i]) {
                if (!fst) fst = A[i][L[i] - 1];
                else good &= A[i][L[i] - 1] == fst;
                good &= L[i] > 0;
            }
        }
        if (good)
            repi(0, N)
                if (!same[i])
                    L[i]--;
    } while (good);
    // assert(0);

    repi(0, N) {
        if (!same[i]) {
            replen = R[i] - L[i] + 1;
            subFind = A[i].substr(L[i], replen);
            subRepl = B[i].substr(L[i], replen);
            break;
        }
    }

    // string is all same
    repi(0, N) {
        if (same[i]) {
            if (KMPSearch(subFind.c_str(), A[i].c_str()) != -1) {
                println("NO");
                return 0;
            }
        }
        else {
            // int ind = KMPSearch(A[i].c_str(), subFind.c_str());
            // db(i); db(A[i]); db(subFind); db(L[i]); db(R[i]); db(ind); dbln;
            if (KMPSearch(subFind.c_str(), A[i].c_str()) != L[i]) {
                println("NO");
                return 0;
            }
        }
    }

    // output
    println("YES");
    repi(0, N) {
        if (!same[i]) {
            println(A[i].substr(L[i], R[i] - L[i] + 1));
            println(B[i].substr(L[i], R[i] - L[i] + 1));
            return 0;
        }
    }

    return 0;
}