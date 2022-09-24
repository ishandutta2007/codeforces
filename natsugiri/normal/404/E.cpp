#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;

string S;

bool OK(int o=0) {
    int l, r, x;
    l = r = x = 0;
    for (int i=0; i<(int)S.size(); i++) {
	l = min(l, x);
	r = max(r, x);
	if (S[i] == 'L') x--;
	else x++;
	if (0<o) x = min(x, o-1);
	if (0>o) x = max(x, o+1);
    }

    return x < l || r < x; 
    
}


int main() {
    cin >> S;

    if (OK()) puts("1");
    else if (!OK(1) && !OK(-1)) puts("0");
    else {
	int lo = 1, hi = S.size() + 1;
	while (hi-lo > 1) {
	    int m = (hi + lo) / 2;
	    if (S[S.size()-1] == 'L') {
		if (OK(m)) lo = m;
		else hi = m;
	    } else {
		if (OK(-m)) lo = m;
		else hi = m;
	    }
	}
	printf("%d\n", lo);
    }
    return 0;
}