#include<cstdio>
#include<algorithm>
using namespace std;

int gcd(int a, int b) { return b?gcd(b, a%b):a; }
int n, m, x, y, a, b;
int main() {
    scanf("%d%d%d%d%d%d", &n, &m, &x, &y, &a, &b);
    int g=gcd(a, b); a/=g; b/=g;
    int k=min(n/a, m/b), A=a*k, B=b*k;
    int X=0, Y=0;
    int d;
    d=n-A;
    if (X+A/2+d<x) X+=d;
    else if (X+A/2<x) X=x-(A+1)/2;

    d=m-B;
    if (Y+B/2+d<y) Y+=d;
    else if (Y+B/2<y) Y=y-(B+1)/2;
    
    printf("%d %d %d %d\n", X, Y, X+A, Y+B);
    return 0;
}