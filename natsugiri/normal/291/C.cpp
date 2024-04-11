#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
#include<set>
using namespace std;

typedef long long LL;
typedef unsigned int Uint;

Uint ip[100010];
int N, K;

int main() {
    scanf("%d%d", &N, &K);
    for (int i=0; i<N; i++) {
	Uint a,b,c,d; scanf("%u.%u.%u.%u", &a, &b, &c, &d);
	ip[i] = a*(1<<24) + b*(1<<16) + c*(1<<8) + d;
    }

    Uint mask=0;
    for (int i=32; --i; ) {
	mask|=1<<i;
	set<Uint>se;
	for (int j=0; j<N; j++) se.insert(ip[j]&mask);
	if (int(se.size())==K) {
	    printf("%u.%u.%u.%u\n", mask>>24, 255&(mask>>16), 255&(mask>>8), 255&mask);
	    return 0;
	}
    }
    puts("-1");
    return 0;
}