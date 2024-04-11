#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;

bool dp[1010][11][11];

int main() {
    char S[20];
    int M;
    scanf("%s%d", S+1, &M);

    for (int i=1; i<=10; i++) {
	if (S[i]=='1') dp[1][i][i] = true;
    }
    for (int t=1; t<M; t++) {
	for (int i=1; i<=10; i++) {
	    if (S[i]=='1') {
		for (int j=1; j<i; j++) { // diff
		    for (int k=1; k<=10; k++) {
			if (k==i) continue;
			if(dp[t][k][j]) dp[t+1][i][i-j] = true;
		    }
		}
	    }
	}
    }

    int p = 0, q = 0;
    for (int i=1; i<=10; i++) {
	for (int j=1; j<=10; j++) {
	    if (dp[M][i][j]) {
		p = i; q = j;
		break;
	    }
	}
    }

    if (p==0 && q==0) {
	puts("NO");
    } else {
	vector<int>v;
	for (int t=M; t--;) {
	    v.push_back(p);
	    for (int i=1; i<=10; i++) {
		if (i==p) continue;
		if (dp[t][i][p-q]) {
		    q = p-q;
		    p = i;
		    break;
		}
	    }
	}
	puts("YES");
	for (int t=M; t--;) printf("%d%c", v[t], t ? ' ' : '\n');
    }
    
    

    return 0;
}