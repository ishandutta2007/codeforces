#include<cstdio>
#include<cmath>
using namespace std;



const double RT2 = sqrt(2);

double tri(double n) { return n*(n+1.0)/2.0; }

double calc(int n) {
    double ret=0.0;
    if (n) ret += 2+RT2;
    if (n>1) ret += tri(n-1)*2.0 + 2.0*RT2*(n-1);
    return ret;
}

int M, R;

int main() {
    scanf("%d%d", &M, &R);
    double ans = 0, B = double(M)*M;
    for (int i=0; i<M; i++) {
	ans += 2.0 / B;
	ans += calc(i) / B;
	ans += calc(M-1-i) / B;
    }

    printf("%.9f\n", ans*R);
    
    return 0;
}