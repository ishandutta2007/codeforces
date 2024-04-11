#include <cstdio>

using namespace std;

int n;

int ask(int l, int r){
	if(l == r) return -1;
	printf("? %d %d\n", l, r);
	fflush(stdout);
	int ret; scanf("%d", &ret);
	return ret;
}

int main(){
	scanf("%d", &n);
	int dr = ask(1, n);
	int lo = 0;
	if(dr != 1 && ask(1, dr) == dr){
		int lo = n + 1;	
		for(int i = 18;i >= 0;i--){
			if(lo - (1 << i) >= 1 && ask(lo - (1 << i), n) != dr)
				lo -= (1 << i);
		}
		printf("! %d\n", lo - 1);
	}
	else{
		for(int i = 18;i >= 0;i--){
			if(lo + (1 << i) <= n && ask(1, lo + (1 << i)) != dr)
				lo += (1 << i);
		}
		printf("! %d\n", lo + 1);
	}
	fflush(stdout);
	return 0;
}