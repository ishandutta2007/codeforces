#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;
typedef vector<int> VI;

int H;
LL K;
LL ans;
bool rec(LL l, LL r, bool left) {
    if (K < l || r <= K) {
	ans += (r-l)*2-1; // subtree
	return false;
    } else {
	ans++; // current node
    }
    
    if (r-l==1) return l == K;

    
    LL m = (l+r)/2;
    if (left) {
	rec(l, m, false) || rec(m, r, true);
    } else {
	rec(m, r, true) || rec(l, m, false);
    }
    return true;
}

int main() {
    scanf("%d%lld", &H, &K);
    K--;
    rec(0, 1LL<<H, true);
    printf("%lld\n", ans-1);
    return 0;
}