#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <map>

#define X first
#define Y second
#define PB push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair < int, int> pii;
typedef pair < ll, ll> pll;
typedef vector < int > vi;

const int N = 1e5 + 500;
const int M = 1e6 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int BASE = 31337;
const ld EPS = 1e-9;
const ld PI = 3.1415926535;

int a[N], b[N],n;

void get(int x){
    if(a[x] != INF) return;
    printf("? %d\n", x);
    fflush(stdout);
    int y;scanf("%d", &y);
    a[x] = y;
}

void ask(int x){
    get(x);
    get((x + n / 2 - 1) % n + 1);
    b[x] = a[(x + n / 2 - 1) % n + 1] - a[x];
}



int binary(int lo, int hi){
    //printf("{%d %d}\n", lo, hi);
    int mid = (lo + hi) / 2;
    ask(mid);
    if(b[lo] > 0 && b[hi] > 0){
        while(b[mid] > 0) mid = rand() % (hi - lo + 1) + lo, ask(mid);
    }
    if(b[lo] < 0 && b[hi] < 0){
        while(b[mid] < 0) mid = rand() % (hi - lo + 1) + lo, ask(mid);
    }
    if(b[mid] == 0) return mid;
    if((b[lo] > 0 && b[mid] < 0) || (b[mid] > 0 && b[lo] < 0))
        return binary(lo, mid);
    return binary(mid, hi);
}

int main(){
    memset(a, INF, sizeof(a));
    scanf("%d", &n);
    ask(1);ask(n);
    if(n % 4 != 0) printf("! -1\n");
    else if(!b[1]) printf("! 1\n");
    else if(!b[n]) printf("! %d\n", n);
    else printf("! %d\n", binary(1, n));
    fflush(stdout);
}