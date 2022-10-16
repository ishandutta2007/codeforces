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

const int N = 3e5 + 500;
const int M = 1e6 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int LOG = 20;
const int OFF = (1 << LOG);
const double PI = 3.1415926535;
const double EPS = 1e-9;

int n;
vector < ll > sol;

ll get(ll i, ll n){
    return (ll)n / (ll)i + (ll)(n / i) * (ll)(n / i - 1) * (ll)(i) / 2LL;
}

int main(){
    scanf("%d", &n);
    for(int i = 1;i * i<=n;i++){
        if(n % i) continue;
        sol.push_back(get(i, n));
        sol.push_back(get(n / i, n));
    }
    sort(sol.begin(), sol.end());
    sol.erase(unique(sol.begin(), sol.end()), sol.end());
    for(int i = 0;i<sol.size();i++){
        printf("%lld ", sol[i]);
    }
    printf("\n");
    return 0;
}