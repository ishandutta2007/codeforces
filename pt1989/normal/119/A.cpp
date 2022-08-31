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

int a, b, n;
bool win(int x, int p) {
    if (x==0) return 0;
    int fixed = p == 0 ? a : b;
    int z = gcd(fixed, x);
    return !win(x-z, p^1);
}

int main(int argc, char** argv) {
	cin>>a>>b>>n;
    puts( win(n, 0) ? "0" : "1" );
	return 0;
}