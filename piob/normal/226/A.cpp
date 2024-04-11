#include <cstdlib>
#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <deque>
#include <cstring>
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define REP(a,c) for(int a=0; a<(c); ++a)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define FE(a,b) for(__typeof((b).end()) a=(b).begin(); a!=(b).end(); ++a)
#define PII pair<int, int>
#define x first
#define y second
#define pb push_back

using namespace std;

inline long long pot(long long a, long long b, long long c){
    if(b == 0LL) return 1LL;
    long long d = pot(a, b/2, c);
    d = (d*d)%c;
    if(b&1LL) d = (d*a)%c;
    return d;
}

long long n, m;

int main(){
    cin >> n >> m;
    cout << ((pot(3LL,n,m)+m-1)%m) << endl;
    return 0;
}