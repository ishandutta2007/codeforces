#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;

string S;
int in=0, p;

void out(int l, int r) {
    printf("<%s>\n", S.substr(l, r-l).c_str());
}

int main() {
    getline(cin, S);
    for (int i=0; i<=int(S.size()); i++) {
	if (S[i]=='"') {
	    if (in) {
		out(p, i);
		p=i+1;
		in = 0;
	    } else {
		if (i>p) {
		    out(p, i);
		}
		p=i+1;
		in = 1;
	    }
	} else if (S[i]==' ' || S[i]=='\0') {
	    if (!in) {
		if (i>p) out(p, i);
		p=i+1;
	    }
	}
    }
    return 0;
}