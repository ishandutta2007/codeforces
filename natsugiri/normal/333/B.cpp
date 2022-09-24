#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;

int N, M;
bool row[1010], col[1010];


int main() {
    scanf("%d%d", &N, &M);

    for (int i=0; i<M; i++) {
	int x, y;
	scanf("%d%d", &x, &y);
	x--; y--;
	row[y]=col[x]=1;
    }

    int ans=0;
    for (int i=1; i*2<N-1; i++) {
	// row[i], col[i], row[N-1-i], col[N-1-i]
	int tmp=0;

	for (int r1=-1; r1<2; r1++) {
	    if (r1 && row[i]) continue;
	    
	    for (int c1=-1; c1<2; c1++) {
		if (c1 && col[i]) continue;
		if (c1 && r1==c1) continue;
		
		
		for (int r2=-1; r2<2; r2++) {
		    if (r2 && row[N-1-i]) continue;
		    if (r2 && r2==-c1) continue;

		    for (int c2=-1; c2<2; c2++) {
			if (c2 && col[N-1-i]) continue;
			if (c2 && c2==-r1) continue;
			if (c2 && c2==r2) continue;
			tmp = max(tmp, abs(r1) + abs(r2) + abs(c1) + abs(c2));
		    }}}}
	//printf("%d %d\n", i, tmp);
	ans += tmp;
    }

    if (N%2==1 && (!row[N/2] || !col[N/2])) ans++;

    printf("%d\n", ans);
    return 0;
}