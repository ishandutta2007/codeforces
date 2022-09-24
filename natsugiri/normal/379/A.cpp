#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;


int main() {
    int A, B;
    scanf("%d%d", &A, &B);
    int ans = 0, c=0;

    while (A) {
	ans += A;
	c += A;
	A = c/B;
	c %= B;
    }

    printf("%d\n", ans);
    return 0;
}