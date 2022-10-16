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

int n, k, bio[2 * M + 10];
vi v;

int main(){
    scanf("%d%d", &n, &k);
    for(int i = 0;i<n;i++){
        int x;scanf("%d", &x);
        v.PB(x);
        bio[x]++;
    }
    for(int i = 1;i<2 * M;i++){
        bio[i] += bio[i - 1];
    }
    int sol = 0;
    for(int i = 0;i<v.size();i++){
        if((bio[v[i] + k] - bio[v[i]]) == 0) sol++;
    }
    printf("%d\n", sol);
    return 0;
}