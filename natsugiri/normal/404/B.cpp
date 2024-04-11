#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
#include<cmath>
using namespace std;

typedef long long LL;

int main() {
    double A, D;
    int N;
    scanf("%lf%lf%d", &A, &D, &N);

    
    for (int i=1; i<=N; i++) {
	double R = D*i - floor(D*i / (4*A)) * 4*A;
	double x = 0, y = 0, z;
	z = min(A, R);
	x += z; R -= z;
	z = min(A, R);
	y += z; R -= z;
	z = min(A, R);
	x -= z; R -= z;
	z = min(A, R);
	y -= z; R -= z;

	printf("%.9f %.9f\n", x, y);
    }

    return 0;
}