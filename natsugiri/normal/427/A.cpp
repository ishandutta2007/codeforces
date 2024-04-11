#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;


int main() {
    int N, S = 0, X, ans = 0;
    scanf("%d", &N);
    for (;N--;) {
	scanf("%d", &X);
	if (S == 0 && X == -1) ans++;
	S = max(0, S+X);
    }
    printf("%d", ans);
    return 0;
}