#include<cstdio>
const int dx[]={1,0,-1,0}, dy[]={0,1,0,-1};
int X[1010], Y[1010];

int main() {
    int x, y;
    scanf("%d%d", &x, &y);

    for (int i=0; i<1009; i++) {
	X[i+1] = X[i] + (i+2)/2 * dx[i%4];
	Y[i+1] = Y[i] + (i+2)/2 * dy[i%4];
    }
    for (int i=0; ; i++) {
	if ((x==X[i] && x==X[i+1]
	     && ((Y[i]<=y && y<=Y[i+1]) ||
		 (Y[i+1]<=y && y<=Y[i]))) ||
	    (y==Y[i] && y==Y[i+1]
	     && ((X[i]<=x && x<=X[i+1]) ||
		 (X[i+1]<=x && x<=X[i])))) {
	    printf("%d\n", i);
	    return 0;
	}
    }
    return 0;
}