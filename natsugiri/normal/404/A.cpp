#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;

int N;
char F[400][400];
int main() {
    scanf("%d", &N);
    for (int i=0; i<N; i++) scanf("%s", F[i]);

    bool YES = true;
    for (int i=0; i<N; i++) {
	for (int j=0; j<N; j++) {
	    if (i==j || i==N-1-j) {
		if (F[i][j] != F[0][0] || F[i][j] == F[0][1]) YES = false;
	    } else {
		if (F[i][j] != F[0][1] || F[i][j] == F[0][0]) YES = false;
	    }
	}
    }

    puts(YES ? "YES" : "NO");

    return 0;
}