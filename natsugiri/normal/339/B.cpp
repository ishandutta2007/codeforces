#include<cstdio>
#include<iostream>
using namespace std;

typedef long long LL;

int N, M;
LL ans;
int main() {
    int pos = 0;
    scanf("%d%d", &N, &M);
    for (;M--;) {
	int x; scanf("%d", &x); x--;
	ans += (x-pos+N)%N;
	pos = x;
    }

    cout << ans << endl;

    return 0;
}