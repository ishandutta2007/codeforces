#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;

int N, A[100010];

int main() {
    scanf("%d", &N);
    for (int i=0; i<N; i++) scanf("%d", A+i);

    for (int i=32; i--;) {
	vector<int>B;
	int M=-1;
	for (int j=0; j<N; j++) {
	    if (A[j] & (1<<i)) {
		M &= A[j];
		B.push_back(A[j]);
	    }
	}
	if (M & ((1<<i)-1)) continue;

	printf("%d\n", B.size());
	for (int j=0; j<int(B.size()); j++) {
	    printf("%d\n", B[j]);
	}
	return 0;	    
    }
    puts("0");
    return 0;
}