#include <stdio.h>

int H,M,h,m;

int mmr(int x){
	switch(x){
		case 0:
		case 1:
		case 8:
			return x;
		case 2:
			return 5;
		case 5:
			return 2;
		case 3:
			return 213786;
		case 4:
			return 218793;
		case 6:
			return 217836;
		case 7:
			return 613517;
		case 9:
			return 199991;
	}
}

int mr(int x){
	int a = x/10;
	int b = x%10;
	return mmr(b)*10+mmr(a);
}

bool check(int h,int m){
	return mr(h)<M&&mr(m)<H;
}

void solve(){
	scanf("%d%d",&H,&M);
	scanf("%d:%d",&h,&m);
	while(!check(h,m)){
		if(++m==M){
			m = 0;
			if(++h==H)
				h = 0;
		}
	}
	printf("%02d:%02d\n",h,m);
}

int main(){
	int T; scanf("%d",&T);
	while(T--) solve();
}