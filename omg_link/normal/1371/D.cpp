#include <stdio.h>
#include <string.h>
#define MN 300

int n,k;

bool b[MN+5][MN+5];

int nxt(int x){
	x++;
	if(x == n){
		x = 0;
	}
	if(x > n){
		throw "......";
	}
	return x;
}

void solve(){
	scanf("%d%d",&n,&k);
	memset(b,0,sizeof(b));
	int x=0,y=0;
	while(k--){
		b[x][y] = true;
		x = nxt(x);
		y = nxt(y);
		if(b[x][y]){
			x = nxt(x);
		}
	}
	if(y == 0){
		puts("0");
	}else{
		puts("2");
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(b[i][j]) putchar('1');
			else putchar('0');
		}
		putchar('\n');
	}
}

int main(){
	int T; scanf("%d",&T);
	while(T--) solve();
}