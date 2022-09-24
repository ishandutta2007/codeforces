#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;

const char dir[] = "RDLU";
const int dx[] = { 1, 0, -1, 0};
const int dy[] = { 0, 1, 0, -1};


int N, M, K;
char S[2333];
int ans[2333];

void update(int r, int c, int dr, int dc) {
    if (dr == 1) {
	;
    } else if (dr == -1) {
	if (r % 2 == 0) ans[c]++;
    } else {
	c += r*dc;
	if (0<=c && c<M) ans[c]++;
    }
}

int main() {
    scanf("%d%d%d", &N, &M, &K);
    for (int i=0; i<N; i++) {
	scanf("%s", S);
	for (int j=0; j<M; j++) {
	    for (int d=0; d<4; d++) {
		if (dir[d] == S[j]) {
		    update(i, j, dy[d], dx[d]);
		}
	    }
	    
	}
    }
	    

    for (int i=0; i<M; i++) printf("%d%c", ans[i], i==M-1 ? '\n' : ' ');

    return 0;
}