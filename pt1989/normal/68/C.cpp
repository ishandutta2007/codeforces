//      hello world


//DS includes
#include<bitset>
#include<complex>
#include<deque>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<vector>

//Other Includes
#include<algorithm>
#include<cassert>
#include<climits>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<fstream>
#include<iostream>
#include<sstream>

#define oo          0xBADC0DE
#define s(n)            scanf("%d",&n)
#define sl(n)           scanf("%lld",&n)
#define sf(n)           scanf("%lf",&n)
#define fill(a,v)       memset(a, v, sizeof a)
#define ull             unsigned long long
#define ll              long long
#define bitcount        __builtin_popcount
#define all(x)          x.begin(), x.end()
#define pb( z )         push_back( z )
#define gcd             __gcd

#define FOR(i,n) for (int i=0; i < (n); i++)

using namespace std;

const int mxn = 8;
int a[mxn][mxn];
int lo[mxn][mxn];
int hi[mxn][mxn];
int flow[mxn][mxn];
int n;

int solve(int v, int child, int f) {
    //cout << v << " " << child << " " << f << endl;
    if (v==n) {
        int ret = 0;
        if (1) {
            for (int f=1; f <= n; f++)
            for (int t=f+1; t <= n; t++) {
                if (lo[f][t] <= flow[f][t] && flow[f][t] <= hi[f][t]) {
                } else {
                    return -1e9;
                }
                if (flow[f][t] > 0) {
                    ret += a[f][t];
                    ret += flow[f][t]*flow[f][t];
                } 
            }
        }
        return ret;
    }
    if (child == v) {
        int inflow = 0;
        for (int x=1; x < v; x++)
            inflow += flow[x][v];
        return solve(v, v+1, inflow);
    }
    if (child > n) {
        if (f != 0) return -1e9;
        return solve(v+1, v+1, 0);
    }   
    //give 0 flow to child
    int ret = INT_MIN;
    
    if (flow[v][child] >= lo[v][child])
        ret = max(ret, solve(v, child+1, f));
    if (f > 0 && flow[v][child] < hi[v][child]) {
        flow[v][child]++;
        ret = max(ret, solve(v, child, f-1));
        flow[v][child]--;
    }
    return ret;
}


int main(int argc, char** argv) {
    cin>>n;
    for (int i=0; i < n*(n-1)/2; i++) {
        int s,f,_l,_h,_a;
        cin>>s>>f>>_l>>_h>>_a;
        a[s][f] = _a;
        lo[s][f] = _l;
        hi[s][f] = _h;
    }
    
    for (int f=0; f <= 25; f++) {
        int ans = solve(1, 2, f);
        if (ans >= 0) {
            cout << f << " " << ans << endl;
            exit(0);
        } 
    }
    cout << -1 << " " << -1 << endl;
    
    return 0;
}