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

const int N = 1e5 + 500;
const int M = 1e6 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int LOG = 17;
const int OFF = (1 << LOG);
const double PI = 3.1415926535;
const double EPS = 1e-9;


int n;
int ty[N];
ll l[N], cur[N];

ll tour[2 * OFF], prop[2 * OFF], fl[N];

void refresh(int i){
    if(prop[i] == 0) return;
    tour[i] -= prop[i];
    if(i < OFF){
        prop[2 * i] += prop[i];
        prop[2 * i + 1] += prop[i];
    }
    prop[i] = 0;
}

void update(int i,int a,int b,int lo,int hi, ll x){
    refresh(i);
    if(lo <= a && b <= hi){
        prop[i] += x;
        refresh(i);
        return;
    }
    if(a > hi || b < lo) return;
    update(2 * i, a, (a + b) / 2, lo, hi, x);
    update(2 * i + 1, (a + b) / 2 + 1, b, lo, hi, x);
    tour[i] = min(tour[2 * i], tour[2 * i + 1]);
}

ll query(int i,int a,int b,int lo,int hi){
    refresh(i);
    if(lo <= a && b <= hi) return tour[i];
    if(a > hi || b < lo) return (ll)INF * INF;
    return min(query(2 * i, a, (a + b) / 2, lo, hi), query(2 * i + 1, (a + b) / 2 + 1, b, lo, hi));
}

int main(){
    scanf("%d", &n);
    for(int i = 0;i<n;i++){
        scanf("%lld", l + i);l[i] *= 2LL;
    }
    for(int i = 0;i<n;i++){
        char c;scanf(" %c", &c);
        if(c == 'W') ty[i] = 0;
        else if(c == 'G') ty[i] = 1;
        else ty[i] = 2;
    }
    int gt = 0;
    ll sol = 0, st = 0;
    for(int i = 0;i<n;i++){
        cur[i] = st;
        if(ty[i] == 0){
            gt = 1;
            sol += 3LL * l[i];
            st += l[i];
        }
        if(ty[i] == 1){
            sol += 5LL * l[i];
            st += l[i];
        }
        if(ty[i] == 2){
            sol += l[i];
            st -= l[i];
            if(st < 0){
                if(gt) sol += (-st) * 3LL;
                else sol += (-st) * 5LL;
                st = 0;
            }
        }
    }
    cur[n] = st;
    for(int i = 0;i<2*OFF;i++) tour[i] = (ll)INF * INF;
    for(int i = 0;i<=n;i++) tour[i + OFF] = cur[i];
    for(int i = OFF - 1; i ; i--) tour[i] = min(tour[2 * i], tour[2 * i + 1]);
    for(int i = 0;i<n;i++){
        if(ty[i] == 1){
            ll pos = query(1, 0, OFF - 1, i + 1, n) / 2LL;
            if(pos < l[i]){
                sol -= 4LL * pos;fl[i] = pos;
                update(1, 0, OFF - 1, i + 1, n, 2LL * pos);
            }
            else{
                sol -= 4LL * l[i];fl[i] = l[i];
                update(1, 0, OFF - 1, i + 1, n, 2LL * l[i]);
            }
        }
    }
    for(int i = 0;i<n;i++){
        if(ty[i] == 0){
            ll pos = query(1, 0, OFF - 1, i + 1, n) / 2LL;
            if(pos < l[i]){
                sol -= 2LL * pos;fl[i] = pos;
                update(1, 0, OFF - 1, i + 1, n, 2LL * pos);
            }
            else{
                sol -= 2LL * l[i];fl[i] = l[i];
                update(1, 0, OFF - 1, i + 1, n, 2LL * l[i]);
            }
        }
    }
    printf("%lld\n", sol / 2LL);
    gt = 0;
    for(int i = 0;i<n;i++){
        if(ty[i] == 0 && fl[i] != l[i]) gt = 1;
        if(ty[i] == 1 && gt){
            sol -= (l[i] - fl[i]);
        }
    }
    return 0;
}