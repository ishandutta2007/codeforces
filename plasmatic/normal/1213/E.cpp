#include <bits/stdc++.h>

using namespace std;

// Common DS shorteners
using ll = long long; using ull = unsigned long long;
using pii = pair<int, int>; using pll = pair<ll, ll>;
template <typename T> using vec = vector<T>;
template <typename K, typename V> using mp = unordered_map<K, V>;
template <typename K> using us = unordered_set<K>;
using vi = vec<int>; using vl = vec<ll>; using vpi = vec<pii>; using vpl = vec<pll>;
// Shorthand Macros
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define mpr make_pair
#define pb push_back
// Shorthand Functions
template<typename T> inline void maxa(T& st, T v) { st = max(st, v); }
template<typename T> inline void mina(T& st, T v) { st = min(st, v); }
// Out operators and printing for arrays and vectors
template <typename T> ostream& operator<<(ostream& out,vector<T> iter){out<<"[";for(auto t:iter){out<<t<<", ";}out<<"]";return out;}
template <typename T> void printDebug(T *arr,int sz){cout<<"[";for(int i=0;i<sz;i++){cout<<arr[i]<<", "; } cout<<"]\n";}
template <typename T> void printArray(T *arr,int sz){for(int i=0;i<sz;i++){cout<<arr[i]<<" "; } cout<<"\n";}
#define OUT_OPERATOR(type, propa, propb) ostream& operator<<(ostream& out,type obj){out<<"("<<#propa<<"="<<obj. propa<<", "<<#propb<<"="<<obj. propb<<")";return out;}
// I/O Operations
inline void scan(){}
template<typename F, typename... R> inline void scan(F &f,R&... r){cin>>f;scan(r...);}
inline void println(){cout<<"\n";}
template<typename F, typename... R> inline void println(F f,R... r){cout<<f<<" ";println(r...);}
inline void print(){}
template<typename F, typename... R> inline void print(F f,R... r){cout<<f;print(r...);}
// Debugging
int di_; string dnms_, co_ = ",";
void debug_(){cout<<endl;}
template<typename F, typename... R>
void debug_(F f,R... r){int bc=0;while (bc != 0 || dnms_[di_] != ','){if (dnms_[di_] == '(') {bc++;}else if (dnms_[di_] == ')') {bc--;}cout << dnms_[di_++];}di_++;cout << ": " << f << ",";debug_(r...);}
#define debug(...) do{dnms_=#__VA_ARGS__+co_,di_=0,debug_(__VA_ARGS__);}while(0)

inline int let(char c) { return c - 'a'; }
inline char ulet(int x) { return x + 'a'; }

const int MX = 3;
int n;
bool block[MX][MX];
char s[2][2];
vi g[MX];

void dfs(int cur, int st) {

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    scan(n, s[0], s[1]);

    for (int i = 0; i < 2; i++) {
        int a = let(s[i][0]), b = let(s[i][1]);
        block[a][b] = true;
    }

    // Special case
    // ab, ac | bc, ba | cb, ca
    if (s[0][0] == s[1][0] && s[0][0] != s[0][1] && s[1][0] != s[1][1]) {
        vec<char> oths;
        for (int i = 0; i < 3; i++)
            if (ulet(i) != s[0][0])
                oths.pb(ulet(i));
        
        println("YES");
        for (int i = 0; i < n; i++)
            print(oths[0], oths[1]);
        for (int i = 0; i < n; i++)
            print(s[0][0]);
        print('\n');

        return 0;
    }

    for (int i = 0; i < 3; i++) {
        vec<char> ans;

        if (!block[i][i]) {
            for (int j = 0; j < n; j++)
                ans.pb(ulet(i));
            
            for (int j = 0; j < 3; j++) {
                if (j != i && !block[i][j]) {
                    int oth = -1;
                    for (int k = 0; k < 3; k++)
                        if (k != i && k != j)
                            oth = k;
                    
                    if (!block[j][oth] && !block[oth][j]) {
                        for (int k = 0; k < n; k++) {
                            ans.pb(ulet(j));
                            ans.pb(ulet(oth));
                        }

                        break;
                    }
                }
            }
        }
        else {
            continue;
        }

        if (ans.size() == (size_t)(3 * n)) {
            println("YES");
            for (auto x : ans)
                print(x);
            print('\n');

            return 0;
        }
    }

    println("NO\n");

    return 0;
}