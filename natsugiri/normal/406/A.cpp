#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;

int N, P;
int main() {
    scanf("%d", &N);
    for (int i=0; i<N; i++) {
	for (int j=0; j<N; j++) {
	    int x;
	    scanf("%d", &x);
	    if (i==j) P += x;
	}
    }

    P %= 2;

    int Q;
    scanf("%d", &Q);
    for (; Q--;) {
	int T;
	scanf("%d", &T);
	if (T==1 || T==2) {
	    int x;
	    scanf("%d", &x);
	    P = (P+1)%2;
	} else {
	    putchar('0' + P);
	}
    }
    putchar('\n');


    return 0;
}