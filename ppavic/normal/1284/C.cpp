#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>

#define X first
#define Y second
#define PB push_back

using namespace std;

typedef long long ll;
typedef pair < int , int > pii;
typedef pair < ll, ll > pll;
typedef vector < int > vi;

const int N = 3e5 + 500;
const int M = 1e6 + 500;
const int INF = 0x3f3f3f3f;

int MOD;

inline int add(int A,int B){
    if(A + B >= MOD) return A + B - MOD;
    return A + B;
}

inline int mul(int A,int B){
    return (ll)A * B % MOD;
}

int fak[N], n;

int main(){
    scanf("%d%d", &n, &MOD);
    fak[0] = 1;
    for(int i = 1;i < N;i++)
        fak[i] = mul(i, fak[i - 1]);

    int sol = 0;
    for(int len = 1;len <= n;len++){
        sol = add(sol, mul(mul(n - len + 1, n - len + 1), mul(fak[n - len], fak[len])));
    }
    printf("%d\n", sol);
    return 0;
}