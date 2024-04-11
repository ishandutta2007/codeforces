#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;

string S;
int M;
int N;
int sums[100010][3];

int get(int L, int R, char c) {
    return sums[R][c-'x'] - sums[L][c-'x'];
}

int main() {
    cin >> S >> M;
    N = S.size();

    S += "_____";


    for (int i=0; i<N; i++) {
	for (int j=0; j<3; j++) sums[i+1][j] += sums[i][j];
	sums[i+1][S[i]-'x']++;

    }

    for (; M--;) {
	int L, R; scanf("%d%d", &L, &R); L--;

	bool yes = true;
	int g[]= {get(L, R, 'x'), get(L, R, 'y'), get(L, R, 'z')};

	for (int i=0; i<3; i++) {
	    for (int j=0; j<3; j++) {
		if (abs(g[i]-g[j]) > 1) yes = false;
	    }
	}


	if (R-L<3) yes = true;

	puts(yes ? "YES" : "NO");
    }
   

    return 0;
}