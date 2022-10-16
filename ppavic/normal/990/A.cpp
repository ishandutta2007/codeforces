#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <iostream>
#include <ctime>

#define X first
#define Y second
#define MP make_pair
#define PB push_back

using namespace std;

typedef long long ll;
typedef pair < int, int> pii;
typedef pair < ll, ll> pll;
typedef vector < int > vi;
typedef vector < ll > vll;
typedef pii pt;

const int N = 1e5 + 500;
const int M = 1e6 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int BASE = 31337;
const int LOG = 18;
const int OFF = (1 << LOG);
const double EPS = 1e-9;
const double PI = 3.1415926535;

ll n, m, a , b;

int main(){
    cin >> n >> m >> a >> b;
    cout << min((n % m) * b , (m - (n % m)) % m * a) << endl;
    return 0;
}