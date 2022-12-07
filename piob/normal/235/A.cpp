#include <cstdlib>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define FE(a,b) for(typeof((b).end()) a=(b).begin(); a!=(b).end(); ++a)

using namespace std;


typedef long long LL;

LL gcd(LL a, LL b){
    while(a&&b) a>b?a%=b:b%=a;
    return a+b;
}

LL lcm(LL a, LL b, LL c){
    b = b*c/gcd(b,c);
    return a*b/gcd(a,b);
}

LL n, a, b, c, r;

int main(){
/*#ifdef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif*/
    cin >> n;
    c = n;
    b = n-1;
    a = n;
    r = max(n, (n-1)*(n-2)*(n-3));
    while(--a){
        r = max(r, lcm(a,b,c));
    };
    cout << r << endl;
    return 0;
}