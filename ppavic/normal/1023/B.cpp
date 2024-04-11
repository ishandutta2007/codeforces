#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <iostream>

#define PB push_back
#define MP make_pair
#define X first
#define Y second

using namespace std;

typedef long long ll;
typedef pair < int, int> pii;
typedef pair < ll, ll> pll;
typedef vector < int > vi;
typedef vector < ll > vl;

const int N = 1e5 + 500;
const int M = 1e6 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int LOG = 20;
const int OFF = (1 << LOG);
const double EPS = 1e-9;
const double PI = 3.1415926535;

ll n, m;

int main(){
    cin >> n >> m;
    ll sol;
    if(n >= m) {
        sol = m / 2;
        if(m % 2LL == 0LL) sol--;
    }
    if(n < m){
        ll x = m - n;
        if(x >= n) sol = 0;
        else{
            sol = (n - x + 1) / 2LL;
        }
    }
    cout << sol << endl;
    return 0;
}