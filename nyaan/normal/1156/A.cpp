#define _GLIBCXX_DEBUG
#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdarg>
#include <cstdio>
#include <cstring>
#include <deque>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;

#define whlie while
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define inf 1001001001
#define mod 1000000007
#define FOR(i,a,b) for(int (i)=((int)a); (i)<((int)b); (i)++) // [a,b)
#define rep(i,N) FOR((i), 0, ((int)N)) // [0,N)
#define all(v) (v).begin(),(v).end()
#define sz(v) ((int)(v).size())
#define inx(t,...) t __VA_ARGS__; in(__VA_ARGS__)
#define ini(...) int __VA_ARGS__; in(__VA_ARGS__)
#define inl(...) ll __VA_ARGS__; in(__VA_ARGS__)
#define inc(...) char __VA_ARGS__; in(__VA_ARGS__)
#define ins(...) string __VA_ARGS__; in(__VA_ARGS__)
#define ind(...) double __VA_ARGS__; in(__VA_ARGS__)
#define inpii(...) pii __VA_ARGS__; in(__VA_ARGS__)
#define invi(v,...) vi v; in(v,##__VA_ARGS__)
#define invl(v,...) vl v; in(v,##__VA_ARGS__)

// 
// dbg(...) printf 
// trc(var) ()=()
// stopif(val) 
// vd(v,N) v

#ifdef LOCAL
    #define dbg(...) fprintf(stderr, __VA_ARGS__)
    #define trc(...) cout << #__VA_ARGS__ << "="; dbg_out(__VA_ARGS__)
    #define stopif(val) assert( !(val) )
    #define vdbg(v,...) cout << #v << "={"; vector_debug(v , ##__VA_ARGS__)
#else
    #define dbg(...) 1
    #define trc(...) 1
    #define stopif(...) 1
    #define vdbg(...) 1
#endif

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef vector<pii> vpii;
typedef vector< vector<int> > vvi;
int gcd(int a, int b){if(a>b) swap(a,b); return a==0 ? b : gcd(b%a,a);} ll gcd(ll a, ll b){if(a>b) swap(a,b); return a==0 ? b : gcd(b%a,a);}
template<typename T, typename U> inline bool amin(T &x, U y) { return (y < x) ? (x = y, true) : false; }
template<typename T, typename U> inline bool amax(T &x, U y) { return (x < y) ? (x = y, true) : false; }
template<typename C> inline void _cin(C &c){cin >> c;} template<typename T,typename U> inline void _cin(pair<T,U> &p){cin >> p.fi; cin >> p.se;}
template<typename C> inline void _cout(const C &c){cout << c;} template<typename T,typename U> inline void _cout(const pair<T,U> &p){cout << p.fi << ' ' << p.se;}
void in(){} template <typename T,class... U> void in(T &t,U &...u){ _cin(t); in(u...);}
void out(){cout << endl;} template <typename T,class... U> void out(const T &t,U ...u){ _cout(t); if(sizeof...(u)) cout << ' '; out(u...);}
void dbg_out(){cout << endl;} template <typename T,class... U> void dbg_out(const T &t,U ...u){ _cout(t); if(sizeof...(u)) cout << ','; out(u...);}
template<typename C> inline void in(vector<C> &v,int N=-1){if(sz(v) != 0){int M=(N == -1) ? sz(v) : N; rep(i,M) _cin(v[i]);}else{C c;rep(i,N) v.pb((_cin(c),c));}} template<typename C> inline void in(C v[],int N){rep(i,N) _cin(v[i]);}
template<typename C> inline void out(const vector<C> &v,int N=-1){int M=(N == -1) ? sz(v) : N; rep(i,M) {cout<<( (i)?" ":"" ); _cout(v[i]);} cout<<endl; } template<typename C> inline void out(C v[],int N){rep(i,N) {cout<<( (i)?" ":"" ); _cout(v[i]);} cout<<endl; }
template<typename C> inline void vector_debug(const vector<C> &v,int N=-1){int M=(N == -1) ? sz(v) : N; rep(i,M) {cout<<( (i)?", ":"" ); _cout(v[i]);} cout<<"}"<<endl; } template<typename C> inline void vector_debug(C v[], int N){rep(i,N) {cout<<((i)?", ":""); _cout(*(v+i));} cout<<"}"<<endl;}
template<typename C> inline C vmax(const vector<C> &v){C n=v[0]; rep(i,sz(v)) amax(n,v[i]); return n;} template<typename C> inline C vmax(C v[], int N){C n=v[0]; rep( i , N ) amax(n,v[i]); return n;}
template<typename C> inline C vmin(const vector<C> &v){C n=v[0]; rep(i,sz(v)) amin(n,v[i]); return n;} template<typename C> inline C vmin(C v[], int N){C n=v[0]; rep( i , N ) amin(n,v[i]); return n;}
template<typename C> inline C vsum(const vector<C> &v){C n=0; rep(i,sz(v)) n+=v[i]; return n;} template<typename C> inline C vsum(C v[], int N){C n=0; rep( i , N ) n+=v[i]; return n;}
const int dx[]={1,0,-1,0}; const int dy[]={0,1,0,-1};
//const int dx[]={1,1,1,0,-1,-1,-1,0}; const int dy[]={1,0,-1,-1,-1,0,1,1};

// ini(A,B,C) => int A,B,C; cin >> A >> B >> C; 
// in(A,B,C) => cin >> A >> B >> C;   invi(v,N) =>vi v; rep(i,N) v.pb( (int x,cin >> x,x) );
// out(A,B,C) cout << A << ' ' <<  B << ' ' << C;
// in,outpair()
// amax(x,y) boolx<yxytrue

int main(){
    ini(N);
    invi(v,N);
    int flg = 1;
    int ans = 0;
    for(int i=1; i<N;i++){
        if(v[i-1] == 1){
            if(v[i] == 2){
                if((i-2 >= 0 && v[i-2] == 3))ans += 2;
                else ans += 3;
            }
            else ans += 4; 
        }
        if(v[i-1] == 2){
            if(v[i] == 1) ans += 3;
            else{
                flg = 0;
                break;
            }
        }
        if(v[i-1] == 3){
            if(v[i] == 1){
                ans += 4;
            }
            else{
                flg = 0;
                break;
            }
        }
    }
    if(flg){
        out("Finite"); out(ans);
    }
    else{
        out("Infinite");
    }
}