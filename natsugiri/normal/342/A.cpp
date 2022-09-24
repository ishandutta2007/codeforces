#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;

int N, C[10], X[3];
int main() {
    scanf("%d", &N);
    for (int i=0; i<N; i++) {
	int x;
	scanf("%d", &x);
	C[x]++;
    }

    bool bad=false;
    if (C[5] | C[7]) bad = true;

    int g;
    g = min(C[1], min(C[2], C[4]));
    C[1] -= g; C[2] -= g; C[4] -= g; X[0] += g;

    g = min(C[1], min(C[2], C[6]));
    C[1] -= g; C[2] -= g; C[6] -= g; X[1] += g;

    g = min(C[1], min(C[3], C[6]));
    C[1] -= g; C[3] -= g; C[6] -= g; X[2] += g;

    for (int i=0; i<8; i++) if (C[i]) bad = true;

    if (bad) puts("-1");
    else {
	for (;X[0]--;) puts("1 2 4");
	for (;X[1]--;) puts("1 2 6");
	for (;X[2]--;) puts("1 3 6");
    }
    return 0;
}