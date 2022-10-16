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

int blok[M], n, bio[M], pref[M], lft[M], q, k;

int get(int l, int r){
    if(l <= 0) return pref[r];
    return pref[r] - pref[l - 1];
}

int check(int x){
    int sol = 0;
    for(int i = 0;i<n;i++){
        if(blok[i]){
            if(lft[i] <= i - x){
                return  -1;
            }
            else{
                i = lft[i] + x - 1;
                sol++;
            }
        }
        else{
            i += x - 1;
            sol++;
        }
    }
    return sol;
}

int main(){
    scanf("%d%d%d", &n, &q, &k);
    for(int i = 0;i<q;i++){
        int x;scanf("%d", &x);
        blok[x] = 1;
    }
    if(blok[0]) lft[0] = -INF;
    else lft[0] = 0;
    for(int i = 1;i<n;i++){
        if(!blok[i]) lft[i] = i;
        else lft[i] = lft[i - 1];
    }
    ll fin = (ll)INF * INF;
    for(int i = 1;i<=k;i++){
        int x;scanf("%d", &x);
        int y = check(i);
        if(y == -1) continue;
        fin = min(fin, (ll)x * y);
    }
    if(fin == (ll)INF * INF) printf("-1\n");
    else printf("%I64d\n", fin);
    return 0;
}