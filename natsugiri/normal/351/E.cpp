#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;

int N, A[2010], G[2010], B[2010];
int main() {
    scanf("%d", &N);
    for (int i=0; i<N; i++) scanf("%d", A+i);

    for (bool loop=true; loop;) {
	loop = false;
	for (int i=0; i<N; i++) {
	    int cur=0, next=0;
	    for (int j=0; j<i; j++) {
		if (A[j] > A[i]) cur++;
		if (A[j] > -A[i]) next++;
	    }
	    for (int j=i+1; j<N; j++) {
		if (A[i] > A[j]) cur++;
		if (-A[i] > A[j]) next++;
	    }
	    if (next < cur) {
		A[i] = -A[i];
		loop = true;
	    }
	}
    }


    int cnt = 0;
    for (int i=0; i<N; i++) {
	for (int j=i+1; j<N; j++) {
	    if (A[i] > A[j]) {
		cnt++;
	    }
	}
    }
    printf("%d\n", cnt);
    return 0;
}