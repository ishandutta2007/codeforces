#include <cstdlib>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define FE(a,b) for(typeof((b).end()) a=(b).begin(); a!=(b).end(); ++a)

using namespace std;

inline int gcd(int a, int b){
    while(a&&b) a>b?a%=b:b%=a;
    return a+b;
}

inline int scm(int a, int b){
    return a*b/gcd(a,b);
}

inline int scm(int a, int b, int c){
    return scm(scm(a, b), c);
}

inline int scm(int a, int b, int c, int d){
    return scm(scm(a,b), scm(c,d));
}

int main(){
    int a, b, c, d, n;
    scanf("%d %d %d %d %d", &a, &b, &c, &d, &n);
    printf("%d", n/a + n/b + n/c + n/d - n/scm(a,b) - n/scm(a,c) - n/scm(a,d) - n/scm(b,c) - n/scm(b,d) - n/scm(c,d) + n/scm(a,b,c) + n/scm(a,b,d) + n/scm(a,c,d) + n/scm(b,c,d) - n/scm(a,b,c,d));
}