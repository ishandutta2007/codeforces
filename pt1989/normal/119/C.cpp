#include<vector>
#include<stack>
#include<set>
#include<map>
#include<queue>
#include<deque>
#include<bitset>
#include<complex>
 
#include<sstream>
#include<fstream>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<climits>
 
#define oo            (int)13e7
#define s(n)          scanf("%d",&n)
#define sl(n)         scanf("%lld",&n)
#define sf(n)         scanf("%lf",&n)
#define fill(a,v)     memset(a, v, sizeof a)
#define ull           unsigned long long
#define ll            long long
#define bitcount      __builtin_popcount
#define all(x)        x.begin(), x.end()
#define pb( z )       push_back( z )
#define gcd           __gcd
using namespace std;

int n, m, k;

const int mxm = 55;
struct subject {
    ll lo, hi; int c, id;
    void read(int _i) { id = _i; cin>>lo>>hi>>c; }
    bool operator < (const subject &s) const {
        return c < s.c;
    }
};
subject a[mxm];
ll dp[mxm][mxm][111];
ll solve(int pos, int off, int dep) {
    ll previousValue = a[pos].lo + off;
    if (dep == 1) return previousValue;
    ll &ret = dp[pos][dep][off];
    if (~ret) return ret;
    
    ret = -4000000000000000000LL;
    for (int nxt=pos+1; nxt < m; nxt++)
        if (a[nxt].c > a[pos].c) {
            for (int mode=0; mode < 2; mode++) {
                ll newValue = previousValue;
                if (mode) newValue += k; else newValue *= k;
                if (a[nxt].lo <= newValue && newValue <= a[nxt].hi) {
                    ret = max(ret, previousValue + solve(nxt, newValue - a[nxt].lo, dep-1));
                }
            }
        }
    return ret;
}

void recon(int pos, int off, int dep) {
    
    ll previousValue = a[pos].lo + off;
    ll ret = solve(pos, off, dep);
    cout << a[pos].id << " " << (a[pos].lo + off) << endl;
    if (dep == 1) return;
    for (int nxt=pos+1; nxt < m; nxt++)
        if (a[nxt].c > a[pos].c) {
            for (int mode=0; mode < 2; mode++) {
                ll newValue = previousValue;
                if (mode) newValue += k; else newValue *= k;
                if (a[nxt].lo <= newValue && newValue <= a[nxt].hi) {
                    ll nret = (previousValue + solve(nxt, newValue - a[nxt].lo, dep-1));
                    if (nret == ret) {
                        return recon(nxt, newValue - a[nxt].lo, dep-1);
                    }
                }
            }
        }
    
}

int main(int argc, char** argv) {
	cin>>n>>m>>k;
    for (int i=0; i < m; i++) {
        a[i].read(i+1);
    }
    sort(a, a+m);
    fill(dp, -1);
    
    ll bestExercises = -1;
    int bestPos, bestOff;
    for (int pos=m-1; pos >= 0; pos--) {
        for (int off=a[pos].hi - a[pos].lo; off >= 0 ; off--) {
            ll exercises = solve(pos, off, n);
            if (exercises > 0) {
                if (exercises > bestExercises) {
                    bestExercises = exercises;
                    bestPos = pos;
                    bestOff = off;
                }
            }
        }
    }
    if (bestExercises > 0) {
        cout << "YES" << endl;
        recon(bestPos, bestOff, n);
    } else {
        cout << "NO" << endl;
    }
    
	return 0;
}