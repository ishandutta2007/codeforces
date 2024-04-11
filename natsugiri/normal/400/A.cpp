#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;


int main() {
    int T;
    string S;
    scanf("%d", &T);
    for (;T--;) {
	cin >> S;
	vector<int>ans;
	for (int i=1; i<=12; i++) {
	    if (12%i) continue;
	    int x = 12/i;
	    bool f = false;
	    for (int j=0; j<x; j++) {
		int k;
		for (k=0; k<i; k++) if (S[k*x+j] == 'O') break;
		if (k==i) f = true;
	    }
	    if (f) ans.push_back(i);
	}

	printf("%d", ans.size());
	for (int i=0; i<(int)ans.size(); i++) {
	    printf(" %dx%d", ans[i], 12/ans[i]);
	}
	putchar('\n');
    }

    return 0;
}