#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <deque>
#include <map>

#define X first
#define Y second
#define MP make_pair

using namespace std;

typedef long long ll;
typedef pair < int, int > pii;
typedef vector < int > vi;
typedef set < int > si;

const int N = 1e6 + 500;
const int M = 1e6 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;
const int LOG = 20;
const int OFF = (1 << LOG);
const double PI = 3.1415926535;
const double EPS = 1e-9;

int n, perm[N], inv[N];

inline int mul(int A,int B){
    return (ll)A * (ll)B % (ll)MOD;
}

inline int pot(int A,int B){
    int base = A, sol = 1;
    for(; B ; B >>= 1){
        if(B&1) sol = mul(sol, base);
        base = mul(base, base);
    }
    return sol;
}

void precompute(){
    perm[0] = 1;
    inv[0] = 1;
    for(int i = 1;i<N;i++){
        perm[i] = mul(perm[i - 1], i);
        inv[i] = pot(perm[i], MOD - 2);
    }
}

int choose(int n, int k){
    return mul(perm[n], mul(inv[k], inv[n - k]));
}


int main(){
    precompute();
    scanf("%d", &n);
    int sol = perm[n];
    for(int k = 1;k<n;k++){
        sol = (sol + mul(choose(n, k), mul((perm[k] - 1 + MOD) % MOD, perm[n - k]))) % MOD;
        //sol = (sol + mul(perm[n - k], perm[k]));
    }
    printf("%d\n", sol);
    return 0;
}