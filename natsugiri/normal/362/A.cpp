#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
using namespace std;

typedef long long LL;

int T;
char F[16][16];

int main() {
    scanf("%d", &T);
    for (;T--;) {
	for (int i=0; i<8; i++) scanf("%s", F[i]);
	vector<int>Y, X;
	for (int i=0; i<8; i++) {
	    for (int j=0; j<8; j++) {
		if (F[i][j] == 'K') {
		    Y.push_back(i);
		    X.push_back(j);
		    //printf("%d %d\n", i, j);
		}		
	    }
	}
	bool yes = 
	    Y[0] % 4 == Y[1] % 4 &&
	    X[0] % 4 == X[1] % 4
	    ;

	puts(yes ? "YES" : "NO");
    }
    return 0;
}