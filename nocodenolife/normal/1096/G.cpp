//#define DEBUG
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
using namespace std;

#define BSET(a, p) ((a) | (1ll << (p)))
#define BCHK(a, p) ((a) & (1ll << (p)))
#define BXOR(a, p) ((a) ^ (1ll << (p)));
#define BREM(a, p) (BCHK(a, p)?(BXOR(a, p)):(a))
#define BSHO(a, N) (bitset<N>(a))

#define fi first
#define sc second 
#define pb push_back


#ifdef DEBUG
    #define dbg(s) {s;}
    #define PRELUDE
#endif

#ifndef DEBUG 
    #define PRELUDE { ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0); }
    #define dbg(s)
    #define endl "\n"
#endif

#define int ll
#define i32 int32_t

#define RBTTYPE int
#define ordered_set tree<RBTTYPE, null_type, less<RBTTYPE>, rb_tree_tag,tree_order_statistics_node_update> 
// Ordered set docs:
// order_of_key (k) : Number of items strictly smaller than k .
// find_by_order(k) : K-th element in a set (counting from zero).

#define all(v) (v).begin(),(v).end()

typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;

// To remove randomization use 0 below:
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
inline int ri(int x) { // from [0, n-1]
    return uniform_int_distribution<int>(0, x - 1)(rng);
}

inline ld rf() { // from [0, 1]
    return uniform_real_distribution<ld>(0, 1)(rng);
}

ll gcd(ll x, ll y) {
    if (x < y) return gcd(y, x);
    if (y == 0) return x;
    return gcd(y, x % y);
} 

const ll mod = 998244353;

ll modexp(ll x, ll ex) {
    ll ans = 1ll;
    while (ex > 0) {
        if (ex & 1ll) ans = (ans * x) % mod;
        ex >>= 1ll;
        x = (x * x) % mod;
    }
    return ans;
}

const int maxn = 1e6 + 7;

const ll inf = 1e9 + 7;

const int i2 = (mod + 1) / 2;
// inverse of 2
const int N = 1 << 20;
// Keep always >= size of final polynomial
const int iN = modexp(N, mod - 2); // inverse of N
int resv[N];
int omega[21];
// omega[i] = 1^(1/(2^ i ) ) % mod => omega[i]^(2^i) = 1
int omegai[21];
// omegai[i] = 1/omega[i]
// A is the array whose fft is to be calculated. FFT(A)[j] is put in A[j ] itself .
// l is the left endpoint
// n is the log of the size of the array
// s is the step size
// So in the current recursion, the jth element corresponds to A[l + s  j ]
// If inv is set, the inverse fourier  N is computed. You need to divide everything by
// N to get the inverse fourier . This part is NOT DONE by the routine.
// See https :// codeforces.com/contest/1251/submission/63401447
// for its application in a real problem.
void fft ( int *A, int l , int n, int s, bool inv ) {
    if (n == 0) return;
    fft (A, l, n - 1, s + s, inv );
    fft (A, l+ s, n - 1, s+ s, inv );
    int N = 1 << n;
    int wn = inv ? omegai[n] : omega[n];
    int w1 = 1, w2 = mod - 1;
    for ( int j = 0; j < N / 2; j ++) {
        int x1 = l + s * j , x2 = l + s * j + s * N / 2;
        int y = l + (s + s) * j , z = l + (s + s) * j + s;
        resv[x1] = A[y] + w1 * A[z] % mod;
        resv[x1] %= mod;
        resv[x2] = A[y] + w2 * A[z] % mod;
        resv[x2] %= mod;
        w1 = w1 * wn % mod;
        w2 = w2 * wn % mod;
    }
    for ( int j = 0; j < N; j ++) {
        A[l + j * s] = resv[ l + j * s ];
    }
}


int n,k;
int pows[2][N];

void findPower()
{
    fft(pows[0],0,20,1,false);
    for(int i=0;i<N;i++)
    {
        pows[1][i] = modexp(pows[0][i],n/2);
    }
    fft(pows[1],0,20,1,true);
    for(int i=0;i<N;i++)
    {
        pows[1][i] *= iN;
        pows[1][i] %= mod;
    }
}

void solve()
{
    cin>>n>>k;
    int x;
    memset(pows,0,sizeof(pows));
    for(int i=0;i<k;i++)
    {
        cin>>x;
        pows[0][x] = 1;
    }
    /*for(int c =0;c<10;c++)
        cout<<pows[0][c]<<" ";
    cout<<endl;*/
    findPower();
    /*for(int c =0;c<30;c++)
        cout<<pows[1][c]<<" ";
    cout<<endl;*/
    int ans = 0;
    for(int i=0;i<N;i++)
    {
        x = pows[1][i]*pows[1][i];
        x%=mod;
        ans+=x;
        ans%=mod;
    }
    cout<<ans<<endl;
}

i32 main() {
    //freopen("<file>.in", "r", stdin);
    //freopen("<file>.out", "w", stdout);
    
    PRELUDE;
    omega[20] = 646ll;
// 2^20 th root of mod
    omegai[20] = 208611436ll; // 1/646 % mod
    for ( int j = 19; j >= 0; j--) {
        omega[j] = omega[j + 1] * omega[j + 1] % mod;
        omegai[j] = omegai[j + 1] * omegai[j + 1] % mod;
    }
    int t = 1;
    //cin>>t;
    while(t--)
        solve();
}