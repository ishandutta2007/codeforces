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

void solve(int n, ll x, int y) {
    if (n > y) {
        puts("-1");
        return;
    }
    vector<int> a( n );
    ll a2sum = 0;
    for (int i=0; i < n; i++) {
        a[i] = 1; y--;
    }
    a[n-1] += y;
    for (int i=0; i < n; i++) {
        a2sum += a[i]*(ll)a[i];
    }
    if (a2sum < x) {
        puts("-1");
        return;
    }
    for (int i=0; i < n; i++)
        printf("%d\n", a[i]);
}

int main(int argc, char** argv) {
	int n; ll x; int y;
    cin>>n>>x>>y;
    solve(n, x, y);
	return 0;
}