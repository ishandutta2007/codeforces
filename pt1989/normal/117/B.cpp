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

void twoWin() {
    cout << 2 << endl; exit(0);
}
const int mxn = 10000007;
int vis[mxn];
bool ok[mxn];
int main(int argc, char** argv) {
	int a, b, mod;
    cin>>a>>b>>mod;
    fill(vis, -1); fill(ok, 1);
    //i*1e9 + j % m != 0
    //i*1000 % m != j % m
    
    for (int j=0; j <= b && j < mod; j++) {
        int i = j ? mod - j : 0;
        ok[i] = 0;
    }
    int r = 1000000000 % mod;
    int tmp = r;
    if (r)
    for (int x=1; x <= a; x++) {
        if (vis[tmp] != -1) break;
        vis[tmp] = x;
        tmp += r;
        if (tmp > mod) tmp -= mod;
    }
    int ret = 1000000002;
    bool hvSol = 0;
    for (int f=0; f < mod; f++)
    if (ok[f])
    if (vis[f] != -1) {
        ret = min(ret, vis[f]);
        hvSol = 1;
    }
    if (hvSol) {
        printf("%d %09d\n", 1, ret);
    } else {
        twoWin();
    }
	return 0;
}