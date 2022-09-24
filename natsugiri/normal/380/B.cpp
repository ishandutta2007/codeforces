#include<set>
#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;

int clz(LL x) {
    if (x==0) return 64;
    int n=0;
    if ((x & 0xFFFFFFFF00000000LL) == 0) n|=32, x<<=32;
    if ((x & 0xFFFF000000000000LL) == 0) n|=16, x<<=16;
    if ((x & 0xFF00000000000000LL) == 0) n|=8, x<<=8;
    if ((x & 0xF000000000000000LL) == 0) n|=4, x<<=4;
    if ((x & 0xC000000000000000LL) == 0) n|=2, x<<=2;
    if ((x & 0x8000000000000000LL) == 0) n|=1;
    return n;
}

int next(int n) {
    return 64-clz(n);
}
	

vector<vector<int> > val, le, ri;
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    
    val = le = ri = vector<vector<int> >(n+1);
    for (; m--;) {
	int g;
	scanf("%d", &g);
	if (g==1) {
	    int t, l, r, x;
	    scanf("%d%d%d%d", &t, &l, &r, &x);
	    val[t].push_back(x);
	    le[t].push_back(l);
	    ri[t].push_back(r);
	} else {
	    int t, v;
	    scanf("%d%d", &t, &v);
	    int l=v, r=v;
	    set<int>se;
	    for (; t<=n; t++) {
		for (int i=0; i<(int)val[t].size(); i++) {
		    if (l <= ri[t][i]  && le[t][i] <= r) se.insert(val[t][i]);
		}
		
		l += next(l-1);
		r += next(r);
	    }
	    printf("%d\n", se.size());
	}
    }
	
    return 0;
}